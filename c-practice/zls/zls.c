#include <dirent.h>
#include <grp.h>
#include <linux/limits.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

void list(char dir[]);
void parseParam(char arg[]);
char* mod2str(int mod);
char* num2str(unsigned int num);
char* uname(gid_t uid);
char* gname(gid_t gid);

static unsigned param = 0;
#define P_a 0b1
#define P_l 0b10
#define P_R 0b100
#define P_t 0b1000
#define P_r 0b10000
#define P_i 0b100000
#define P_s 0b1000000

int main(int argc, char* argv[]) {
    int havePath = 0;
    for (int i = 1; i < argc; i++)
        if (*argv[i] == '-')
            parseParam(argv[i]);
        else
            havePath++;
    while (--argc)
        if (**++argv != '-')
            list(*argv);
    if (!havePath)
        list(".");
    return 0;
}

void list(char dir[]) {
    // 打开目录
    DIR* dirp = opendir(dir);
    if (!dirp) {
        closedir(dirp);
        // fprintf(stderr, "zls: 无法访问 '%s': 没有那个目录。\n", dir);
        return;
    }
    printf("%s:\n", dir);
    // 生成列表
    int entryc, entryIndex[PATH_MAX];
    struct entry {
        char dname[NAME_MAX];
        time_t mtime;
    };
    struct entry* entry = malloc(sizeof(struct entry[PATH_MAX]));
    struct dirent* entryp;
    for (entryc = 0; (entryp = readdir(dirp)) != NULL;) {
        if (!(param & P_a) && *entryp->d_name == '.')
            continue;
        struct stat einfo;
        strcpy(entry[entryc].dname, entryp->d_name);
        if (param & P_t) {
            char path[PATH_MAX];
            sprintf(path, "%s/%s", dir, entryp->d_name);
            if (stat(path, &einfo) == -1)
                continue;
            entry[entryc].mtime = einfo.st_mtim.tv_sec;
        }
        entryIndex[entryc] = entryc;
        entryc++;
    }
    // 排序
    if (param & P_t) {
        int i, j, temp;
        for (i = 1; i < entryc; i++) {
            temp = entryIndex[i];
            for (j = i;
                 j > 0 && entry[entryIndex[j - 1]].mtime > entry[temp].mtime;
                 j--)
                entryIndex[j] = entryIndex[j - 1];
            entryIndex[j] = temp;
        }
    } else {
        int i, j, temp;
        for (i = 1; i < entryc; i++) {
            temp = entryIndex[i];
            for (j = i; j > 0 && strcmp(entry[entryIndex[j - 1]].dname,
                                        entry[temp].dname) > 0;
                 j--)
                entryIndex[j] = entryIndex[j - 1];
            entryIndex[j] = temp;
        }
    }
    // 输出
    for (int i = param & P_r ? entryc - 1 : 0;
         param & P_r ? i >= 0 : i < entryc; param & P_r ? i-- : i++) {
        struct stat einfo;
        char path[PATH_MAX];
        sprintf(path, "%s/%s", dir, entry[entryIndex[i]].dname);
        if (stat(path, &einfo) == -1)
            continue;
        if (param & P_i)
            printf("%8lu  ", einfo.st_ino);
        if (param & P_s)
            // Zhilu's correction ;D
            // 纠正：应该是4KB向上取整
            printf("%4ld  ",
                   (einfo.st_size / 4096 * 4) + (einfo.st_size % 4096 ? 4 : 0));
        if (param & P_l) {
            printf("%s  ", mod2str(einfo.st_mode));
            printf("%4d  ", (int)einfo.st_nlink);
            printf("%-8s  ", uname(einfo.st_uid));
            printf("%-8s  ", gname(einfo.st_gid));
            printf("%8ld  ", einfo.st_size);
            printf("%.12s  ", 4 + ctime((const time_t*)&einfo.st_mtim));
        }
        printf(S_ISDIR(einfo.st_mode) ? "\033[1;34m%s\033[0m" : "%-10s",
               entry[entryIndex[i]].dname);
        printf(param & P_l ? "\n" : "  \t");
    }
    printf(param & P_l ? "\n" : "\n\n");
    closedir(dirp);
    // 递归
    if (!(param & P_R))
        return;
    for (int i = 0; i < entryc; i++) {
        if (!strcmp(entry[i].dname, ".") || !strcmp(entry[i].dname, ".."))
            continue;
        char* path = malloc(PATH_MAX);
        sprintf(path, "%s/%s", dir, entry[i].dname);
        list(path);
        free(path);
    }
    free(entry);
}

void parseParam(char arg[]) {
#define CheckParam(ch) \
    if (*arg == *#ch)  \
        paramTemp |= P_##ch;
    while (*++arg) {
        unsigned paramTemp = 0;
        CheckParam(a);
        CheckParam(l);
        CheckParam(R);
        CheckParam(t);
        CheckParam(r);
        CheckParam(i);
        CheckParam(s);
        param |= paramTemp;
        if (!paramTemp)
            fprintf(stderr, "zls: 未知参数 '-%c'。\n", *arg);
    }
#undef CheckParam
}

char* mod2str(int mod) {
    static char str[] = "----------";
    str[0] = S_ISDIR(mod) ? 'd' : S_ISLNK(mod) ? 'l' : '-';
    str[1] = mod & S_IRUSR ? 'r' : '-';
    str[2] = mod & S_IWUSR ? 'w' : '-';
    str[3] = mod & S_IXUSR ? 'x' : '-';
    str[4] = mod & S_IRGRP ? 'r' : '-';
    str[5] = mod & S_IWGRP ? 'w' : '-';
    str[6] = mod & S_IXGRP ? 'x' : '-';
    str[7] = mod & S_IROTH ? 'r' : '-';
    str[8] = mod & S_IWOTH ? 'w' : '-';
    str[9] = mod & S_IXOTH ? 'x' : '-';
    return str;
}

char* num2str(unsigned int num) {
    static char str[NAME_MAX];
    sprintf(str, "%d", num);
    return str;
}

char* uname(gid_t uid) {
    struct passwd* pwp = getpwuid(uid);
    return pwp ? pwp->pw_name : num2str(uid);
}

char* gname(gid_t gid) {
    struct group* grp = getgrgid(gid);
    return grp ? grp->gr_name : num2str(gid);
}
