#include <iostream>

struct Link{
    int value;
    Link* next = nullptr;
};

void release(Link** phead)
{
    if (*phead == nullptr)
        return;

    Link* next = (*phead)->next;
    delete *phead;
    *phead = next;

    release(phead);
}