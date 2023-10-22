#include"Status.h"
#include<iostream>
template<class DataType>
class SqQueue {
private:
    DataType* elem;
    int front, rear, size;
public:
    SqQueue(int s = 10) :front(0), rear(0), size(s) {
        elem = new DataType[size];
    }
    SqQueue(const DataType* data, int n) :front(0), rear(n), size(n + 10) {
        elem = new DataType[size];
        for(int i = 0; i < n; ++i) {
            elem[i] = data[i];
        }
    }
    ~SqQueue() {
        delete[] elem;
    }
    int getSize() const {
        return size;
    }
    int getLength() const {
        return rear - front;
    }
    bool isEmpty() const {
        return front == rear;
    }
    bool isFull() const {
        return size == getLength();
    }
    Status getHead(DataType& e) {
        if(front == rear) return INVALID;
        e = elem[front];
        return SUCESESS;
    }
    Status getTail(DataType& e) {
        if(front == rear) return INVALID;
        e = elem[rear - 1];
        return SUCESESS;
    }
    void clear() {
        front = rear = 0;
    }
    Status enQueue(const DataType& e) {
        if(rear == size) return OVER_FLOW;
        elem[rear++] = e;
        return SUCESESS;
    }
    Status deQueue() {
        if(front == rear) return UNDER_FLOW;
        ++front;
        return SUCESESS;
    }
    Status deQueue(DataType& e) {
        if(front == rear) return UNDER_FLOW;
        e = elem[front++];
        return SUCESESS;
    }
    void traverse() const {
        for(int i = front; i < rear; ++i) {
            std::cout << elem[i] << ' ';
        }
        std::cout << std::endl;
    }
};