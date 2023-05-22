use ws::listen;

fn main() {
    println!("Test WebSocket Server");

    if let Err(error) = listen("0.0.0.0:7068", |out| {
        // 处理程序需要获取out的所有权，因此我们使用move
        move |msg| {
            // 处理在此连接上接收的消息
            println!("\n服务器收到消息 '{}'\n", msg);

            // 使用输出通道发送消息
            out.send(msg)
        }
    }) {
        // 通知用户故障
        println!("创建Websocket失败，原因： {:?}", error);
    }
}
