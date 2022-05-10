#include "TText.h"
#include "Viewer.h"

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
    int CurrLine = 0;
    system("cls");
    writeToConsoleRec(level, pFirst, CurrLine);
}

void TText::writeToConsoleRec(int level, TNode *node, int &CurrLine) {
    if(node == nullptr){
        return;
    }

    if(node == pCurr){
        gotoxy(0, CurrLine);
        color(10);
    } else{
        color(7);
    }

    for(int i = 0; i < level; i++){
        std::cout << "\t";
    }

    std::cout << node->text << std::endl;
    CurrLine++;
    writeToConsoleRec(level+1, node->pDown, CurrLine);
    writeToConsoleRec(level, node->pNext, CurrLine);
    color(7);
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

bool TText::isPCurrNull() {
    return pCurr == nullptr;
}

void TText::insDownLine(const std::string& str) {
    if(pCurr == nullptr){
        throw_with_nested(std::runtime_error("pCurr is NULL"));
    }

    auto *node = new TNode(str, pCurr->pDown, nullptr);
    pCurr->pDown = node;

    pCurr = pCurr->pDown;
}

void TText::insDownSection(const std::string& str) {
    if(pCurr == nullptr){
        throw_with_nested(std::runtime_error("pCurr is NULL"));
    }

    auto *node = new TNode(str, nullptr, pCurr->pDown);
    pCurr->pDown = node;

    pCurr = pCurr->pDown;
}

void TText::insNextLine(const std::string& str) {
    if(pCurr == nullptr){
        throw_with_nested(std::runtime_error("pCurr is NULL"));
    }

    auto *node = new TNode(str, pCurr->pDown, nullptr);

    pCurr->pDown = nullptr;
    pCurr->pNext = node;

    pCurr = pCurr->pNext;
}

void TText::insNextSection (const std::string& str){
    if(pCurr == nullptr){
        throw_with_nested(std::runtime_error("pCurr is NULL"));
    }

    auto *node = new TNode(str, nullptr, pCurr->pDown);

    pCurr->pDown = nullptr;
    pCurr->pNext = node;

    pCurr = pCurr->pNext;
}

void TText::delDownLine() {
    if(pCurr == nullptr){
        throw_with_nested(std::runtime_error("pCurr is NULL"));
    }

    if(pCurr->pDown == nullptr){
        return;
    }

    TNode *delNode = pCurr->pDown;
    if (delNode->pDown == nullptr){
        pCurr->pDown = delNode->pNext;
    }
}

void TText::delDownSection() {
    if(pCurr == nullptr){
        throw_with_nested(std::runtime_error("pCurr is NULL"));
    }

    if(pCurr->pDown == nullptr){
        return;
    }

    TNode *delNode = pCurr->pDown;
    pCurr->pDown = delNode->pNext;
}

void TText::delNextLine() {
    if(pCurr == nullptr){
        throw_with_nested(std::runtime_error("pCurr is NULL"));
    }

    if(pCurr->pNext == nullptr){
        return;
    }

    TNode *delNode = pCurr->pNext;
    if (delNode->pDown == nullptr){
        pCurr->pNext = delNode->pNext;
    }
}

void TText::delNextSection() {
    if(pCurr == nullptr){
        throw_with_nested(std::runtime_error("pCurr is NULL"));
    }

    if(pCurr->pNext == nullptr){
        return;
    }

    TNode *delNode = pCurr->pNext;
    pCurr->pNext = delNode->pNext;
}

void TText::delDown() {
    if(pCurr == nullptr){
        throw_with_nested(std::runtime_error("pCurr is NULL"));
    }

    pCurr->pDown = nullptr;
}

void TText::delPCurr() {
    if(pCurr == nullptr){
        throw_with_nested(std::runtime_error("pCurr is NULL"));
    }

    if(pCurr == pFirst){
        return;
    }

    TNode *delNode = pCurr;
    goPrevLine();
    if(pCurr->pNext == delNode){
        pCurr->pNext = delNode->pNext;
    } else if (pCurr->pDown == delNode){
        pCurr->pDown = delNode->pNext;
    }
}
