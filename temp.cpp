//#include "TText.h"
//#include <Windows.h>
//#include <conio.h>
//
//#define HOME 71
//#define DOWN 80
//#define NEXT 77
//#define UP 72
//#define ESC	27
//#define INS	82
//#define DEL	83
//#define ENTER 13
//
//std::string strs[100];
//int ns, nl;
//
//void clrscr(void){
//    HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
//    if (!Console) return;
//
//    CONSOLE_SCREEN_BUFFER_INFO buf;
//    GetConsoleScreenBufferInfo(Console, &buf);
//
//    DWORD Count;
//
//    COORD zpos;
//    zpos.X = 0;
//    zpos.Y = 0;
//
//    FillConsoleOutputCharacter(Console, ' ', buf.dwSize.X * buf.dwSize.Y, zpos, &Count);
//    SetConsoleCursorPosition(Console, zpos);
//}
//
//void clreol(void){
//    HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
//    if (!Console)return;
//
//    CONSOLE_SCREEN_BUFFER_INFO buf;
//    GetConsoleScreenBufferInfo(Console, &buf);
//
//    WORD Attr;
//    DWORD Count;
//
//    COORD zpos = buf.dwCursorPosition;//взяли позицию курсора
//
//    zpos.X = buf.dwCursorPosition.X + 1;
//    zpos.Y = buf.dwCursorPosition.Y;
//
//    FillConsoleOutputCharacter(Console, ' ', buf.dwSize.X - buf.dwCursorPosition.X - 1, zpos, &Count);
//    SetConsoleCursorPosition(Console, buf.dwCursorPosition);
//}
//
//void gotoxy(int x, int y){
//    HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
//    if (!Console)return;
//
//    COORD pos;
//    pos.X = x;
//    pos.Y = y;
//
//    SetConsoleCursorPosition(Console, pos);
//}
//
//void TextTyper(TText &text){
//    clrscr();
//    gotoxy(1, 2);
//    text.writeToConsole();
//    ns = 0;
//
//    for(text.reset(); !text.isEnd(); text.goNext()){
//        strs[ns++] = text.getLine();
//    }
//
//    text.goFirstLine();
//    nl=2;
//    gotoxy(1, nl);
//    std::cout << "\333";
//}
//
//void TextLineMark(TText &text){
//    std::string str = text.getLine();
//    gotoxy(1, nl);
//    for(nl = 0; nl < ns; nl++){
//        if(str == strs[nl]){
//            break;
//        }
//        nl += 2;
//        gotoxy(1, nl);
//        std::cout << "\333";
//    }
//}
//
//void textProcessor(TText text){
//    int dir, uint;
//    std::string str;
//    char ch;
//    do {
//        std::cout << ">,v,^, Home, Ins, Del, Enter, Esc";
//        ch = getch();
//        //if ( ch == 0xE0 ) ch = getch();
//        if ( ch == ESC ) break;
//        if ( ch != ENTER ) ch = getch();
//        switch (ch) {
//            case ENTER:
//                gotoxy(1, 1);
//                clreol();
//                std::cout << "Line (without blanks): ";
//                std::cin >> str;
//                text.setLine("2");
//                //TextTyper();
//
//                break;
//            case HOME:text.goFirstLine();break;
//            case DOWN:text.goDownLine();break;
//            case NEXT:text.goNextLine();break;
//            case UP:  text.goPrevLine();break;
//            case INS:
//            case DEL:
//                gotoxy(1, 1);
//                clreol();
//                std::cout << "not implement";
//                break;
//
//        }
//        TextLineMark(text);
//    } while ( ch != ESC );
//}
//
//void color(int color){
//    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
//}