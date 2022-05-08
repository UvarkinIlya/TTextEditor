#include "TNode.h"
#include <cstring>

TNode::TNode(char _text[], TNode *_pDown, TNode *_pNext) {
    pDown = _pDown;
    pNext = _pNext;

    if(_text != nullptr){
        strcpy_s(text, _text);
    } else{
        text[0] = '\0';
    }
}
