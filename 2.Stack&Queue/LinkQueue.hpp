#include"Status.h"
#include"Node.h"
#include<iostream>
template<class DataType>
class LinkQueue {
protected:
    Node<DataType>* front,* rear;
    int length;
public:
    LinkQueue() :length(0) {
        front = new Node<DataType>;
        rear = front;
    }
    LinkQueue(const DataType* data, int n) :length(0) {
        front = new Node<DataType>;
        rear = front;
        for(int i = 0; i < n; ++i) {
            enQueue(data[i]);
        }
    }
    ~LinkQueue() {
        clear();
        delete front;
    }
    bool isEmpty() const {
        return length == 0;
    }
    int getLength() const {
        return length;
    }
    void clear() {
        Node<DataType>* p = front;
        while (p->next != nullptr)
        {
            front = front->next;
            delete p;
            p = front;
        }
        length = 0;
    }
    Status enQueue(const DataType& e) {
        rear->next = new Node<DataType>(e);
        rear = rear->next;
        ++length;
        return SUCESESS;
    }
    Status deQueue() {
        if(length == 0) return UNDER_FLOW;
        Node<DataType>* p = front;
        front = front->next;
        delete p;
        --length;
        return SUCESESS;
    }
    Status deQueue(DataType& e) {
        if(length == 0) return UNDER_FLOW;
        Node<DataType>* p = front;
        front = front->next;
        delete p;
        e = front->data;
        --length;
        return SUCESESS;
    }
    void traverse() const {
        if(length == 0) return;
        Node<DataType>* p = front;
        while(p->next != nullptr) {
            p = p->next;
            std::cout << p->data << ' ';
        }
    }
    void traverseLn() const {
        if(length == 0) return;
        Node<DataType>* p = front;
        while(p->next != nullptr) {
            p = p->next;
            std::cout << p->data << ' ';
        }
        std::cout << std::endl;
    }
};
template<class DataType>
class SStack {
private:
    LinkQueue<DataType> q1, q2;
public:
    SStack() {}
    SStack(const DataType* data, int n) :q1(data, n) {}
    bool isEmpty() const {
        return q1.isEmpty() && q2.isEmpty();
    }
    int getLength() const {
        return q1.getLength() + q2.getLength();
    }
    void clear() {
        q1.clear();
        q2.clear();
    }
    Status push(const DataType& e) {
        if(q1.isEmpty()) {
            q2.enQueue(e);
        } else {
            q1.enQueue(e);
        }
        return SUCESESS;
    }
    Status pop() {
        if(q1.isEmpty() && q2.isEmpty()) return INVALID;
        DataType temp;
        if(q1.isEmpty()) {
            for(int i = 0; i < getLength() - 1; ++i) {
                q2.deQueue(temp);
                q1.enQueue(temp);
            }
            q2.clear();
        } else {
            for(int i = 0; i < getLength() - 1; ++i) {
                q1.deQueue(temp);
                q2.enQueue(temp);
            }
            q1.clear();
        }
        return SUCESESS;
    }
    Status pop(DataType& e) {
        if(q1.isEmpty() && q2.isEmpty()) return INVALID;
        if(q1.isEmpty()) {
            for(int i = 0; i < q2.getLength() - 1; ++i) {
                DataType temp;
                q2.deQueue(temp);
                q1.enQueue(temp);
            }
            q2.deQueue(e);
        }
        else {
            for(int i = 0; i < q1.getLength() - 1; ++i) {
                DataType temp;
                q1.deQueue(temp);
                q2.enQueue(temp);
            }
            q1.deQueue(e);
        }
        return SUCESESS;
    }
    void traverse() const {
        if(isEmpty()) return;
        std::cout << "bottom -> top : ";
        if(q1.isEmpty()) q2.traverseLn();
        else q1.traverseLn();
    }
};