#ifndef _LoginUtils_
#define _LoginUtils_

#include "ColoredIO.h"
#define GenAuthPath(name)               \
    char authpath[80] = "./data/auth/"; \
    strcat(authpath, name);

void login(int* state);
int signIn();
void signUp();
void changePw();
void cancelAc();

void login(int* state) {
    cPntL("================================", "1;33");
    cPntL("   共享充电宝租借记录管理系统   ", "1;33");
    cPntL("     XUPT C语言大一课程设计     ", "1;33");
    cPntL("================================", "1;33");
    puts("     1. 登录                    ");
    puts("     2. 注册                    ");
    puts("     3. 修改密码                ");
    puts("     4. 注销账号                ");
    puts("     0. 退出                    ");
    puts("================================");
    cPntOp("请选择：");
    switch (pickchar()) {
        case '1':
            *state = signIn();
            break;
        case '2':
            signUp();
            break;
        case '3':
            changePw();
            break;
        case '4':
            cancelAc();
            break;
        case '0':
            *state = 0;
            break;
        default:
            cPntErr("未知选项，请重试。");
    }
}

int signIn() {
    cPntH("  登录");
    cPntOp("用户名：");
    char name[64];
    gets(name);
    FILE* fp;
    GenAuthPath(name);
    if ((fp = fopen(authpath, "r")) == NULL) {
        cPntErr("用户不存在，请重试。");
        fclose(fp);
        return -1;
    }
    cPntOp("密码：");
    char pw[64], realPw[64];
    getpw(pw);
    fgets(realPw, 64, fp);
    fclose(fp);
    if (strcmp(pw, realPw)) {
        cPntErr("密码错误，请重试。");
        return -1;
    }
    return 1;
}

void signUp() {
    cPntH("  注册");
    cPntOp("用户名：");
    char name[64];
    gets(name);
    FILE* fp;
    GenAuthPath(name);
    if ((fp = fopen(authpath, "r")) != NULL || !name[0]) {
        cPntErr("用户名重复，请重试。");
        fclose(fp);
        return;
    }
    char pw1[64], pw2[64];
    cPntOp("密码：");
    getpw(pw1);
    fflush(stdin);
    cPntOp("再次输入密码：");
    getpw(pw2);
    if (strcmp(pw1, pw2)) {
        cPntErr("密码不一致，请重试。");
        return;
    }
    fp = fopen(authpath, "w");
    fputs(pw1, fp);
    fclose(fp);
}

void changePw() {
    cPntH("修改密码");
    cPntOp("用户名：");
    char name[64];
    gets(name);
    FILE* fp;
    GenAuthPath(name);
    if ((fp = fopen(authpath, "r")) == NULL) {
        cPntErr("用户不存在，请重试。");
        fclose(fp);
        return;
    }
    cPntOp("原密码：");
    char pw[64], realPw[64];
    getpw(pw);
    fgets(realPw, 64, fp);
    fclose(fp);
    if (strcmp(pw, realPw)) {
        cPntErr("密码错误，请重试。");
        fclose(fp);
        return;
    }
    char pw1[64], pw2[64];
    fp = fopen(authpath, "w");
    cPntOp("密码：");
    getpw(pw1);
    cPntOp("再次输入密码：");
    getpw(pw2);
    if (strcmp(pw1, pw2)) {
        cPntErr("密码不一致，请重试。");
        return;
    }
    fputs(pw1, fp);
    fclose(fp);
}

void cancelAc() {
    cPntH("注销账号");
    cPntOp("用户名：");
    char name[64];
    gets(name);
    FILE* fp;
    GenAuthPath(name);
    if ((fp = fopen(authpath, "r")) == NULL) {
        cPntErr("用户不存在，请重试。");
        fclose(fp);
        return;
    }
    cPntOp("密码：");
    char pw[64], realPw[64];
    getpw(pw);
    fgets(realPw, 64, fp);
    fclose(fp);
    if (strcmp(pw, realPw)) {
        cPntErr("密码错误，请重试。");
        fclose(fp);
        return;
    }
    cPntOp("输入y来删除: ");
    if (pickchar() == 'y')
        remove(authpath);
}

#endif
