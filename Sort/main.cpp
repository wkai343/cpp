#include "Sort.h"
#include <iostream>
int main() {
    int arr[] = {4, 6, 2, 1, 8 , 7, 9, 3, 5};
    // bubbleSort(arr, 9);
    // selectSort(arr, 9);
    // bucketSort(arr, 9);
    insertSort(arr, 9);
    for(int& e: arr) {
        std::cout << e << ' ';
    }
    return 0;
}