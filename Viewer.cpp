#include <Windows.h>
#include <conio.h>
#include "TText.h"
#include <string>
#include <iostream>

#define HOME 71
#define DOWN 77
#define NEXT 80
#define UP 72
#define ESC	27
#define INS	82
#define DEL	83
#define ENTER 13

void color(int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x, int y){
    HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
    if (!Console)return;

    COORD pos;
    pos.X = x;
    pos.Y = y;

    SetConsoleCursorPosition(Console, pos);
}

void control(TText text){
    char ch;
    do{
        std::string str;
        ch = getch();
        switch (ch) {
            case ENTER:
                std::cout << "Enter text: ";
                std::getline(std::cin, str);
                text.setLine(str);
                break;
            case HOME:
                text.goFirstLine();
                break;
            case DOWN:
                text.goDownLine();
                break;
            case NEXT:
                text.goNextLine();
                break;
            case UP:
                text.goPrevLine();
                break;
            case INS:
                break;
            case DEL:
                break;
        }
        if(text.isPCurrNull()){
            text.goPrevLine();
        }

        if(text.isPCurrNull()){
            text.goFirstLine();
        }
        text.writeToConsole();
    } while (ch != ESC);
}
