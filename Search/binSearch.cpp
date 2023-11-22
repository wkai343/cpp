int binSearch(int* data, int n, int key) {
    int left = 0, right = n - 1;
    int mid = (left + right) / 2;
    while(left <= right) {
        if(data[mid] == key) return mid;
        else if(data[mid] > key) right = mid - 1;
        else if(data[mid] < key) left = mid + 1;
        mid = (left + right) / 2;
    }
    return -1;
}