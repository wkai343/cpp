#include <vector>
#include <list>
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
            radix = data[j] % ((int)pow(10, i + 1)) / (int)pow(10, i);
            bucket[radix].push_back(data[j]);
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
int getDigits(int* data, int n, int r) {
    int max = 0, count = 0;
    for(int i = 0; i < n; ++i) {
        count = 0;
        while(data[i] / (int)pow(r, count)) {
            ++count;
        }
        max = max >= count ? max : count;
    }
    return max;
}
void radixSort(int* data, int n, int r) {
    std::list<int> l(n);
    std::list<int>::iterator it = l.begin();
    int digits = getDigits(data, n, r), radix;
    std::list<int> bucket[r];
    for(int i = 0; i < n; ++i) {
        *it = data[i];
        it++;
    }
    for(int i = 0; i < digits; ++i) {
        for(it = l.begin(); it != l.end();) {
            radix = *it % (int)pow(r, i + 1) / (int)pow(r, i);
            std::list<int>::iterator t = it++;
            bucket[radix].splice(bucket[radix].end(), l, t);
        }
        for(int k = 0; k < r; ++k) {
            l.splice(l.end(), bucket[k]);
        }
    }
    it = l.begin();
    for(int i = 0; i < n; ++i) {
        data[i] = *it;
        it++;
    }
}