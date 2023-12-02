#include <iostream>
#include <queue>
#include <vector>
struct ArcNode {
    int vex, weight;
    ArcNode* next;
    ArcNode(int n = -1,int w = 1, ArcNode* p = nullptr) {
        vex = n;
        weight = w;
        next = p;
    }
};
struct VexNode {
    char ch;
    ArcNode* arc;
    VexNode(char c = '\0', ArcNode* p = nullptr) {
        ch = c;
        arc = p;
    }
};
class DNet {
protected:
    int vexNum, arcNum, size;
    VexNode* vex;
public:
    friend void dijkstra(const DNet&, int);
    friend void dijkstra1(const DNet&, int);
    DNet(int s) :vexNum(0), arcNum(0), size(0) {
        vex = new VexNode[s];
    }
    DNet(char* data, int n) :DNet(n + 10) {
        vexNum += n;
        for(int i = 0; i < n; ++i) {
            vex[i].ch = data[i];
        }
    }
    ~DNet() {
        clear();
        delete[] vex;
    }
    void clear() {
        vexNum = arcNum = 0;
        ArcNode* p, *q;
        for(int i = 0; i < size; ++i) {
            p = vex[i].arc;
            while(p != nullptr) {
                q = p->next;
                delete p;
                p = q;
            }
            vex[i].arc = nullptr;
        }
    }
    int getVexNum() const {
        return vexNum;
    }
    void insertVex(char ch) {
        if(vexNum == size) {
            return;
        }
        vex[vexNum++] = ch;
    }
    void insertArc(int v1, int v2, int w) {
        if(v1 < 0 || v1 >= vexNum || v2 < 0 || v2 >= vexNum || v1 == v2) return;
        ArcNode* p = vex[v1].arc;
        if(p) {
            while(p->next != nullptr) {
                if(v2 < p->next->vex) break;
                p = p->next;
            }
            ArcNode* q = new ArcNode(v2, w, p->next);
            p->next = q;
        } else {
            vex[v1].arc = new ArcNode(v2, w);
        }
        ++arcNum;
    }
    void getMinPath(int v) {
        std::pair<int, int> path[vexNum];
        ArcNode* p;
        for(int i = 0; i < vexNum; ++i) {
            path[i].first = INT32_MAX;
            path[i].second = -1;
        }
        std::queue<int> q;
        q.push(v);
        path[q.front()].first = 0;
        while(!q.empty()) {
            p = vex[q.front()].arc;
            while(p != nullptr) {
                if(path[q.front()].first + p->weight < path[p->vex].first) {
                    path[p->vex].first = path[q.front()].first + p->weight;
                    path[p->vex].second = q.front();
                    q.push(p->vex);
                }
                p = p->next;
            }
            q.pop();
        }
        int temp;
        for(int t = 0; t < vexNum; ++t) {
            if(path[t].first < INT32_MAX) {
                std::cout << "Weight: " << path[t].first << ", Path: ";
            } else {
                continue;
            }
            temp = t;
            while(path[temp].second != -1) {
                std::cout << '(' << temp << ", " << char('A'+temp) << ')' << " <- ";
                temp = path[temp].second;
            }
            std::cout << temp <<std::endl;
        }
    }
};
int main() {
    int n, m, s;
    return 0;
}