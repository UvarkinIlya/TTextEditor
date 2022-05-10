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
#define SAVE 115

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
            int direction, unit, target;
            case ENTER:
                std::cout << "Enter text: ";
                std::cin.ignore(256, '\n');
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
            case SAVE:
                text.writeFile("../out.txt");
                std::cout << "File save to ../out.txt" << std::endl;
                std::cout << "press any key";
                ch = getch();

                break;
            case INS:
                std::cout << "Direction 0 - Down, 1 - Next: ";
                std::cin >> direction;

                std::cout << "Unit 0 - Line, 1 - Section: ";
                std::cin >> unit;

                std::cout << "Enter text: ";
                //std::cin >> str;
                std::cin.ignore(256, '\n');
                std::getline(std::cin, str);

                if (direction == 0){
                    if(unit == 0){
                        text.insDownLine(str);
                    } else{
                        text.insDownSection(str);
                    }
                } else{
                    if(unit == 0){
                        text.insNextLine(str);
                    } else{
                        text.insNextSection(str);
                    }
                }
                break;
            case DEL:
                std::cout << "Del 0 - Self, 1 - Section, 2 - Other: ";
                std::cin >> target;

                if(target == 0){
                    text.delPCurr();
                    break;
                } else if(target == 1){
                    text.delDown();
                    break;
                } else if(target != 2){
                    break;
                }

                std::cout << "Direction 0 - Down, 1 - Next: ";
                std::cin >> direction;

                std::cout << "Unit 0 - Line, 1 - Section: ";
                std::cin >> unit;


                if (direction == 0){
                    if(unit == 0){
                        text.delDownLine();
                    } else{
                        text.delDownSection();
                    }
                } else{
                    if(unit == 0){
                        text.delNextLine();
                    } else{
                        text.delNextSection();
                    }
                }
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
