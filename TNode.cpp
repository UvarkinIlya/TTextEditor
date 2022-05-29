#include "TNode.h"
#include <cstring>
#include <stdexcept>
#include <iostream>
#include "TText.h"

TNode::TNode(char _text[], TNode *_pDown, TNode *_pNext) {
    pDown = _pDown;
    pNext = _pNext;

    if(_text != nullptr){
        strcpy_s(text, _text);
    } else{
        text[0] = '\0';
    }
}

void TNode::setLine(const std::string& str) {
    strncpy_s(text, str.c_str(), TEXT_LENGTH);
}

TNode::TNode(const std::string& _text, TNode *_pDown, TNode *_pNext) {
    pDown = _pDown;
    pNext = _pNext;

    setLine(_text);
}

void TNode::initMemSystem(int size) {
    mem.pFirst = (TNode*) new char[sizeof(TNode) * size];
    mem.pFree = mem.pFirst;
    mem.pLast = mem.pFirst + size - 1;
    TNode* node = mem.pFirst;
    for (int i = 0; i < size - 1; i++, node++){
        node->pNext = node + 1;
        node->setLine("");
        node->isTrash = false;
    }
    node->pNext = nullptr;
    node->setLine("");
    node->isTrash = false;
}

void *TNode::operator new(size_t size) {
    if(mem.pFree == nullptr){
        throw_with_nested(std::runtime_error("pFree is NULL"));
    }
    TNode* node = mem.pFree;
    mem.pFree = mem.pFree->pNext;

    return node;
}

void TNode::operator delete(void *node) {
    auto lastPFree = mem.pFree;
    mem.pFree = (TNode*)node;
    mem.pFree->isTrash = true;
    mem.pFree->pNext = lastPFree;
    mem.pFree->pDown = nullptr;
}

void TNode::printFreeLink() {
    auto node = mem.pFree;
    while (node->pNext != nullptr){
        std::cout << node->text << "->";
        node = node->pNext;
    }

    if(node != nullptr){
        std::cout << node->text;
    }
}

void TNode::memCleaner(TText &text) {
    TNode* node = mem.pFirst;
    while (node != mem.pLast){
        node->isTrash = true;
        node++;
    }
    mem.pLast->isTrash = true;

    auto free = mem.pFree;
    while (free != nullptr){
        free->isTrash = false;
        free = free->pNext;
    }

    for(text.reset(); !text.isEnd(); text.goNext()){
        text.getPCurr()->isTrash = false;
    }

    node = mem.pFirst;
    while (node != mem.pLast){
        if(node->isTrash){
            delete node;
        }
        node++;
    }
}

TNode *TNode::copy(TNode *nodeSample) {
    if(nodeSample == nullptr){
        return nullptr;
    }

    TNode* pD = copy(nodeSample->pDown);
    TNode* pN = copy(nodeSample->pNext);

    auto node = new TNode(nodeSample->text, pD, pN);

    return node;
}
