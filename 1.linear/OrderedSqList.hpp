#include"Status.h"
template<class DataType>
class OrderedList {
private:
    DataType *elem;
    int size, length;
public:
    OrderedList(int s = 10) :size(s),length(0) {
        elem = new DataType[size];
    };
    OrderedList(const DataType *data, int s) :size(s + 10),length(0) {
        elem = new DataType[size];
        for(int i = 0; i < s; ++i) {
            insertElem(data[i]);
        }
    };
    ~OrderedList() {
        delete[] elem;
    };
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
    Status insertElem(const DataType &e) {
        if(length == size) {
            OrderedList temp(size + 1);
            for(int i = 0; i < size; ++i) {
                temp.insertElem(elem[i]);
            }
            temp.insertElem(e);
            delete[] elem;
            elem = new DataType(size + 10);
            for(int i = 0; i < length + 1; ++i) {
                elem[i] = temp.elem[i];
            }
            size += 10;
        }else if(length == 0) {
            elem[0] = e;
        }else {
            int i = 0;
            for(; i < length; ++i) {
                if(e <= elem[i]) break;
            }
            if(i == length) {
                elem[i] = e;
                ++length;
                return SUCESESS;
            }
            for(int j = length; j > i; --j) {
                elem[j] = elem[j - 1];
            }
            elem[i] = e;
        }
        ++length;
        return SUCESESS;
    };
    Status deleteElem(const DataType &e) {
        if(length == 0) return UNDER_FLOW;
        int i = 0, j = 0;
        for(; i < length; ++i) {
            if(e == elem[i]) break;
        }
        if(i == length) return NOT_FIND;
        for(; i < length && elem[i] == e; ++i) {
            ++j;
        }
        int k = i;
        i = i - j;
        for(; k < length; ++i, ++k)
        {
            elem[i] = elem[k];
        }
        length = length - j;
        return SUCESESS;
    }
    Status deleteElems(DataType s, DataType t) {
        if(length == 0) return UNDER_FLOW;
        if(s >= t) return INVALID;
        int i = 0, j = 0;
        for(; i < length; ++i) {
            if (s <= elem[i]) break;
        }
        if (i == length) return NOT_FIND;
        for(; i < length && elem[i] <= t; ++i) {
            ++j;
        }
        int k = i;
        i = i - j;
        for(; k < length; ++i, ++k) {
            elem[i] = elem[k];
        }
        length = length - j;
        return SUCESESS;
    }
    Status mergeList(const OrderedList &l) {
        if(l.size == 0) return SUCESESS;
        if(size - length >= l.length) {
            for(int i = 0; i < l.length; ++i) insertElem(l.elem[i]);
        } else {
            OrderedList temp(length + l.length);
            int j = 0, k = 0;
            for(int i = 0; i < temp.size; ++i) {
                if(elem[j] <= l.elem[k] && j < length) {
                    temp.elem[i] = elem[j];
                    ++j;
                }else {
                    temp.elem[i] = l.elem[k];
                    ++k;
                }
            }
            delete[] elem;
            elem = new DataType[size + l.size + 10];
            for(int i = 0; i < temp.size; ++i) {
                elem[i] = temp.elem[i];
            }
            length += l.length;
            size += l.size + 10;
        }
        return SUCESESS;
    }
    template<class DataStruct>
    friend void sqTraverse(const DataStruct& d);
};