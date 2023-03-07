#ifndef _MenuUtils_
#define _MenuUtils_

#include "MgrUtils.h"

void menu(int* state);
void logAdd();
void logMod();
void logDel();
Log* logQuery();
void logSort();
void logReport();

void menu(int* state) {
    puts("================================");
    puts("     1. 录入记录                ");
    puts("     2. 修改记录                ");
    puts("     3. 删除记录                ");
    puts("     4. 记录查询/统计           ");
    puts("     5. 记录排序                ");
    puts("     6. 统计报表                ");
    puts("     a. 登出                    ");
    puts("     0. 退出                    ");
    puts("================================");
    cPntOp("请选择：");
    switch (pickchar()) {
        case '1':
            cPntH("录入记录");
            logAdd();
            break;
        case '2':
            cPntH("修改记录");
            logMod();
            break;
        case '3':
            cPntH("删除记录");
            logDel();
            break;
        case '4':
            cPntH("查询统计");
            logQuery();
            break;
        case '5':
            cPntH("记录排序");
            logSort();
            break;
        case '6':
            logReport();
            break;
        case 'a':
            *state = -1;
            break;
        case '0':
            *state = 0;
            break;
        default:
            cPntErr("未知选项，请重新选择！");
            break;
    }
}

void logAdd() {
    cPntOp("租借日期(YYYYMMdd): ");
    unsigned long dateT;
    scanf("%lu", &dateT);
    Log* logN = logH;
    while (logN->next && logN->next->date < dateT)
        logN = logN->next;
    Log* log2A = (Log*)malloc(sizeof(Log));
    log2A->next = logN->next;
    logN->next = log2A;
    log2A->date = dateT;
    cPntOp("充电宝编号: ");
    scanf("%hu", &log2A->id);
    cPntOp("用户手机号: ");
    scanf("%s", log2A->phone);
    cPntOp("租借地点: ");
    scanf("%s", log2A->siteFrom);
    cPntOp("归还地点: ");
    scanf("%s", log2A->siteTo);
    cPntOp("租借时长(min): ");
    scanf("%u", &log2A->time);
    cPntOp("费用(自动生成): ");
    printf("%.1f元\n", log2A->bill = log2A->time * RATE);
    fflush(stdin);
}

void logMod() {
    cPntErr("修改前需要通过查询来指定要修改的租借记录。");
    Log* log2M = logQuery();
    if (!log2M)
        return;
    Log logT = {0};
    cPntErr("输入信息则更新, 输入0则不更新。");
    cPntOp("租借日期(YYYYMMdd): ");
    scanf("%lu", &logT.date);
    cPntOp("充电宝编号: ");
    scanf("%hu", &logT.id);
    cPntOp("用户手机号: ");
    scanf("%s", logT.phone);
    cPntOp("租借地点: ");
    scanf("%s", logT.siteFrom);
    cPntOp("归还地点: ");
    scanf("%s", logT.siteTo);
    cPntOp("租借时长(min): ");
    scanf("%u", &logT.time);
    fflush(stdin);
    if (logT.date)
        log2M->date = logT.date;
    if (logT.id)
        log2M->id = logT.id;
    if (strcmp(logT.phone, "0"))
        strcpy(log2M->phone, logT.phone);
    if (strcmp(logT.siteFrom, "0"))
        strcpy(log2M->siteFrom, logT.siteFrom);
    if (strcmp(logT.siteTo, "0"))
        strcpy(log2M->siteTo, logT.siteTo);
    if (logT.time) {
        log2M->time = logT.time;
        log2M->bill = logT.time * RATE;
    }
}

void logDel() {
    Log* log2D = logQuery();
    if (!log2D)
        return;
    cPntOp("输入y来删除: ");
    if (pickchar() == 'y') {
        Log* logT = log2D->next;
        *log2D = *log2D->next;
        free(logT);
    }
}

