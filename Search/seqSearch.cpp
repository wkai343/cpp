#include <vector>
int seqSearch(int* data, int n, int key) {
    int i = 0;
    while(i < n && data[i++] != key);
    return i <= n ? i - 1 : -1;
}
int seqSearch(std::vector<int>& v, int key) {
    int i = 0;
    v.push_back(key);
    while(v[i++] != key);
    return i - 1 < v.size() - 1 ? i - 1 : -1;
}