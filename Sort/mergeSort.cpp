void merge(int* data, int a, int b, int rear2) {
    int temp[rear2 + 1 - a], rear1 = b - 1, i = 0, beg = a;
    while(a <= rear1 && b <= rear2) {
        if(data[a] <= data[b]) {
            temp[i++] = data[a++];
        } else {
            temp[i++] = data[b++];
        }
    }
    while(a <= rear1) {
        temp[i++] = data[a++];
    }
    while(b <= rear2) {
        temp[i++] = data[b++];
    }
    for(i = 0; i < rear2 + 1 - beg; ++i) {
        data[beg + i] = temp[i];
    }
}
void mergeSort(int* data, int n) {
    if(data == nullptr || n <= 0) return;
    for(int len = 1, i; len < n; len *= 2) {
        for(i = 0; i + 2 * len < n; i += 2 * len) {
            merge(data, i, i + len, i + 2 * len - 1);
        }
        if(i + len < n) {
            merge(data, i, i + len, n - 1);
        }
    }
}
void _mergeSort(int* data, int l, int r) {
    if(l < r - 1) {
        int i = (l + r) / 2;
        _mergeSort(data, l, i);
        _mergeSort(data, i + 1, r);
        merge(data, l, i + 1, r);
    }
    
}
void mergeSort2(int* data, int n) {
    if(data == nullptr || n <= 0) return;
    _mergeSort(data, 0, n - 1);
}