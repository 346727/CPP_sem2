#include <iostream>

struct Link {
    int value;
    Link* next = nullptr;
};

void release(Link** phead) {
    if (*phead == nullptr)
        return;

    Link* next = (*phead)->next;
    delete *phead;
    *phead = next;

    release(phead);
}

int main() {

    Link* head = new Link;
    head->value = 1;
    head->next = new Link;
    head->next->value = 2;
    head->next->next = new Link;
    head->next->next->value = 3;
    

    Link* current = head;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;

//zwolnienie pamięci
    release(&head);
    
    if (head == nullptr)
        std::cout << "Lista została usunięta." << std::endl;
    else
        std::cout << "Coś poszło nie tak." << std::endl;

    return 0;
}
