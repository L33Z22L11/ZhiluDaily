#ifdef _WIN32
#include <windows.h>
#endif

#include "asset/LoginUtils.h"
#include "asset/MenuUtils.h"

int main() {
#ifdef _WINDOWS_
    // Windows 控制台编码设置为 UTF-8
    // SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif

    Log* log = loadLog();
    int state = -1;
    while (state)
        if (state == -1)
            login(&state);
        else
            menu(&state);
    saveLog(log);
    return 0;
}
