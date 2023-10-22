#include"Status.h"
#include<iostream>
template<class DataType>
class CirQueue {
private:
    DataType* elem;
    int front, rear, size;
public:
    CirQueue(int s = 10) :front(0), rear(0), size(s) {
        elem = new DataType[size];
    }
    CirQueue(const DataType* data, int n) :front(0), rear(n), size(n + 10) {
        elem = new DataType[size];
        for(int i = 0; i < n; ++i) {
            elem[i] = data[i];
        }
    }
    ~CirQueue() {
        delete[] elem;
    }
    int getSize() const {
        return size;
    }
    int getLength() const {
        return (size + rear - front) % size;
    }
    bool isEmpty() const {
        return front == rear;
    }
    bool isFull() const {
        // return size == getLength() + 1;
        return front == (rear + 1) % size;
    }
    Status getHead(DataType& e) const {
        if(front == rear) return INVALID;
        e = elem[front];
        return SUCESESS;
    }
    Status getTail(DataType& e) const {
        if(front == rear) return INVALID;
        e = elem[(size + rear - 1) % size];
        return SUCESESS;
    }
    void clear() {
        front = rear = 0;
    }
    Status enQueue(const DataType& e) {
        if(isFull()) return OVER_FLOW;
        elem[rear] = e;
        rear = (rear + 1) % size;
        return SUCESESS;
    }
    Status deQueue() {
        if(front == rear) return UNDER_FLOW;
        front = (front + 1) % size;
        return SUCESESS;
    }
    Status deQueue(DataType& e) {
        if(front == rear) return UNDER_FLOW;
        e = elem[front];
        front = (front + 1) % size;
        return SUCESESS;
    }
    void traverse() const {
        for(int i = front; i <front + getLength(); ++i) {
            std::cout << elem[i % size] << ' ';
        }
        std::cout << std::endl;
    }
};