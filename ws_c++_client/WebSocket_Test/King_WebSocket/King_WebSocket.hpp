#pragma once
#include <string>
#include <thread>

#include "easywsclient/easywsclient.hpp"
using easywsclient::WebSocket;

#include "King_Queue.hpp"

class King_WebSocket {
    std::thread               runner;
    King_Queue< std::string > outgoing;
    King_Queue< std::string > incoming;
    std::atomic< bool >       running { true };

public:
    King_WebSocket();
    ~King_WebSocket();

    void run(const std::string& url);
    void close();

    void send(const std::string& s);
    bool recv(std::string& s);

    WebSocket::readyStateValues State;

public:
    static std::string GBKToUTF8(const std::string& strGBK);
    static std::string UTF8ToGBK(const std::string& strUTF8);
};

extern King_WebSocket* g_ws;