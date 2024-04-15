#include <sys/socket.h>
#include <arpa/inet.h>
#include "erroif.h"
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    // 创建客户端连接socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    erroif(client_socket == -1, "client_socket create error");

    // 创建连接的服务器地址及端口号
    sockaddr_in server_address;
    bzero(&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("192.168.0.113");
    server_address.sin_port = htons(8888);

    //连接服务器
    int connect_socket = connect(client_socket, (sockaddr*)&server_address, sizeof(server_address));
    erroif(connect_socket == -1, "server connect error");

    while (true)
    {
        // 分配内存,存储发送给服务器的信息
        char buf[1024];
        bzero(&buf, sizeof(buf));

        //从键盘上进行读取
        printf("please input the message the send to serve,enter q or ctrl c quit./s\n");
        cin.getline(buf, 1024);

        //已经写入的信息
        ssize_t write_bytes = write(client_socket, buf, sizeof(buf));
        if (write_bytes == -1)
        {
            printf("server already disconnect, can't write\n");
            close(client_socket);
            break;
        }

        bzero(&buf, sizeof(buf));
        ssize_t read_bytes = read(client_socket, buf, sizeof(buf));

        if (read_bytes == -1)
        {
            close(client_socket);
            erroif(true, "socket read error");
        }
        else if (read_bytes > 0)
        {
            printf("message is from server and content is: %s\n", buf);
        }
        else if (read_bytes == 0)
        {
            close(client_socket);
            printf("already no message from server,disconnect with server\n");
        }     
        
    }
    

    return 0;
}