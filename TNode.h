#define TEXT_LENGTH 80

class TNode {
public:
    TNode* pNext;
    TNode* pDown;
    char text[TEXT_LENGTH];
    explicit TNode(char _text[] = nullptr, TNode *_pDown = nullptr, TNode *_pNext = nullptr);
};