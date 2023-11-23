#include "Heap.hpp"
#include <iostream>
int main() {
    int arr[] = {4, 6, 2, 1, 8 , 7, 9, 3, 5};
    MinHeap h(arr, 9);
    for(int i = 0; i < h.length; ++i) {
        std::cout << h.elem[i] << ' ';
    }
    std::cout << std::endl;
    return 0;
}