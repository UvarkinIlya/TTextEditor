#include "TNode.h"
#include <cstring>
#include <string>

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