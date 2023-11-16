#include <iostream>
#include <queue>
struct ArcNode {
    int vex;
    ArcNode* next;
    ArcNode(int n = -1, ArcNode* p = nullptr) {
        vex = n;
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
class DGraph {
protected:
    int vexNum, arcNum, size;
    VexNode* vex;
    bool* visited;
public:
    DGraph(int s) :vexNum(0), arcNum(0), size(0) {
        vex = new VexNode[s];
        visited = new bool[size];
        for(int i = 0; i < size; ++i) {
            visited[i] = false;
        }
    }
    DGraph(char* data, int n) :DGraph(n + 10) {
        vexNum += n;
        for(int i = 0; i < n; ++i) {
            vex[i].ch = data[i];
        }
    }
    ~DGraph() {
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
    void clearVisited() {
        for(int i = 0; i < vexNum; ++i) {
            visited[i] = false;
        }
    }
    bool isEmpty() const {
        return vexNum == 0;
    }
    int getSize() const {
        return size;
    }
    int getVexNum() const {
        return vexNum;
    }
    int getArcNum() const {
        return arcNum;
    }
    int getIArcNum(int v) const {
        ArcNode* p;
        int count = 0;
        for(int i = 0; i < vexNum; ++i) {
            p = vex[i].arc;
            while(p != nullptr) {
                if(p->vex == v) ++count;
                p = p->next;
            }
        }
        return count;
    }
    int getOArcNum(int v) const {
        ArcNode* p = vex[v].arc;
        int count;
        while(p != nullptr) {
            ++count;
            p = p->next;
        }
        return count;
    }
    int getArcNum(int v) const {
        return getIArcNum(v) + getOArcNum(v);
    }
    void insertVex(char ch) {
        if(vexNum == size) {
            return;
        }
        vex[vexNum++] = ch;
    }
    void insertArc(int v1, int v2) {
        if(v1 < 0 || v1 >= vexNum || v2 < 0 || v2 >= vexNum || v1 == v2) return;
        ArcNode* p = vex[v1].arc;
        if(p) {
            while(p->next != nullptr) {
                if(v2 < p->next->vex) break;
                p = p->next;
            }
            ArcNode* q = new ArcNode(v2, p->next);
            p->next = q;
        } else {
            vex[v1].arc = new ArcNode(v2);
        }
        ++arcNum;
    }
    void deleteVex(int v) {
        if(v < 0 || v >= vexNum) return;
        ArcNode* p;
        for(int i = 0; i < vexNum; ++i) {
            if(i == v) continue;
            deleteArc(i, v);
            deleteArc(v, i);
            p = vex[i].arc;
            while(p != nullptr) {
                if(p->vex > v) --(p->vex);
                p = p->next;
            }
        }
        for(int i = v; i < vexNum - 1; ++i) {
            vex[i].ch = vex[i + 1].ch;
            vex[i].arc = vex[i + 1].arc;
        }
        vexNum -= 1;
    }
    void deleteArc(int v1, int v2) {
        if(v1 < 0 || v1 >= vexNum || v2 < 0 || v2 >= vexNum || v1 == v2) return;
        ArcNode* p = vex[v1].arc;
        while(p->next != nullptr) {
            if(v2 == p->next->vex) {
                ArcNode* q = p->next;
                p->next = q->next;
                delete q;
                --arcNum;
            }
            p = p->next;
        }
    }
    void DFS(int v) const {
        std::cout << vex[v].ch << ' ';
        visited[v] = true;
        ArcNode* p = vex[v].arc;
        while(p != nullptr) {
            if(!visited[p->vex]) DFS(p->vex);
            p = p->next;
        }
    }
    int DFS() {
        clearVisited();
        int count = 0;
        for(int i = 0; i < vexNum; ++i) {
            if(!visited[i]) {
                DFS(i);
                ++count;
            }
        }
        return count;
    }
    void BFS(int v) const {
        std::queue<int> q;
        ArcNode* p;
        q.push(v);
        visited[q.front()] = true;
        while(!q.empty()) {
            std::cout << vex[q.front()].ch << ' ';
            p = vex[q.front()].arc;
            q.pop();
            while(p != nullptr) {
                if(!visited[p->vex]) {
                    q.push(p->vex);
                    visited[p->vex] = true;
                }
                p = p->next;
            }
        }
    }
    int BFS() {
        clearVisited();
        int count = 0;
        for(int i = 0; i < vexNum; ++i) {
            if(!visited[i]) {
                BFS(i);
                ++count;
            }
        }
        return count;
    }
};
class UGraph :public DGraph {
public:
    UGraph(int s) :DGraph(s) {}
    UGraph(char* data, int n) :DGraph(data, n) {}
    int getIArcNum(int v) const {
        return getOArcNum(v);
    }
    int getOArcNum(int v) const {
        ArcNode* p = vex[v].arc;
        int count;
        while(p != nullptr) {
            ++count;
            p = p->next;
        }
        return count;
    }
    int getArcNum(int v) const {
        return getOArcNum(v);
    }
    void insertArc(int v1, int v2) {
        DGraph::insertArc(v1, v2);
        DGraph::insertArc(v2, v1);
        --arcNum;
    }
    void deleteArc(int v1, int v2) {
        DGraph::deleteArc(v1, v2);
        DGraph::deleteArc(v2, v1);
        ++arcNum;
    }
    void deleteVex(int v) {
        if(v < 0 || v >= vexNum) return;
        ArcNode* p;
        p = vex[v].arc;
        while(p != nullptr) {
            deleteArc(p->vex, v); 
            p = p->next;
        }
        for(int i = 0; i < vexNum; ++i) {
            if(i == v) continue;
            p = vex[i].arc;
            while(p != nullptr) {
                if(p->vex > v) --(p->vex);
                p = p->next;
            }
        }
        for(int i = v; i < vexNum - 1; ++i) {
            vex[i].ch = vex[i + 1].ch;
            vex[i].arc = vex[i + 1].arc;
        }
        vexNum -= 1;
    }
};