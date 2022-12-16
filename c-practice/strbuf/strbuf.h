#include <stdlib.h>
#include <string.h>

struct strbuf
{
    int len;
    int alloc;
    char *buf;
};

void strbuf_init(struct strbuf *sb, size_t alloc)
{
    sb->len = 0;
    sb->alloc = alloc;
    sb->buf = (char *)malloc(sizeof(char) * alloc);
    *sb->buf = 0;
}

void strbuf_attach(struct strbuf *sb, void *str, size_t len, size_t alloc)
{
    strbuf_init(sb, alloc);
    sb->len = len;
    memcpy(sb->buf, str, len + 1);
}

void strbuf_release(struct strbuf *sb)
{
    free(sb->buf);
    free(sb);
}

void strbuf_swap(struct strbuf *a, struct strbuf *b)
{
    struct strbuf tmp = *a;
    *a = *b;
    *b = tmp;
}

char *strbuf_detach(struct strbuf *sb, size_t *sz)
{
    *sz = sb->alloc;
    return sb->buf;
}

int strbuf_cmp(const struct strbuf *first, const struct strbuf *second)
{
    return memcmp(first, second, sizeof first > sizeof second ? sizeof first : sizeof second);
}

void strbuf_reset(struct strbuf *sb)
{
    strbuf_init(sb, sb->alloc);
}

void strbuf_grow(struct strbuf *sb, size_t extra)
{
    if (sb->alloc - sb->len < extra)
        strbuf_attach(sb, sb->buf, sb->len, sb->len + extra);
}

void strbuf_add(struct strbuf *sb, const void *data, size_t len)
{
    strbuf_grow(sb, len);
    strcpy(sb->buf + sb->len, data);
}

void strbuf_addch(struct strbuf *sb, int c)
{
    strbuf_add(sb, &c, 1);
}

void strbuf_addstr(struct strbuf *sb, const char *s)
{
    strbuf_add(sb, s, strlen(s));
}

void strbuf_addbuf(struct strbuf *sb, const struct strbuf *sb2)
{
    strbuf_addstr(sb, sb2->buf);
}

void strbuf_setlen(struct strbuf *sb, size_t len)
{
    if (len < sb->alloc)
    {
        *(sb->buf + len) = 0;
        sb->len = len;
    }
    else
    {
        ;
    }
}
size_t strbuf_avail(const struct strbuf *sb)
{
    return sb->alloc - sb->len;
}
void strbuf_insert(struct strbuf *sb, size_t pos, const void *data, size_t len)
{
    memcpy(sb->buf + pos, data, sizeof(char) * (len + 1));
}