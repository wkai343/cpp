#include "AMNet.hpp"
class DisjointSet {
private:
    int* parent;
    int* sz;
public:
    friend bool isConnect(const UNet&);
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
    void merge(int a, int b) {
        int pa = parent[a], pb = parent[b], t;
        if(pa != pb) {
            if(sz[pa] < sz[pb]) {
                t = pa, pa = pb, pb = t;
            }
            parent[pb] = pa;
            sz[pa] += sz[pb];
        }
    }
};
bool isConnect(const UNet& net) {
    DisjointSet set(net.getVexNum());
    for(int i = 0; i < net.getVexNum(); ++i) {
        for(int j = 0; j < net.getVexNum(); ++j) {
            if(i != j && net.arc[i][j] != INT32_MAX) {
                set.merge(i, j);
            }
        }
    }
    if(set.sz[set.find(0)] == net.vexNum) return true;
    return false;
}