void selectSort(int* data, int n) {
    if(data == nullptr || n <= 0) {
        return;
    }
    int t;
    for(int i = 0; i < n - 1; ++i) {
        for(int j = i + 1; j < n; ++j) {
            if(data[i] > data[j]) {
                t = data[j];
                data[j] = data[i], data[i] = t;
            }
        }
    }
}