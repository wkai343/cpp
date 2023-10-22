#include"Status.h"
#include<iostream> 
template<class DataType>
class cirQueue {
private:
    DataType* elem;
    int front, length, size;
public:
    cirQueue(int s = 10) : size(s), length(0),front(-1) {
        elem = new DataType[size];
    }
    ~cirQueue() {
        delete[] elem;
    }
    bool isEmpty() {
        return length == 0;
    }
    bool isFull() {
        return length == size;
    }
    Status enQueue(const DataType& e) {
        if(isFull()) return OVER_FLOW;
        ++length;
        elem[(front + length - 1) % size] = e;
        return SUCESESS;
    }
    Status deQueue(DataType& e) {
        if(isEmpty()) return UNDER_FLOW;
        --length;
        e = elem[front];
        front = (front + 1) % size;
        return SUCESESS;
    }
    void traverse() {
        for(int i = 0; i < length; ++i) {
            std::cout << elem[(front + i) % size] << ' ';
        }
    }
};