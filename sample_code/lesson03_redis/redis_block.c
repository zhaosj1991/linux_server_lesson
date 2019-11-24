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

    char *key = "str";
    char *val = "hello world";
    redisReply *reply = redisCommand(context, "set %s %s", key, val);
    if (reply->type == REDIS_REPLY_STATUS)
    {
        LOG("set success: set %s %s\n", key, val);
    }
    else
    {
        LOG("set fail: reply->type = %d\n", reply->type);
    }
    freeReplyObject(reply);

    reply = redisCommand(context, "strlen %s", key);
    if (reply->type == REDIS_REPLY_INTEGER)
    {
        LOG("strlen str : %lld\n", reply->integer);
    }
    freeReplyObject(reply);

    redisFree(context);

    return 0;
}