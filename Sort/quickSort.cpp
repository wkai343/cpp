void quickSort(int* data, int left, int right) {
    if(data == nullptr || left < 0 || left >= right) return;
    int t, l = left, r = right;
    while(left < right) {
        while(data[right] >= data[l] && left != right) right--;
        while(data[left] <= data[l] && left != right) left++;
        if(left != right) t = data[left], data[left] = data[right], data[right] = t;
    }
    t = data[l], data[l] = data[left], data[left] = t;
    quickSort(data, l, left - 1);
    quickSort(data, left + 1, r);
}
void quickSort(int* data, int n) {
    quickSort(data, 0, n - 1);
}