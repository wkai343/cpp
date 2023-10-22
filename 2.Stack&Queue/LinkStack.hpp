#include"Node.h"
#include"Status.h"
#include<iostream>
template<class DataType>
class SQueue;
template<class DataType>
class LinkStack {
private:
    Node<DataType>* top;
    int length;
public:
    friend class SQueue<DataType>;
    LinkStack() :top(nullptr), length(0) {}
    LinkStack(const DataType* data, int n) :top(nullptr), length(0) {
        for(int i = 0; i < n; ++i) {
            push(data[i]);
        }
    }
    ~LinkStack() {
        clear();
    }
    int getLength() const {
        return length;
    }
    bool isEmpty() const {
        return length == 0;
    }
    DataType getTop() const {
        return top->data;
    }
    void clear() {
        Node<DataType>* p = top;
        while(p != nullptr) {
            top = top->next;
            delete p;
            p = top;
        }
        length = 0;
    }
    Status push(const DataType& e) {
        Node<DataType>* p = new Node<DataType>(e, top);
        top = p;
        ++length;
        return SUCESESS;
    }
    Status pop() {
        if(isEmpty()) return UNDER_FLOW;
        Node<DataType>* p = top;
        top = top->next;
        delete p;
        --length;
        return SUCESESS;
    }
    Status pop(DataType& e) {
        if(isEmpty()) return UNDER_FLOW;
        Node<DataType>* p = top;
        top = top->next;
        e = p->data;
        delete p;
        --length;
        return SUCESESS;
    }
    void traverse() const {
        Node<DataType>* p = top;
        std::cout << "top -> bottom : ";
        while(p != nullptr) {
            std::cout << p->data << ' ';
            p = p->next;
        }
    }
    void traverseLn() const {
        Node<DataType>* p = top;
        while(p != nullptr) {
            std::cout << "top -> bottom : ";
            std::cout << p->data << ' ';
            p = p->next;
        }
        std::cout << std::endl;
    }
};
template<class DataType>
class SQueue {
private:
    LinkStack<DataType> s1, s2;
public:
    SQueue() {}
    SQueue(const DataType* data, int n) :s1(data, n) {}
    bool isEmpty() const {
        return s1.isEmpty() && s2.isEmpty();
    }
    int getlength() const {
        return s1.getlength() + s2.getlength();
    }
    void clear() {
        s1.clear();
        s2.clear();
    }
    Status enQueue(const DataType &e) {
        s1.push(e);
        return SUCESESS;
    }
    Status deQueue() {
        if(isEmpty()) return UNDER_FLOW;
        if(s2.top != nullptr) {
            s2.pop();
            return SUCESESS;
        }
        while(s1.top->next != nullptr) {
            s2.push(s1.top->data);
            s1.pop();
        }
        s1.pop();
        return SUCESESS;
    }
    Status deQueue(DataType &e) {
        if(isEmpty()) return UNDER_FLOW;
        if(s2.top != nullptr) {
            s2.pop(e);
            return SUCESESS;
        }
        while(s1.top->next != nullptr) {
            s2.push(s1.top->data);
            s1.pop();
        }
        s1.pop(e);
        return SUCESESS;
    }
    void traverse() const {
        if(isEmpty()) return;
        s2.traverse();
        Node<DataType>* p = s1.top;
        LinkStack<DataType> s3;
        while(p != nullptr) {
            s3.push(p->data);
            p = p->next;
        }
        s3.traverseLn();
    }
};