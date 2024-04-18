#include <iostream>

struct Link {
    int value;
    Link* next = nullptr;
};

void reverse(Link** lst){
    Link* prev = nullptr;
    Link* curr = *lst;
    while(curr!= nullptr){
        Link* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *lst = prev;

}
int main(){

    Link* lista = new Link;
    lista->value = 1;
    lista->next = new Link;
    lista->next->value = 2;
    lista->next->next = new Link;
    lista->next->next->value = 3;
    lista->next->next->next = new Link;
    lista->next->next->next->value = 4;

    Link* current = lista;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;

    reverse(&lista);

    current = lista;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }

    return 0;
}