#include "../4.Tree/Heap.hpp"
void heapSort1(int* data, int n) {
    MinHeap h(data, n);
    for(int i = 0; i < n; ++i) {
        data[i] = h.getMin();
        h.deleteMin();
    }
}
void heapSort2(int* data, int n) {
    MaxHeap h(data, n);
    for(int i = n - 1; i >= 0; --i) {
        data[i] = h.getMax();
        h.deleteMax();
    }
}
void heapSort(int* data, int n) {
    int t;
    createHeap(data, n);
    for(int i = 0; i < n - 1; ++i) {
        t = data[0];
        deleteMax(data, n - i);
        data[n - 1 - i] = t;
    }
}