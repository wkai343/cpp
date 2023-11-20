void bubbleSort(int* data, int n) {
    if(data == nullptr || n <= 0) {
        return;
    }
    bool sorted = false;
    int t;
    for(int i = 0; i < n - 1 && !sorted; ++i) {
        sorted = true;
        for(int j = 0; j < n - 1 - i; ++j) {
            if (data[j] > data[j + 1]) {
                t = data[j + 1], data[j + 1] = data[j], data[j] = t;
                sorted = false;
            }
        }
    }
}