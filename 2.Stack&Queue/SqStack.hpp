#include"Status.h"
#include<iostream>
template<class DataType>
class SqStack {
private:
    DataType* elem;
    int top;
    int size;
public:
    SqStack(int s = 10) :top(0), size(s) {
        elem = new DataType[size];
    }
    SqStack(const DataType* data, int n) :top(n), size(n + 10) {
        elem = new DataType[size];
        for(int i = 0; i < n; ++i) {
            elem[i] = data[i];
        }
    }
    ~SqStack() {
        delete[] elem;
    }
    int getSize() const {
        return size;
    }
    int getLength() const {
        return top;
    }
    bool isEmpty() const {
        return top == 0;
    }
    bool isFull() const {
        return top ==size;
    }
    Status getTop(DataType& e) const {
        if(top == 0) return INVALID;
        e = elem[top - 1];
        return SUCESESS;
    }
    void clear() {
        top = 0;
    }
    Status push(const DataType& e) {
        if(top == size) return OVER_FLOW;
        elem[top++] = e;
        return SUCESESS;
    }
    Status pop() {
        if(top == 0) return UNDER_FLOW;
        --top;
        return SUCESESS;
    }
    Status pop(DataType& e) {
        if(top == 0) return UNDER_FLOW;
        e = elem[--top];
        return SUCESESS;
    }
    void traverse() const {
        std::cout << "top -> bottom : ";
        for(int i = top - 1; i >= 0; --i) {
            std::cout << elem[i] << ' ';
        }
        std::cout << std::endl;
    }
};