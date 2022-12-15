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
    memcpy(sb->buf, str, len);
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
    return memcmp(first, second, first->alloc > second->alloc ? first->alloc : second->alloc);
}
void strbuf_reset(struct strbuf *sb)
{
    strbuf_init(sb, sb->alloc);
}