#include <iostream>

struct Link{
    int value;
    Link* next = nullptr;
};

//Punkt a
size_t size(const Link* head){
    size_t size = 0;
    while(head!= nullptr){
        size++;
        head = head->next;
    }
    return size;
}

//punkt b
size_t sum(const Link* head){
    size_t sum = 0;
    if(head!= nullptr){
        sum += head->value;
        head = head->next;
    }
    return sum;
}

int main(){

    Link list;
    std::cout << "wielkość listy: " << size(&list) << std::endl;
    std::cout << "Suma wartości: " << sum(&list) << std::endl;

    return 0;
}