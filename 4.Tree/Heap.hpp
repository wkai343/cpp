class MinHeap {
private:
    int* elem, size, length;
    void siftUp(int i) {
        int t;
        while((i - 1) / 2 >= 0) {
            if(elem[i] < elem[(i - 1) / 2]) {
                t = elem[(i - 1) / 2], elem[(i - 1) / 2] = elem[i], elem[i] = t;
            } else break;
            i = (i - 1) / 2;
        }
    }
    void siftDown(int i) {
        int min, t;
        while(2 * i + 1 < length) {
            min = 2 * i + 2 < length ? (elem[2 * i + 1] < elem[2 * i + 2] ? 2 * i + 1 : 2 * i + 2) : 2 * i + 1;
            if(elem[i] > elem[min]) {
                t = elem[i], elem[i] = elem[min], elem[min] = t;
            } else break;
            i = min;
        }
    }
    friend int main();
public:
    MinHeap(int s) :size(s), length(0) {
        elem = new int[size];
    }
    MinHeap(int* data, int n) :size(n + 10), length(n) {
        elem = new int[size];
        for(int i = 0; i < n; ++i) {
            elem[i] = data[i];
        }
        for(int i = (length - 2) / 2; i >= 0; --i) {
            siftDown(i);
        }
    }
    ~MinHeap() {
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
    int getMin() const {
        return elem[0];
    }
    void insertElem(int e) {
        if(length == size) return;
        elem[length++] = e;
        siftUp(length - 1);
    }
    void deleteMin() {
        if(!length) return;
        --length;
        elem[0] = elem[length];
        siftDown(0);
    }
};
class MaxHeap {
    private:
    int* elem, size, length;
    void siftUp(int i) {
        int t;
        while((i - 1) / 2 >= 0) {
            if(elem[i] > elem[(i - 1) / 2]) {
                t = elem[(i - 1) / 2], elem[(i - 1) / 2] = elem[i], elem[i] = t;
            } else break;
            i = (i - 1) / 2;
        }
    }
    void siftDown(int i) {
        int max, t;
        while(2 * i + 1 < length) {
            max = 2 * i + 2 < length ? (elem[2 * i + 1] > elem[2 * i + 2] ? 2 * i + 1 : 2 * i + 2) : 2 * i + 1;
            if(elem[i] < elem[max]) {
                t = elem[i], elem[i] = elem[max], elem[max] = t;
            } else break;
            i = max;
        }
    }
    friend int main();
public:
    MaxHeap(int s) :size(s), length(0) {
        elem = new int[size];
    }
    MaxHeap(int* data, int n) :size(n + 10), length(n) {
        elem = new int[size];
        for(int i = 0; i < n; ++i) {
            elem[i] = data[i];
        }
        for(int i = (length - 2) / 2; i >= 0; --i) {
            siftDown(i);
        }
    }
    ~MaxHeap() {
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
    int getMax() const {
        return elem[0];
    }
    void insertElem(int e) {
        if(length == size) return;
        elem[length++] = e;
        siftUp(length - 1);
    }
    void deleteMax() {
        if(!length) return;
        --length;
        elem[0] = elem[length];
        siftDown(0);
    }
};
inline void siftUp(int* data, int i) {
    int t;
    while((i - 1) / 2 >= 0) {
        if(data[i] > data[(i - 1) / 2]) {
            t = data[(i - 1) / 2], data[(i - 1) / 2] = data[i], data[i] = t;
        } else break;
        i = (i - 1) / 2;
    }
}
inline void siftDown(int* data, int i, int length) {
    int max, t;
    while(2 * i + 1 < length) {
        max = 2 * i + 2 < length ? (data[2 * i + 1] > data[2 * i + 2] ? 2 * i + 1 : 2 * i + 2) : 2 * i + 1;
        if(data[i] < data[max]) {
            t = data[i], data[i] = data[max], data[max] = t;
        } else break;
        i = max;
    }
}
inline void createHeap(int* data, int n) {
    for(int i = (n - 2) / 2; i >= 0; --i) {
            siftDown(data, i, n);
    }
}
inline void deleteMax(int* data, int length) {
        if(!length) return;
        data[0] = data[length - 1];
        siftDown(data, 0, length - 1);
    }