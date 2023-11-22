#include "Sort.h"
#include <iostream>
int main() {
    int arr[] = {4, 6, 2, 1, 8 , 7, 9, 3, 5};
    // insertSort(arr, 9);
    binInsertSort(arr, 9);
    for(int& e: arr) {
        std::cout << e << ' ';
    }
    return 0;
}