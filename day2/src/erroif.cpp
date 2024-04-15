#include "erroif.h"
#include <cstdlib>
#include <iostream>

using namespace std;

//打印错误信息并退出
void erroif(bool erro_status, const char *erro_message)
{
    if (erro_status)
    {
        perror(erro_message);
        exit(EXIT_FAILURE);
    }
    
}
