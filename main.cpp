#include <iostream>
#include "TText.h"
#include <conio.h>
#include "Viewer.h"

//TMem TNode::mem;//Почему с этим полем пропадает ошибка линковки

int main() {
    try {
        TNode::initMemSystem(15);
        TText text;

        text.readFile("../text.txt");
        text.goFirstLine();
        text.writeToConsole();
        //TText* text2 = text.getCopy();
        //TNode::printFreeLink();
        control(text);
    } catch (std::exception& exception) {
        std::cerr << exception.what();
    }

    char ch = _getch();
    return 0;
}
