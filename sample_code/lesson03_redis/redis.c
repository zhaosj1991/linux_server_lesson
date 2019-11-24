#include <hiredis/hiredis.h>
#include <stdio.h>
#include <stdlib.h>

#define LOG printf

int main()
{
    redisContext *context = redisConnect("127.0.0.1", 6379);
    if (NULL == context || context->err)
    {
        if (context)
        {
            LOG("%s\n", context->errstr);
        }
        else
        {
            LOG("redisConnect error\n");
        }
        exit(-1);
    }

    LOG("Connect success!\n");

    redisFree(context);

    return 0;
}