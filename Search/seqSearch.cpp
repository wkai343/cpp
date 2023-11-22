int seqSearch(int* data, int n, int key) {
    int i = 0;
    while(i < n && data[i++] != key);
    return i <= n ? i - 1 : -1;
}