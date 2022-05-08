#include <iostream>
#include "TText.h"
#include <conio.h>
#include "Viewer.h"

int main() {
    try {
        TText text;
        //char ch;

        text.readFile("../text.txt");

        textProcessor(text);
    } catch (std::exception& exception) {
        std::cerr << exception.what();
    }

    return 0;
}
