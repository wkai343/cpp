#include <vector>
#include <algorithm>
void bucketSort(int* data, int n) {
    int max = data[0], t = 0;
    for(int i = 1; i < n; ++i) {
        if(data[i] > max) max = data[i];
    }
    std::vector<int> bucket[max / 10 + 1];
    for(int i = 0; i < n; ++i) {
        bucket[data[i] / 10].push_back(data[i]);
    }
    for(int i = 0; i < max / 10 + 1; ++i) {
        std::sort(bucket[i].begin(), bucket[i].end());
    }
    for(int i = 0; i < max / 10 + 1; ++i) {
        while(!bucket[i].empty()) {
            data[t++] = bucket[i].front();
            bucket[i].erase(bucket[i].begin());
        }
    }
}