#ifndef _ColoredIO_
#define _ColoredIO_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <conio.h>
#endif

void cPnt(char const* str, char const* param);
void cPntL(char const* str, char const* param);
void cPntH(char const* H1);
char pickchar();

void cPnt(char const* str, char const* param) {
    printf("\e[%sm%s\e[0m", param, str);
}

void cPntL(char const* str, char const* param) {
    cPnt(str, param);
    putchar('\n');
}

void cPntH(char const* H1) {
    cPntL("================================", "1;33");
    printf("%*s", 12, "");
    cPntL(H1, "1;33");
    cPntL("================================", "1;33");
}

void cPntOp(char const* op) {
    cPnt(op, "33");
}

void cPntErr(char const* err) {
    cPntL(err, "31");
}

char pickchar() {
    char ch = getchar();
    fflush(stdin);
    return ch;
}

// Windows 控制台密码不回显
void getpw(char* pw) {
#ifdef _WIN32
    char ch, i;
    while ((ch = getch()) != '\r') {
        if (ch != '\b') {
            putchar('*');
            pw[i++] = ch * 2 + i;
        } else if (i) {
            printf("\b \b");
            pw[i--] = '\0';
        }
    }
    pw[i + 1] = '\0';
    putchar('\n');
#endif
#ifndef _WIN32
    gets(pw);
#endif
}

#endif
