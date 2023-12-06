class DisjointSet {
private:
    int* parent;
    int* rnk;
    int* sz;
    int n;
public:
    DisjointSet(int n): n(n) {
        parent = new int[n];
        rnk = new int[n];
        sz = new int[n];
        for(int i = 0; i < n; ++i) {
            parent[i] = i;
            rnk[i] = 0;
            sz[i] = 1;
        }
    }
    ~DisjointSet() {
        delete[] parent;
        delete[] rnk;
        delete[] sz;
    }
    // 查找根，递归
    int find1(int i) {
        if(i != parent[i]) {
            parent[i] = find1(parent[i]);
        }
        return parent[i];
    }
    //查找根，非递归
    int find2(int i) {
        int p = i, t;
        while(p != parent[p]) {
            p = parent[p];
        }
        while(i != parent[i]) {
            t = parent[i], parent[i] = p, i = t;
        }
        return p;
    }
    bool inSameSet(int a, int b) {
        return find2(a) == find2(b);
    }
    // 简单合并
    void merge1(int a, int b) {
        int pa = find1(a), pb = find1(b);
        if(pa != pb) {
            parent[pa] = pb;
            parent[a] = b;
        }
    }
    // 按秩合并
    void merge2(int a, int b) {
        int pa = find2(a), pb =find2(b), t;
        if(pa != pb) {
            if(rnk[pa] < rnk[pb]) {
                t = pa, pa = pb, pb = t;
            }
            parent[pb] = pa;
            if(rnk[pa] == rnk[pb]) ++rnk[pb];
        }
    }
    // 启发式合并
    void merge3(int a, int b) {
        int pa = parent[a], pb = parent[b], t;
        if(pa != pb) {
            if(sz[pa] < sz[pb]) {
                t = pa, pa = pb, pb = t;
            }
            parent[pb] = pa;
            sz[pa] += sz[pb];
        }
    }
    // 计集合数
    int getSetNum() {
        int count = 0;
        for(int i = 0; i < n; ++i) {
            if(parent[i] == i) ++count;
        }
        return count;
    }
};