void cocktailSort(int* data, int n) {
    if(data == nullptr || n <= 0) return;
    bool sorted = false;
    int t;
    for(int i = 0; i < n - 1 && !sorted; i += 2) {
        sorted = true;
        for(int j = i / 2; j < n - 1 - i / 2; ++j) {
            if (data[j] > data[j + 1]) {
                t = data[j + 1], data[j + 1] = data[j], data[j] = t;
                sorted = false;
            }
        }
        if (sorted) {
            break;
        } else {
            sorted = true;
        }
        for(int k = n - i / 2 - 1; k > i / 2; --k) {
            if(data[k] < data[k - 1]) {
                t = data[k - 1], data[k - 1] = data[k], data[k] = t;
                sorted = false;
            }
        }
    }
}