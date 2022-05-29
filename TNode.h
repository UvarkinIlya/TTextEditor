#pragma once
#include <string>
//#include "TMem.h"

#define TEXT_LENGTH 80
#define MEM_SIZE 100

class TText;
class TNode;
class TMem;

class TMem {
    TNode *pFirst;
    TNode *pLast;
    TNode *pFree;

    friend class TNode;//Классу TNode разрешили доступ к закрытым полям TMem
};

class TNode {
public:
    TNode* pNext;
    TNode* pDown;
    bool isTrash;
    char text[TEXT_LENGTH];
    TNode(char _text[] = nullptr, TNode *_pDown = nullptr, TNode *_pNext = nullptr);
    TNode(const std::string& _text, TNode *_pDown, TNode *_pNext);

    void setLine(const std::string& str);
    TNode* copy(TNode* node);

    //управление памятью
    inline static TMem mem;
    static void initMemSystem(int size = MEM_SIZE);//инициализация памяти
    static void printFreeLink(); //печать свободных звеньев
    static void memCleaner (TText &text); // сборка мусора
    void *operator new(size_t size);
    void operator delete(void*);
};
