#include <iostream>
class DisjointSet {
private:
    int* parent;
    int* sz;
public:
    DisjointSet(int n) {
        parent = new int[n];
        sz = new int[n];
        for(int i = 0; i < n; ++i) {
            parent[i] = i;
            sz[i] = 1;
        }
    }
    ~DisjointSet() {
        delete[] parent;
        delete[] sz;
    }
    int find(int i) {
        int p = i, t;
        while(p != parent[p]) {
            p = parent[p];
        }
        while(i != parent[i]) {
            t = parent[i], parent[i] = p, i = t;
        }
        return p;
    }
    bool judge(int a, int b) {
        return find(a) == find(b);
    }
    void merge(int a, int b) {
        int pa = find(a), pb = find(b), t;
        if(pa != pb) {
            if(sz[pa] < sz[pb]) {
                t = pa, pa = pb, pb = t;
            }
            parent[pb] = pa;
            sz[pa] += sz[pb];
        }
    }
};
int main() {
    int n, m, a, b;
    std::cin >> n >> m;
    DisjointSet s(n + 1);
    for(int i = 0; i < m; ++i) {
        std::cin >> n >> a >> b;
        if(n == 1) s.merge(a, b);
        else {
            if(s.judge(a, b)) std::cout << 'Y';
            else std::cout << 'N';
            std::cout << std::endl;
        }
    }
    return 0;
}