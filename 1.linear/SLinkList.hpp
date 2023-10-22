#include"SNode.h"
#include"Status.h"
#include<iostream>
template<class DataType>
class SLinkList
{
private:
    SNode<DataType> elem[100];
    int head, avail, length;
public:
    SLinkList() :head(0), length(0), avail(1) {
        for(int i = 0; i < 100; ++i) {
            elem[i].next = i + 1;
        }
        elem[99].next = -1;
        elem[0].next = -1;
    }
    // SLinkList(const DataType* data, int n) :head(0), length(n), avail(n + 1) {
    //     elem = new SNode<DataType>[n + 11];
    //     elem[0].next = 1;
    //     for(int i = 1; i < n + 1; ++i) {
    //         elem[i].data = data[i];
    //         elem[i].next = i + 1;
    //     }
    //     for(int j = n + 1; j < n + 10; ++j) {
    //         elem[j].next = j + 1;
    //     }
    //     elem[n + 10].next = -1;
    //     elem[n].next = -1;
    // }
    int getLength() const {
        return length;
    }
    bool isEmpty() const {
        return length == 0;
    }
    void clear() {
        int p = head;
        while(elem[p].next != -1) {
            p = elem[p].next;
        }
        elem[p].next = avail;
        elem[0].next = -1;
        length = 0;
    }
    Status insertElem(const DataType& e) {
        if(avail == -1) return OVER_FLOW;
        int q = avail;
        avail = elem[avail].next;
        elem[q].data = e;
        elem[q].next = -1;
        int p = head;
        while(elem[p].next != -1) {
            p = elem[p].next;
        }
        elem[p].next = q;
        ++length;
        return SUCESESS;
    }
    void deleteNext(int n) {
        int p = elem[n].next;
        elem[n].next = elem[p].next;
        elem[p].next = avail;
        avail = p;
    }
    Status deleteElem(const DataType&e) {
        if(length == 0) return UNDER_FLOW;
        int p = head;
        while(elem[p].next != -1) {
            if((elem[p].next)[elem].data == e) {
                deleteNext(p);
                continue;
            }
            p = elem[p].next;
        }
        return SUCESESS;
    }
    void traverse() {
        int p = head;
        while(elem[p].next != -1) {
            p = elem[p].next;
            std::cout << elem[p].data << ' ';
        }
        std::cout << std::endl;
    }
};
