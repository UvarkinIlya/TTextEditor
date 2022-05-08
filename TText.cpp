#include "TText.h"

TText::TText(TNode *_pFirst) {
    if(_pFirst == nullptr){
        pFirst = new TNode();
    } else{
        pFirst = _pFirst;
    }
}

void TText::readFile(const std::string& filename) {
    std::ifstream file (filename);
    if(!file.is_open()){
        throw_with_nested( std::runtime_error("Couldn't open file path:" + filename));
    }

    pFirst = readFileRec(file);
    writeToConsole();
}

void TText::writeToConsole() {
    int level = 0;
    writeToConsoleRec(level, pFirst);
}

void TText::writeToConsoleRec(int level, TNode *node) {
    if(node == nullptr){
        return;
    }

    for(int i = 0; i < level; i++){
        std::cout << "\t";
    }

    std::cout << node->text << std::endl;
    writeToConsoleRec(level+1, node->pDown);
    writeToConsoleRec(level, node->pNext);
}

TNode *TText::readFileRec(std::ifstream &ifs) {
    TNode* pHead = nullptr;
    TNode* tmp;
    char buf[81];

    while (!ifs.eof()){
        ifs.getline(buf, 80, '\n');
        if(buf[0] == '}'){
            break;
        } else if(buf[0] == '{'){
            tmp->pDown= readFileRec(ifs);
        } else{
            auto* p = new TNode(buf);
            if(pHead == nullptr){
                pHead = tmp = p;
            } else{
                tmp->pNext = p;
                tmp = p;
            }
        }
    }

    return pHead;
}

void TText::writeFile(const std::string &filename) {
    std::ifstream file (filename);
    if(!file.is_open()){
        throw_with_nested( std::runtime_error("Couldn't open file path:" + filename));
    }
}

std::string TText::getLine() {
    if(pCurr == nullptr){
        return "";
    }
    return pCurr->text;
}

void TText::setLine(const std::string& str) {
    if(pCurr == nullptr){
        throw_with_nested(std::runtime_error("pCurr is NULL"));
    }

    strncpy_s(pCurr->text, str.c_str(), TEXT_LENGTH);
}

void TText::goFirstLine() {
    pCurr = pFirst;
}

void TText::goNextLine() {
    if(pCurr == nullptr){
        throw_with_nested(std::runtime_error("pCurr is NULL"));
    }

    Path.push(pCurr);
    pCurr = pCurr->pNext;
}

void TText::goDownLine() {
    if(pCurr == nullptr){
        throw_with_nested(std::runtime_error("pCurr is NULL"));
    }

    Path.push(pCurr);
    pCurr = pCurr->pDown;
}

void TText::goPrevLine() {
    if(Path.empty()){
        pCurr = nullptr;
        return;
    }

    pCurr = Path.top();
    Path.pop();
}

void TText::reset() {
    pCurr = pFirst;
}

bool TText::isEnd() {
    return pCurr == nullptr;
}

void TText::goNext() {
    if(pCurr == nullptr){
        throw_with_nested(std::runtime_error("pCurr is NULL"));
    }

    if(pCurr->pDown != nullptr){
        goDownLine();
    } else if(pCurr->pNext != nullptr){
        goNextLine();
    } else{
        goPrevLine();
    }
}
