#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    //创建客户端socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);

    //创建需要连接的服务器地址及端口号
    sockaddr_in server_address;
    bzero(&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("192.168.0.113");
    server_address.sin_port = htons(8888);

    //连接服务器
    int connect_socket = connect(client_socket, (sockaddr*)&server_address, sizeof(server_address));
    
    //打印连接状态信息
    if (connect_socket == -1)
    {
        cout << "客户端请求连接服务器失败\n";
    }
    else
    {
        cout << "客户端请求连接服务器成功\n";
    }
    
    return 0;
}