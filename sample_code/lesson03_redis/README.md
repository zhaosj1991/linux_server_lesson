# hiredis同步异步方案
hiredis自身提供了block和no block的方案。

**源码**

可以看到__redisBlockForReply会对context中的flag进行判断，如果是REDIS_BLOCK，则阻塞等待命令返回。如果不是，则直接返回NULL。

```
void *redisvCommand(redisContext *c, const char *format, va_list ap) {
    if (redisvAppendCommand(c,format,ap) != REDIS_OK)
        return NULL;
    return __redisBlockForReply(c);
}

static void *__redisBlockForReply(redisContext *c) {
    void *reply;

    if (c->flags & REDIS_BLOCK) {
        if (redisGetReply(c,&reply) != REDIS_OK)
            return NULL;
        return reply;
    }
    return NULL;
}
```

## 异步方案