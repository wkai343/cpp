#include <iostream>
#include <algorithm>
#include <vector>
class UNet {
protected:
    int vexNum, arcNum;
    int** arc;
    bool* visited;
public:
    friend int kruskal(const UNet&);
    UNet(int n) :vexNum(n), arcNum(0) {
        arc = new int*[vexNum];
        visited = new bool[vexNum];
        for(int i = 0; i < vexNum; ++i) {
            arc[i] = new int[vexNum];
        }
        for(int i = 0; i < vexNum; ++i) {
            for(int j = 0; j < vexNum; ++j) {
                if(i == j) arc[i][j] = 0;
                else arc[i][j] = -1;
            }
        }
        for(int i = 0; i < vexNum; ++i) {
            visited[i] = false;
        }
    }
    ~UNet() {
        for(int i = 0; i < vexNum; ++i) {
            delete[] arc[i];
        }
        delete[] arc;
        delete[] visited;
    }
    void insertArc(int v1, int v2, int w) {
        if(v1 < 0 || v1 >= vexNum || v2 < 0 || v2 >= vexNum || v1 == v2) return;
        arc[v1][v2] = w;
        arc[v2][v1] = w;
        ++arcNum;
    }
    void DFS(int v) {
        visited[v] = true;
        for(int i = 0; i < vexNum; ++i) {
            if(!visited[i] && arc[v][i] != 0 && arc[v][i] != -1) DFS(i);
        }
    }
    bool isConnected() {
        DFS(0);
        for(int i = 0; i < vexNum; ++i) {
            if(!visited[i]) return false;
            visited[i] = false;
        }
        return true;
    }
};
struct Edge {
    int u, v, w;
    Edge(int u, int v, int w): u(u), v(v), w(w) {}
    bool operator<(const Edge& e) {
        return w < e.w;
    }
};
int kruskal(const UNet& n) {
    int vSet[n.vexNum], count = 0;
    std::vector<Edge> e;
    for(int i = 0; i < n.vexNum; ++i) {
        for(int j = i + 1; j < n.vexNum; ++j) {
            if(n.arc[i][j] != -1) e.emplace_back(Edge(i, j, n.arc[i][j]));
        }
        vSet[i] = i;
    }
    std::sort(e.begin(), e.end());
    int p = 0; // 边列表指针
    int t;
    for(int i = 1; i < n.vexNum; ++i) {
        while(vSet[e[p].u] == vSet[e[p].v]) ++p;
        count += e[p].w;
        //统一编号
        t = vSet[e[p].v];
        for(int j = 0; j < n.vexNum; ++j) {
            if(vSet[j] == t) vSet[j] = vSet[e[p].u];
        }
    }
    return count;
}
int main() {
    int n, m;
    std::cin >> n >> m;
    UNet net(n);
    int x, y, z;
    for(int i = 0; i < m; ++i) {
        std::cin >> x >> y >> z;
        net.insertArc(x - 1, y - 1, z);
    }
    if(net.isConnected()) {
        std::cout << kruskal(net);
    } else {
        std::cout << "orz";
    }
    return 0;
}