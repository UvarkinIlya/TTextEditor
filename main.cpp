#include <iostream>
#include "TText.h"
#include <conio.h>
#//include "Viewer.h"

int main() {
    try {
        TText text;

        text.readFile("../text.txt");
        //textProcessor(text);
    } catch (std::exception& exception) {
        std::cerr << exception.what();
    }

    char ch = getch();
    return 0;
}
