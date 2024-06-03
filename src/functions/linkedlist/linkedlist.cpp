#include "global.h"

void insertNewNode(LLNode*& pHead, unsigned int new_id)
{
    LLNode* tmp = new LLNode;
    tmp->id = new_id;
    tmp->next = nullptr;
    if (!pHead)
    {
        pHead = tmp;
        return;
    }
    LLNode* cur = pHead;
    while (cur->next != nullptr)
    {
        cur = cur->next;
    }
    cur->next = tmp;
}

void printOutLL(LLNode*& pHead)
{
    for (; pHead != nullptr; pHead = pHead->next)
    {
        std::cout << pHead->id << " ";
    }
}

void deleteAtBeginning(LLNode*& pHead)
{
    LLNode* tmp = pHead;
    if (pHead) pHead = pHead->next;
    delete tmp;
}

void deleteANode(LLNode*& pHead, unsigned int id)
{
    if (!pHead) return;
    if (pHead->id == id)
    {
        deleteAtBeginning(pHead);
        return;
    }
    LLNode* pre = nullptr;
    LLNode* cur = pHead;
    while (cur != nullptr && cur->id != id)
    {
        pre = cur;
        cur = cur->next;
    }
    if (!cur) return;
    pre->next = cur->next;
    delete cur;
}

void deleteLL(LLNode*& pHead)
{
    while (pHead)
    {
        LLNode* tmp = pHead;
        delete tmp;
        pHead = pHead->next;
    }
}
