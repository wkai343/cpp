#include "AMNet.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
struct Edge {
    int u, v, w;
    Edge(int u, int v, int w): u(u), v(v), w(w) {}
    bool operator<(const Edge& e) {
        return w < e.w;
    }
};
void kruskal(const UNet& n) {
    int vSet[n.getVexNum()];
    std::vector<Edge> e;
    for(int i = 0; i < n.getVexNum() - 1; ++i) {
        for(int j = i + 1; j < n.getVexNum(); ++j) {
            if(n.arc[i][j] != -1) e.emplace_back(Edge(i, j, n.arc[i][j]));
        }
        vSet[i] = i;
    }
    std::sort(e.begin(), e.end());
    int p = 0; // 边列表指针
    for(int i = 1; i < n.getVexNum(); ++i, ++p) {
        if(vSet[e[p].u] != vSet[e[p].v]) {
            std::cout << "权值为" << e[p].w << "的边: (" << e[p].u << ',' << e[p].v << ")\n";
            vSet[e[p].v] = e[p].u;
        } else --i;
        //统一编号
        for(int j = 0; j < n.getVexNum(); ++j) {
            if(vSet[j] == vSet[e[p].v]) vSet[j] = vSet[e[p].u];
        }
    }
}