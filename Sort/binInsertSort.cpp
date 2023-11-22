void binInsertSort(int* data, int n) {
    if(data == nullptr || n <= 0) return;
    int t; // t为待插入数
    for(int i = 1; i < n; ++i) {
        t = data[i];
        int left = 0, right = i - 1, mid = (left + right) / 2;
        while(left <= right) {
            if(t < data[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
            mid = (left + right) / 2;
        }
        for(int k = i; k > left; --k) {
            data[k] = data[k - 1];
        }
        data[left] = t;
    }
}