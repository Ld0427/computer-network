#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(int argc, char **argv)
{
    //创建服务器等待socket,等待客户端连接
    int wait_socket = socket(AF_INET, SOCK_STREAM, 0);

    //创建服务器ip地址及端口号
    sockaddr_in server_address;
    bzero(&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("192.168.0.113");
    server_address.sin_port = htons(8888);

    //将ip地址及端口号绑定到等待socket
    bind(wait_socket, (sockaddr*)&server_address, sizeof(server_address));

    //开始监听来自客户端的连接
    listen(wait_socket, SOMAXCONN);

    //创建客户端地址
    sockaddr_in client_address;
    bzero(&client_address, sizeof(client_address));
    socklen_t client_address_len = sizeof(client_address);

    //创建服务器连接socket,若没有客户端请求连接,则一直处于阻塞态
    int connect_socket = accept(wait_socket, (sockaddr*)&client_address, &client_address_len);

    //打印客户端请求的状态信息
    if (connect_socket == -1)
    {
        cout << "客户端请求连接失败\n";
    }
    else
    {
        cout << "客户端请求连接成功 connect_socket is: " << connect_socket << endl;
        cout << "客户端的ip is: " << inet_ntoa(client_address.sin_addr) << " port is: " << ntohs(client_address.sin_port) << endl;
    }
    
    return 0;
}