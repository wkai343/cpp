#include "Sort.h"
#include <algorithm>
#include <iostream>
int main() {
    int arr[] = {4, 6, 2, 1, 8 , 7, 9, 3, 5};
    radixSort(arr, 9);
    for(int& e: arr) {
        std::cout << e << ' ';
    }
    return 0;
}