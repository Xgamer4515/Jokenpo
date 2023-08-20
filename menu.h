#ifndef MENU_H
#define MENU_H

#ifdef _WIN32
#include <Windows.h>

inline void ConfigurarAcentuacaoConsole() {
    system("chcp 65001 > nul");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
}
#endif

inline void LimparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void Menu();

#endif // MENU_H
