void shellSort(int* data, int n) {
    if(data == nullptr || n <= 0) return;
    int t, j, k = n / 2; // t为待插入数，j为待插入位置, k为增量
    while(k >= 1) {
        for(int i = k; i < n; i += k) {
            t = data[i];
            for(j = i; j > 0 && t < data[j - k]; j -= k) {
                data[j] = data[j - k];
            }
            data[j] = t;
        }
        k /= 2;
    }
    
}