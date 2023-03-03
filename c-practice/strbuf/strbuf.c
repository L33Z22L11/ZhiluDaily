// CC-BY-SA-4.0 L33Z22L11(纸鹿)
#include "strbuf.h"

void strbuf_init(struct strbuf *sb, size_t alloc) {
    sb->alloc = alloc;
    sb->buf = (char *) malloc(alloc);
    sb->buf[sb->len = 0] = '\0';
}

void strbuf_attach(struct strbuf *sb, void *str, size_t len, size_t alloc) {
    sb->len = len;
    sb->alloc = alloc;
    sb->buf = (char *) str;
}

void strbuf_release(struct strbuf *sb) {
    free(sb->buf);
    strbuf_attach(sb, NULL, 0, 0);
}

void strbuf_swap(struct strbuf *a, struct strbuf *b) {
    struct strbuf tmp = *a;
    *a = *b;
    *b = tmp;
}

char *strbuf_detach(struct strbuf *sb, size_t *sz) {
    *sz = sb->alloc;
    return sb->buf;
}

int strbuf_cmp(const struct strbuf *first, const struct strbuf *second) {
    return first->len - second->len || memcmp(first->buf, second->buf, first->len);
}

void strbuf_reset(struct strbuf *sb) {
    sb->buf[sb->len = 0] = '\0';
}

void strbuf_grow(struct strbuf *sb, size_t extra) {
    if (sb->alloc - sb->len < extra)
        sb->buf = (char *) realloc(sb->buf, sb->alloc += extra);
}

void strbuf_add(struct strbuf *sb, const void *data, size_t len) {
    strbuf_grow(sb, len + 1);
    memcpy(sb->buf + sb->len, data, len);
    sb->buf[sb->len += len] = '\0';
}

void strbuf_addch(struct strbuf *sb, int c) {
    strbuf_add(sb, &c, 1);
}

void strbuf_addstr(struct strbuf *sb, const char *s) {
    strbuf_add(sb, s, strlen(s));
}

void strbuf_addbuf(struct strbuf *sb, const struct strbuf *sb2) {
    strbuf_addstr(sb, sb2->buf);
}

void strbuf_setlen(struct strbuf *sb, size_t len) {
    if (len > sb->alloc) strbuf_grow(sb, len - sb->len + 1);
    sb->buf[sb->len = len] = '\0';
}

size_t strbuf_avail(const struct strbuf *sb) {
    return sb->alloc - sb->len - 1;
}

void strbuf_insert(struct strbuf *sb, size_t pos, const void *data, size_t len) {
    strbuf_setlen(sb, sb->len + len);
    memmove(sb->buf + pos + len, sb->buf + pos, sb->len - pos);
    memcpy(sb->buf + pos, data, len);
}

void strbuf_rtrim(struct strbuf *sb) {
    while (sb->buf[sb->len - 1] == ' ' || sb->buf[sb->len - 1] == '\t')
        sb->buf[--sb->len] = '\0';
}

void strbuf_ltrim(struct strbuf *sb) {
    int trimpos = 0;
    while (sb->buf[trimpos] == ' ' || sb->buf[trimpos] == '\t') trimpos++;
    memmove(sb->buf, sb->buf + trimpos, (sb->len -= trimpos) + 1);
}

void strbuf_remove(struct strbuf *sb, size_t pos, size_t len) {
    memmove(sb->buf + pos, sb->buf + pos + len, (sb->len -= len) - pos + 1);
}

ssize_t strbuf_read(struct strbuf *sb, int fd, size_t hint) {
    strbuf_grow(sb, hint ? hint : 8192);
    FILE *fp = fdopen(fd, "r");
    for (char ch; (ch = fgetc(fp)) != EOF;) strbuf_addch(sb, ch);
    return sb->len;
}

int strbuf_getline(struct strbuf *sb, FILE *fp) {
    for (char ch; (ch = fgetc(fp)) != '\n' && ch != EOF;) strbuf_addch(sb, ch);
    return sb->len;
}

struct strbuf **strbuf_split_buf(const char *str, size_t len, int terminator, int max) {
    struct strbuf **ret = (struct strbuf **) malloc(sizeof(struct strbuf *) * (max + 1));
    for (int pos = 0, flag = 0, n = 0; pos <= len && n < max; pos++) {
        while (str[flag] == terminator) pos = flag++ + 2;
        if (pos == len || pos > flag && str[pos] == terminator) {
            ret[n] = (struct strbuf *) malloc(sizeof(struct strbuf));
            strbuf_init(ret[n], 0);
            strbuf_add(ret[n], str + flag, pos - flag);
            // printf("[%d]: %s (%d~%d, %d)\n", n, ret[n]->buf, flag, pos, pos - flag);
            while (str[pos] == terminator) flag = pos++;
            ret[++n] = NULL;
        }
    }
    return ret;
}

bool strbuf_begin_judge(char *target_str, const char *str, int strnlen) {
    return str == NULL || !strncmp(target_str, str, strlen(str));
}

char *strbuf_get_mid_buf(char *target_buf, int begin, int end, int len) {
    if (begin > end || end >= len) return NULL;
    char *str = (char *) malloc(end - begin + 1);
    memcpy(str, target_buf + begin, end - begin);
    str[end - begin] = '\0';
    return str;
}