Log* logQuery() {
    struct {
        unsigned long date;
        unsigned short id;
        unsigned short idMin;
        unsigned short idMax;
        char phone[64];
        char siteFrom[64];
        char siteTo[64];
        unsigned timeMin;
        unsigned timeMax;
    } queryBody = {0};
    puts("     1. 租借日期                ");
    puts("     2. 充电宝编号              ");
    puts("     3. 充电宝编号(区间)        ");
    puts("     4. 用户手机号              ");
    puts("     5. 租借地点                ");
    puts("     6. 归还地点                ");
    puts("     7. 租借时长(区间)          ");
    puts("     0. 不再添加条件            ");
    puts("================================");
    puts("每次输入一个条件编号后敲回车。");
    for (char ch; ch != '0';) {
        cPntOp("请添加条件编号: ");
        switch (ch = pickchar()) {
            case '1':
                cPntOp("租借日期(YYYYMMdd): ");
                scanf("%lu", &queryBody.date);
                break;
            case '2':
                cPntOp("充电宝编号: ");
                scanf("%hu", &queryBody.id);
                break;
            case '3':
                cPntOp("充电宝编号范围最小值: ");
                scanf("%hu", &queryBody.idMin);
                cPntOp("充电宝编号范围最大值: ");
                scanf("%hu", &queryBody.idMax);
                break;
            case '4':
                cPntOp("用户手机号: ");
                scanf("%s", queryBody.phone);
                break;
            case '5':
                cPntOp("租借地点: ");
                scanf("%s", queryBody.siteFrom);
                break;
            case '6':
                cPntOp("归还地点: ");
                scanf("%s", queryBody.siteTo);
                break;
            case '7':
                cPntOp("租借时长范围最小值: ");
                scanf("%u", &queryBody.timeMin);
                cPntOp("租借时长范围最大值: ");
                scanf("%u", &queryBody.timeMax);
                break;
            default:
                cPntErr("请重新选择！");
            case '0':;
        }
        fflush(stdin);
    }
    Log *logN = logH, *logAddr[MAX_LENGTH];
    int i = 0;
    while ((logN = logN->next))
        if (!queryBody.date | (logN->date == queryBody.date) &&
            !queryBody.id | (logN->id == queryBody.id) &&
            !queryBody.idMin | (logN->id >= queryBody.idMin) &&
            !queryBody.idMax | (logN->id <= queryBody.idMax) &&
            !*queryBody.phone | !strcmp(logN->phone, queryBody.phone) &&
            !*queryBody.siteFrom |
                !strcmp(logN->siteFrom, queryBody.siteFrom) &&
            !*queryBody.siteTo | !strcmp(logN->siteTo, queryBody.siteTo) &&
            !queryBody.timeMin | (logN->time >= queryBody.timeMin) &&
            !queryBody.timeMax | (logN->time <= queryBody.timeMax)) {
            logAddr[i++] = logN;
            logAddr[i] = NULL;
        }
    cPntErr("编号\t日期\t 充电宝号\t手机号\t 租借地点\t归还地点\t租借时长");
    for (int i = 0; logAddr[i]; i++) {
        printf("[%d]\t%-8lu  %6hu  %12s\t %s    \t%s    \t%8u\n", i + 1,
               logAddr[i]->date, logAddr[i]->id, logAddr[i]->phone,
               logAddr[i]->siteFrom, logAddr[i]->siteTo, logAddr[i]->time);
    }
    if (!i) {
        cPntErr("未查询到结果。");
        return NULL;
    }
    cPntOp("请选择记录编号：");
    int index;
    scanf("%d", &index);
    while (index > i || index < 1) {
        cPntOp("编号错误，请重新输入：");
        scanf("%d", &index);
    }
    fflush(stdin);
    return logAddr[index - 1];
}

void logSort() {
    puts("     1. 日期升序                ");
    puts("     2. 日期降序                ");
    puts("================================");
    Log *logN = logH, *logAddr[MAX_LENGTH];
    int index = 0;
    while ((logN = logN->next))
        logAddr[index++] = logN;

    cPntOp("请添加条件编号: ");
    char ch = pickchar();
    cPntErr("编号\t日期\t 充电宝号\t手机号\t 租借地点\t归还地点\t租借时长");
    for (int i = ch - '1' ? index - 1 : 0; i >= 0 && i < index;
         ch - '1' ? i-- : i++) {
        printf("[%d]\t%-8lu  %6hu  %12s\t %s    \t%s    \t%8u\n",
               ch - '1' ? index - i : i + 1, logAddr[i]->date, logAddr[i]->id,
               logAddr[i]->phone, logAddr[i]->siteFrom, logAddr[i]->siteTo,
               logAddr[i]->time);
    }
}

void logReport() {
    Log* logN = logH;
    unsigned device[MAX_LENGTH] = {0};
    while ((logN = logN->next)) {
        device[logN->id] += logN->time;
    }
    cPntH("设备寿命");
    for (int i = 0; i < MAX_LENGTH; i++) {
        if (device[i])
            printf("充电宝 %d#\t使用 %4umin\n", i, device[i]);
    }
}

#endif