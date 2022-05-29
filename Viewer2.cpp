#include "TText.h"
////#include <Windows.h>
////#include <conio.h>
////#include <iostream>
////
////#define HOME 71
////#define DOWN 80
////#define NEXT 77
////#define UP 72
////#define ESC	27
////#define INS	82
////#define DEL	83
////#define ENTER 13
////
////void color(int color){
////    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
////}
////
////void gotoxy(int x, int y){
////    COORD c;
////    c.X=x;
////    c.Y=y;
////    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
////}
////
////int main(){
////    int Set[] = {7,7,7,7,7}; // DEFAULT COLORS
////    int counter = 3;
////    char key;
////
////    for(int i=0;;){
////
////
////        gotoxy(10,5);
////        color(Set[0]);
////        std::cout<<"1. Menu";
////
////        gotoxy(10,6);
////        color(Set[1]);
////        std::cout<<"2. Help";
////
////        gotoxy(10,7);
////        color(Set[2]);
////        std::cout<<"3. Exit";
////
////        gotoxy(10,8);
////        color(Set[3]);
////        std::cout<<"4. Extra_1";
////
////        gotoxy(10,9);
////        color(Set[4]);
////        std::cout<<"5. Extra_2";
////
////        key = _getch();
////
////        if(key == 72 && (counter >=2 && counter <= 5))
////        {
////            counter--;
////        }
////        if(key == 80 && (counter >=1 && counter <= 4))
////        {
////            counter++;
////        }
////        if(key == '\r')//carriage return
////        {
////            if(counter == 1)
////            {
////                // if enter is click and highlight is on 1 the program will run the code here
////                std::cout<<"Menu 1 is Open";
////            }
////            if(counter == 2)
////            {
////                std::cout<<"Menu 2 is Open";
////            }
////            if(counter == 3)
////            {
////                std::cout<<"Menu 3 is Open";
////            }
////            if(counter == 4)
////            {
////                std::cout<<"Menu 4 is Open";
////            }
////            if(counter == 5)
////            {
////                std::cout<<"Menu 5 is Open";
////            }
////        }
////
////        Set[0] = 7;
////        Set[1] = 7;
////        Set[2] = 7;
////        Set[3] = 7;
////        Set[4] = 7;
////
////        if(counter == 1)
////        {
////            Set[0] = 12;
////        }
////        if(counter == 2)
////        {
////            Set[1] = 12;
////        }
////        if(counter == 3)
////        {
////            Set[2] = 12;
////        }
////        if(counter == 4)
////        {
////            Set[3] = 12;
////        }
////        if(counter == 5)
////        {
////            Set[4] = 12;
////        }
////
////
////    }
////}
//
//
//#include <iostream>
//#include "TText.h"
//#include <fstream>
//#include <locale>
//#include <conio.h>
//
//#define HOME	71
//#define DOWN	80
//#define NEXT	77
//#define UP	72
//#define ESC	27
//#define INS	82
//#define DEL	83
//#define ENTER	13
//#define z 122
//#define x 120
//#define c 99
//#define v 118
//#define p 112
//#define f 102
//#define m 109
//#define s 115
//
//using namespace std;
//
//int main(){
//    //TNode::initMem();
//    //setlocale(LC_ALL, "Russian");
//
//    TText text;
//    char ch;
//    //ifstream ifs("text.txt");
//
//    text.readFile("text.txt");
//    text.goFirstLine();
//    text.reset();
//
//    do {
//        cout << endl;
//        cout << "HOME - Go fist line" << endl;
//        cout << "RIGHT - Go next line" << endl;
//        cout << "DOWN - Go down line" << endl;
//        cout << "UP - Go previous line" << endl;
//        cout << "z - Insert next line" << endl;
//        cout << "x - Insert next section" << endl;
//        cout << "c - Insert down line" << endl;
//        cout << "v - Insert down section" << endl;
//        cout << "INS - Delete next line" << endl;
//        cout << "DEL - Delete down line" << endl;
//        cout << "p - Print" << endl;
//        cout << "m - Clean mem" << endl;
//        cout << "f - Print free" << endl;
//        cout << "s - Save into a file" << endl;
//        char* str = new char[100];
//        ch = _getch();
//        if (ch == 0xE0) ch = _getch();
//        if (ch == ESC) break;
//        //if (ch != ENTER) ch = _getch();
//        switch (ch) {
//            case ENTER:
//                break;
//            case HOME: {
//                cout << "×óè ìû äîìà\n";
//                text.goFirstLine();
//                break;
//            }
//            case DOWN: {
//                text.goDownLine();
//                break;
//            }
//            case NEXT: {
//                text.goNextLine();
//                break;
//            }
//            case UP: {
//                text.goPrevLine();
//                break;
//            }
//            case z: {
//                cout << "Ââåäèòå ñòðîêó" << endl;
//                cin.getline(str,100);
//                //text.insNextLine(str);
//                break;
//            }
//            case x: {
//                cout << "Ââåäèòå ñòðîêó" << endl;
//                cin.getline(str, 100);
//                //text.insNextSection(str);
//                break;
//            }
//            case c: {
//                cout << "Ââåäèòå ñòðîêó" << endl;
//                cin.getline(str, 100);
//                //text.insDownLine(str);
//                break;
//            }
//            case v: {
//                cout << "Ââåäèòå ñòðîêó" << endl;
//                cin.getline(str, 100);
//                //text.insDownSection(str);
//                break;
//            }
//            case INS: {
//                //text.delNextLine();
//                break;
//            }
//            case DEL: {
//               // text.delDownLine();
//                break;
//            }
//            case p: {
//                //text.print();
//                break;
//            }
//            case m: {
//                //TNode::cleanMem(text);
//                break;
//            }
//            case f: {
//                cout << "Ñâîáîäíûå: " << endl;
//               // TNode::printFree();
//                break;
//            }
//            case s: {
//                ofstream ofs("text.txt", ios::trunc);
//                //text.printFileMain(ofs);
//                break;
//            }
//        }
//    } while (ch != ESC);
//
//
//
//    //TText text2 = text.copy();
//
//    //
//
//    /* First
//     Second
//     Third*/
//}
