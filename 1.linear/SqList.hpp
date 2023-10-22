#include"Status.h"
template <class DataType>
class SqList {
private:
    DataType* elem;
    int size, length;
public:
    SqList(int s = 10) :size(s), length(0) {
        elem = new DataType[size];
    }
    SqList(const DataType* data, int s) :size(s + 10), length(s) {
        elem = new DataType[size];
        for (int i = 0;i < length;++i) {
            elem[i] = data[i];
        }
    }
    ~SqList() {
        delete[] elem;
    }
    int getSize() const {
        return size;
    }
    int getLength() const {
        return length;
    }
    bool isEmpty() const {
        return length == 0;
    }
    bool isFull() const {
        return length == size;
    }
    void clear() {
        length = 0;
    }
    Status insertElem(const DataType& e, int n) {
        if(n < 0 || n > length) return INVALID;
        if(length == size) {
            DataType* temp = new DataType[size + 10];
            int i = 0;
            for(; i < n; ++i) {
                temp[i] = elem[i];
            }
            temp[i++] = e;
            for(; i < length + 1; ++i) {
                temp[i] = elem[i - 1];
            }
            delete[] elem;
            elem = temp;
            size += 10;
        }
        else {
            for(int i = length; i > n; --i) {
            elem[i] = elem[i - 1];
        }
        elem[n] = e;
        }
        ++length;
        return SUCESESS;
    }
    Status insertElem(const DataType& e) {
        if(length == size) {
            DataType* temp = new DataType[size + 10];
            for(int i = 0; i < length; ++i) {
                temp[i] = elem[i];
            }
            temp[length] = e;
            delete[] elem;
            elem = temp;
            ++length;
            size += 10;
            return SUCESESS;
        }
        elem[length++] = e;
        return SUCESESS;
    }
    Status deleteN(int n) {
        if(length == 0) return UNDER_FLOW;
        if(n < 0 || n >= length) return INVALID;
        for(int i = n; i <length - 1; ++i) {
            elem[i] = elem[i + 1];
        }
        --length;
        return SUCESESS;
    }
    Status deleteElem(const DataType& e, int n = 0) {
        if (n >= length) return INVALID;
        int i = n, j = n;
        for (; j < length; ++i, ++j) {
            if (elem[j] == e && j < length - 1) {
                ++j;
            }
            elem[i] = elem[j];
        }
        length -= j - i;
        return i == j ? SUCESESS : NOT_FIND;
    }
    Status setElem(const DataType& e, int n) {
        if(n < 0 || n >= length) return INVALID;
        elem[n] = e;
        return SUCESESS;
    }
    int locateElem(const DataType& e) {
        for(int i = 0;i < length;++i) {
            if (elem[i] == e) {
                return i;
            }
        }
        return -1;
    }
    // void dedupe() {
    //     for (int i = 0; i < length; ++i) {
    //         deleteElem(elem[i], i + 1);
    //     }
    // }
    Status mergeList(const SqList& l) {
        if(l.length == 0) return SUCESESS;
        if(size - length >= l.length) {
            for(int i = 0; i < l.length; ++i) insertElem(l.elem[i]);
        }
        else {
            DataType* temp = new DataType(length + l.length + 10);
            for(int i = 0; i < length; ++i) {
                temp[i] = elem[i];
            }
            for(int j = 0; j < l.length; ++j) {
                temp[length + j] = l.elem[j];
            }
            delete[] elem;
            elem = temp;
            length += l.length;
            size += l.size + 10;
        }
        return SUCESESS;
    }
    template<class DataStruct>
    friend void sqTraverse(const DataStruct& d);
};