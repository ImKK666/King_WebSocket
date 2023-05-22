#include "King_WebSocket.hpp"

#include <WS2tcpip.h>

King_WebSocket::King_WebSocket() : State() {
}

King_WebSocket::~King_WebSocket() {
    if (runner.joinable()) {
        runner.join();
    }
}

void King_WebSocket::run(const std::string& url) {
    WSADATA wsaData;
    const INT     rc = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (rc) {
        printf("WSAStartup Failed.\n");
        MessageBoxA(nullptr, "WSAStartup Failed.", "King_WebSocket", 0);
        return;
    }

    runner = std::thread([=] {
        const std::unique_ptr< WebSocket > ws(WebSocket::from_url(url));
        while (true) {
            State = ws->getReadyState();
            if (State == WebSocket::CLOSED) {
                break;
            }
            std::string data;
            if (outgoing.pop(data)) {
                ws->send(GBKToUTF8(data));
            }
            ws->poll();
            ws->dispatch([&](const std::string& message) { incoming.push(message); });
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        ws->close();
        ws->poll();
        });
}
void King_WebSocket::close() {
    running = false;
    WSACleanup();
}

void King_WebSocket::send(const std::string& s) {
    outgoing.push(s);
}
bool King_WebSocket::recv(std::string& s) {
    return incoming.pop(s);
}

//===========================================================================//
std::string King_WebSocket::GBKToUTF8(const std::string& strGBK) {
    int    n = MultiByteToWideChar(CP_ACP, 0, strGBK.c_str(), -1, nullptr, 0);
    auto str1 = new WCHAR[n];
    MultiByteToWideChar(CP_ACP, 0, strGBK.c_str(), -1, str1, n);
    n = WideCharToMultiByte(CP_UTF8, 0, str1, -1, nullptr, 0, nullptr, nullptr);
    auto str2 = new char[n];
    WideCharToMultiByte(CP_UTF8, 0, str1, -1, str2, n, nullptr, nullptr);
    std::string strOutUTF8 = str2;
    delete[] str1;
    str1 = nullptr;
    delete[] str2;
    str2 = nullptr;
    return strOutUTF8;
}
std::string King_WebSocket::UTF8ToGBK(const std::string& strUTF8) {
    int      len = MultiByteToWideChar(CP_UTF8, 0, strUTF8.c_str(), -1, nullptr, 0);
    auto* wszGBK = new wchar_t[len + 1];
    memset(wszGBK, 0, len * 2 + 2);
    MultiByteToWideChar(CP_UTF8, 0, strUTF8.c_str(), -1, wszGBK, len);
    len = WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, nullptr, 0, nullptr, nullptr);
    const auto szGBK = new char[len + 1];
    memset(szGBK, 0, len + 1);
    WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, szGBK, len, nullptr, nullptr);
    std::string strTemp(szGBK);
    delete[] wszGBK;
    delete[] szGBK;
    return strTemp;
}