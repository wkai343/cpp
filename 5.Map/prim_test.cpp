#include <iostream>
class UNet {
protected:
    int vexNum, arcNum;
    int** arc;
    bool* visited;
public:
    friend int prim(const UNet&, int);
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
        if(arc[v1][v2] != -1) {
            if(w > arc[v1][v2])
                return;
        }
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
int prim(const UNet& n, int e) {
    int lowest[n.vexNum], closest[n.vexNum], min = -1, count = 0;
    for(int i = 0; i < n.vexNum; ++i) {
        lowest[i] = INT32_MAX;
        closest[i] = i;
    }
    for(int j = 0; j < n.vexNum; ++j) {
        if(n.arc[e][j] != -1) {
            lowest[j] = n.arc[e][j]; // 0表示已添加
            closest[j] = e;
        }
    }

    for(int k = 1; k < n.vexNum; ++k) {
        for(int m = 0; m < n.vexNum; ++m) {
            if(lowest[m] != 0) {
                if(min == -1) {
                    min = m;
                }
                if(lowest[m] < lowest[min]) min = m;
            }
        }
        count += lowest[min];
        for(int l = 0; l < n.vexNum; ++l) {
            if(n.arc[min][l] != -1 && min != l && n.arc[min][l] < lowest[l]) {
                lowest[l] = n.arc[min][l];
                closest[l] = min;
            }
        }
        lowest[min] = 0;
        min = -1;
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
        std::cout << prim(net, 0);
    } else {
        std::cout << "orz";
    }
    return 0;
}