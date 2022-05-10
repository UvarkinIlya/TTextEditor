#include <string>

#define TEXT_LENGTH 80

class TNode {
public:
    TNode* pNext;
    TNode* pDown;
    char text[TEXT_LENGTH];
    explicit TNode(char _text[] = nullptr, TNode *_pDown = nullptr, TNode *_pNext = nullptr);
    explicit TNode(const std::string& _text, TNode *_pDown, TNode *_pNext);

    void setLine(const std::string& str);
};