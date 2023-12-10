int partition1(int* data, int left, int right) {
    int l = left, r = right + 1, t;
    while(l < r) {
        --r;
        while(data[r] > data[left] && l < r) --r;
        ++l;
        while(data[l] <= data[left] && l < r) ++l;
        if(l < r)
            t = data[l], data[l] = data[r], data[r] = t;
    }
    t = data[left], data[left] = data[r], data[r] = t;
    return r;
}
int partition2(int* data, int left, int right) {
    int l = left, r = right;
    int base = data[left];
    while(l < r) {
        while(data[r] > base && l < r) --r;
        if(l < r) data[l++] = data[r];
        while(data[l] <= base && l < r) ++l;
        if(l < r) data[r--] = data[l];
        data[l] = base;
    }
    return l;
}
int partition3(int* data, int left, int right) {
    int l = left, p = left + 1, t;
    for(; p <= right; ++p) {
        if(data[p] <= data[left]) {
            ++l;
            if(l != p) t = data[l], data[l] = data[p], data[p] = t;
        }
    }
    t = data[left], data[left] = data[l], data[l] = t;
    return l;
}
void _quickSort(int* data, int left, int right) {
    if(left < right) {
        int i = partition3(data, left, right);
        _quickSort(data, left, i - 1);
        _quickSort(data, i + 1, right);
    }
}
void quickSort(int* data, int n) {
    _quickSort(data, 0, n - 1);
}