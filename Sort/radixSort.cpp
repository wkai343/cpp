#include <vector>
#include <cmath>
int getMaxRadix(int* data, int n) {
    int max = 0, count = 0;
    for(int i = 0; i < n; ++i) {
        count = 0;
        while(data[i] / (int)pow(10, count)) {
            ++count;
        }
        max = max >= count ? max : count;
    }
    return max;
}
void radixSort(int* data, int n) {
    std::vector<int> bucket[10];
    int count = getMaxRadix(data, n), radix;
    for(int i = 0; i < count; ++i) {
        for(int j = 0; j < n; ++j) {
            if((radix = data[j] % ((int)pow(10, i + 1)) / (int)pow(10, i))) {
                bucket[radix].push_back(data[j]);
            } else {
                bucket[0].push_back(data[j]);
            }
        }
        int t = 0;
        for(int k = 0; k < 10; ++k) {
            while(!bucket[k].empty()) {
                data[t++] = bucket[k].front();
                bucket[k].erase(bucket[k].begin());
            }
        }
    }
}