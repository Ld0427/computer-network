#include <sys/socket.h>
#include <arpa/inet.h>
#include "erroif.h"
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <unistd.h>
using namespace std;

int main(int argc, char **argv)
{
    // 创建服务器等待socket
    int wait_socket = socket(AF_INET, SOCK_STREAM, 0);
    erroif(wait_socket == -1, "wait_socket create error");

    // 创建服务器ip地址及端口号
    sockaddr_in server_address;
    bzero(&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("192.168.0.113");
    server_address.sin_port = htons(8888);

    // 将ip地址及端口号绑定到等待socket上
    int bind_sock = bind(wait_socket, (sockaddr *)&server_address, sizeof(server_address));
    erroif(bind_sock == -1, "wait_socke bind erro");

    // 监听来自客户端的请求连接
    int listen_sock = listen(wait_socket, SOMAXCONN);
    erroif(listen_sock == -1, "wait_socket listen error");

    // 创建客户端地址
    sockaddr_in client_address;
    bzero(&client_address, sizeof(client_address));
    socklen_t client_address_len = sizeof(client_address);

    // 创建服务器连接socket
    int connect_socket = accept(wait_socket, (sockaddr *)&client_address, &client_address_len);
    erroif(connect_socket == -1, "client connect error");

    // 打印客户端的状态信息
    printf("client request connect sucess connect_socket is: %d\n", connect_socket);
    printf("client request connect ip is: %s  port is: %d\n",
           inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

    while (true)
    {
        // 分配内存,用来存客户端发送来的数据
        char buf[1024];
        bzero(&buf, sizeof(buf));

        // 读取客户端发送的数据,并将读入的数据反馈给客户端
        ssize_t read_bytes = read(connect_socket, buf, sizeof(buf));

        if (read_bytes == -1)
        {
            close(connect_socket);
            erroif(true, "connect_socket read error");
        }
        else if (read_bytes > 0)
        {
            printf("new message is from %s  content is: %s\n", inet_ntoa(client_address.sin_addr), buf);
            write(connect_socket, buf, sizeof(buf));
        }
        else if (read_bytes == 0)
        {
            // 若客户端不再发送数据,则服务器主动与客户端的连接断开
            printf("detect no message from client,  disconect with client\n");
            close(connect_socket);
            break;
        }
    }

    return 0;
}