void insertSort(int* data, int n) {
    if(data == nullptr || n <= 0) {
        return;
    }
    int t, j; // t为待插入数，j为待插入位置
    for(int i = 1; i < n; ++i) {
        int t = data[i];
        for(j = i; j > 0 && t < data[j - 1]; --j) {
            data[j] = data[j - 1];
        }
        data[j] = t;
    }
}