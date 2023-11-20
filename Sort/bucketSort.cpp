void bucketSort(int* data, int n) {
    if(data == nullptr || n <= 0) {
        return;
    }
    int max = data[0], count = 0;
    for(int i = 1; i < n; ++i) {
        if(data[i] > max) max = data[i];
    }
    max += 1;
    int bucket[max];
    for(int i = 0; i < max; ++i) {
        bucket[i] = 0;
    }
    for(int i = 0; i < n; ++i) {
        ++bucket[data[i]];
    }
    for(int i = 0; i < max; ++i) {
        while(bucket[i]--) {
            data[count++] = i;
        }
    }
}