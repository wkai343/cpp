#include"DNode.h"
#include"Status.h"
#include<iostream>
template<class DataType>
class DLinkList {
private:
    DNode<DataType>* head,* end;
    int length;
public:
    DLinkList() :length(0) {
        head=new DNode<DataType>;
        end = head;
    }
    DLinkList(const DataType* data, int n) :length(0) {
        head = new DNode<DataType>;
        end = head;
        for(int i = 0; i < n; ++i) insertElem(data[i]);
    }
    // DLinkList(const DataType* data, int n) :length(n) {
    //     head = new DNode<DataType>;
    //     DNode<DataType>* p = head;
    //     for (int i = 0; i < n; ++i) {
    //         p->next = new DNode<DataType>(data[i], p);
    //         p = p->next;
    //     }
    //     end = p;
    // }
    ~DLinkList() {
        clear();
        delete head;
    }
    int getLength() const {
        return length;
    }
    bool isEmpty() const {
        return length == 0;
    }
    void clear() {
        DNode<DataType>* p = head;
        while(head->next != nullptr) {
            head = head->next;
            delete p;
            p = head;
        }
        length = 0;
    }
    Status insertElem(const DataType& e) {
        end->next = new DNode<DataType>(e, end);
        end = end->next;
        ++length;
        return SUCESESS;
    }
    void deletePrior(DNode<DataType>* p) {
        deleteCurr(p->prior);
    }
    void deleteCurr(DNode<DataType>* p) {
        p->prior->next = p->next;
        p->next->prior = p->prior;
        delete p;
        --length;
    }
    void deleteNext(DNode<DataType>* p) {
        deleteCurr(p->next);
    }
    DNode<DataType>* locateN(int i) const {
        if (i<0 || i > length) return nullptr;
        DNode<DataType>* p = head->next;
        for (int j = 0; j < i; ++j) {
            p = p->next;
        }
        return p;
    }
    void traverse() const {
        if (length == 0) return;
        DNode<DataType>* p = head->next;
        while(p != nullptr) {
            std::cout << p->data << ' ';
            p = p->next;
        }
        std::cout << std::endl;
    }
    void reverse() const {
        if (length == 0) return;
        DNode<DataType>* p = end;
        while (p->prior != nullptr) {
            std::cout << p->data << ' ';
            p = p->prior;
        }
        std::cout << std::endl;
    }
};