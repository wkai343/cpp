#include<iostream>
#include"Node.h"
template<class DataStruct>
void lTraverse(const DataStruct& d) {
    if(d.isEmpty()) return;
    Node<decltype(d.head->data)>* p = d.head;
    while (p->next != nullptr) {
        p = p->next;
        std::cout << p->data << ' ';
    }
    std::cout << std::endl;
}