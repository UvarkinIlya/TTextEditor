#include "TNode.h"
#include <iostream>
#include <fstream>
#include <stack>

class TText {
    TNode* pFirst;
    TNode* pCurr;
    std::stack<TNode*> Path; // стек траектории движения по тексту
public:
    explicit TText(TNode* _pFirst = nullptr);
    void readFile (const std::string& filename); //чтение текста из файла
    void writeFile (const std::string& filename); //запись в файл to-do дописать
    std::string getLine(); // чтение текущей строки
    void setLine (const std::string& str); // замена текущей строки

    void goFirstLine();// переход к первой строке
    void goNextLine();// переход к следующей строке по Next
    void goDownLine();// переход к следующей строке по Down
    void goPrevLine();// переход к предыдущей позиции в тексте
    void writeToConsole();

    //навигация
    void reset();
    bool isEnd();
    void goNext();

private:
    TNode* readFileRec(std::ifstream& ifs);

    void writeToConsoleRec(int level, TNode* node);
};

