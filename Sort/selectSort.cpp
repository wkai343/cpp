void selectSort(int* data, int n) {
    if(data == nullptr || n <= 0) return;
    int t, min;
    for(int i = 0; i < n - 1; ++i) {
        min = i;
        for(int j = i + 1; j < n; ++j) {
            if(data[j] < data[min]) {
                min = j;
            }
        }
        if(i != min) t = data[min], data[min] = data[i], data[i] = t;
    }
}