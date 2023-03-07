#ifndef _MgrUtils_
#define _MgrUtils_

#include "ColoredIO.h"

#define LOGFILE "./data/log.txt"
#define RATE 3.5
#define MAX_LENGTH 1024
#define Q_d 0b1
#define Q_i 0b10
#define Q_p 0b100
#define Q_sf 0b1000
#define Q_st 0b10000
#define Q_t 0b100000

typedef struct log {
    unsigned long date;
    unsigned short id;
    char phone[64];
    char siteFrom[64];
    char siteTo[64];
    unsigned time;
    float bill;
    struct log* next;
} Log;
Log* logH;

Log* loadLog();
void saveLog(Log* logH);

Log* loadLog() {
    FILE* fp = fopen(LOGFILE, "r");
    if (!fp)
        cPntErr("找不到日志文件，将在后续写入时创建。");
    logH = (Log*)malloc(sizeof(Log));
    Log logT;
    for (Log* logN = logH; logN; *logN = logT) {
        if (fscanf(fp, "%lu %hu %s %s %s %u %f\n", &logT.date, &logT.id,
                   logT.phone, logT.siteFrom, logT.siteTo, &logT.time,
                   &logT.bill) == -1) {
            logN->next = NULL;
            break;
        }
        logN = logN->next = (Log*)malloc(sizeof(Log));
    }
    fclose(fp);
    return logH;
}

void saveLog(Log* logH) {
    FILE* fp = fopen(LOGFILE, "w");
    for (Log* logN = logH->next; logN; logN = logN->next)
        fprintf(fp, "%lu %hu %s %s %s %u %.1f\n", logN->date, logN->id,
                logN->phone, logN->siteFrom, logN->siteTo, logN->time,
                logN->bill);
    fclose(fp);
}

#endif
