#include <iostream>
#include "TText.h"
#include <conio.h>
#include "Viewer.h"

int main() {
    try {
        TText text;

        text.readFile("../text.txt");
        text.goFirstLine();
        text.writeToConsole();
        control(text);
    } catch (std::exception& exception) {
        std::cerr << exception.what();
    }

    return 0;
}
