#include"Status.h"
#include<iostream>
template<class DataType>
class SharedStack {
private:
    DataType* elem;
    int top1;
    int top2;
    int size;
public:
    SharedStack(int s) :top1(0), top2(s - 1), size(s) {
        elem = new DataType[size];
    }
    ~SharedStack() {
        delete[] elem;
    }
    int getSize() const {
        return size;
    }
    int getLength(int i) const {
        if(i == 1) return top1;
        if(i == 2) return size - 1 - top2;
    }
    int getLength() const {
        return top1 + size - 1 - top2;
    }
    bool isEmpty(int i) const {
        if(i == 1) return top1 == 0;
        if(i == 2) return top2 == size - 1;
    }
    bool isEmpty() const {
        return top1 == 0 && top2 == size - 1;
    }
    bool isFull() const {
        return top1 - 1 == top2;
    }
    Status getTop(int i, DataType& e) const {
        if(i == 1) {
            if(top1 == 0) return UNDER_FLOW;
            e = elem[top1 - 1];
        }
        else if(i == 2) {
            if(top2 == size - 1) return UNDER_FLOW;
            e = elem[top2 + 1];
        }
        else return INVALID;
        return SUCESESS;
    }
    void clear() {
        top1 = 0, top2 = size - 1;
    }
    Status push(int i, const DataType& e) {
        if (top1 - 1 ==top2) return OVER_FLOW;
        if (i == 1) elem[top1++] = e;
        else if (i == 2) elem[top2--] = e;
        else return INVALID;
        return SUCESESS;
    }
    Status pop(int i, DataType& e) {
        if (i == 1) {
            if (top1 == 0) return UNDER_FLOW;
            e = elem[--top1];
        }
        else if (i == 2) {
            if (top2 == size - 1) return UNDER_FLOW;
            e = elem[++top2];
        }
        else return INVALID;
        return SUCESESS;
    }
    Status pop(int i) {
        if (i == 1) {
            if (top1 == 0) return UNDER_FLOW;
            --top1;
        }
        else if (i == 2) {
            if (top2 == size - 1) return UNDER_FLOW;
            ++top2;
        }
        else return INVALID;
        return SUCESESS;
    }
    void traverse(int i) const {
        if (i == 1) {
            if (top1 == 0) return;
            for (int j = top1 - 1; j >= 0; --j) {
                std::cout << elem[j] << ' ';
            }
        }
        else if (i == 2) {
            if (top2 == size - 1) return;
            for (int j = top2 + 1; j < size; ++j) {
                std::cout << elem[j] << ' ';
            }
        }
        else return;
    }
};