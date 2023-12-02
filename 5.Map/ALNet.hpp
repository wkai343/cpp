#pragma once
#include <iostream>
#include <queue>
#include <stack>
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
    DNet(int s): size(s), vexNum(0), arcNum(0) {
        vex = new VexNode[s];
    }
    DNet(char* data, int n): DNet(n + 10) {
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
    void insertArc(int v1, int v2, int w = 1) {
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
    void setWeight(int v1, int v2, int w) {
        if(v1 < 0 || v1 >= vexNum || v2 < 0 || v2 >= vexNum || v1 == v2) return;
        ArcNode* p = vex[v1].arc;
        while(p != nullptr) {
            if(p->vex == v2) p->weight = w;
            p = p->next;
        }
    }
    // 拓扑排序
    bool topSort() {
        int ind[vexNum], temp;
        std::stack<int> s;
        ArcNode* p;
        for(int i = 0; i < vexNum; ++i) {
            ind[i] = 0;
        }
        for(int i = 0; i < vexNum; ++i) {
            p = vex[i].arc;
            while(p != nullptr) {
                ++ind[p->vex];
                p = p->next;
            }
        }
        for(int i = 0; i < vexNum; ++i) {
            if(ind[i] == 0) s.push(i);
        }
        while(!s.empty()) {
            temp = s.top();
            s.pop();
            std::cout << vex[temp].ch << ' ';
            p = vex[temp].arc;
            while(p != nullptr) {
                if(--ind[p->vex] == 0) s.push(p->vex);
                p = p->next;
            }
        }

        for(int& e: ind) {
            if(e != 0) return true;
        }
        return false;
    }
    // BFS求最短路径
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
class UNet :public DNet {
private:
    UNet(int s) :DNet(s) {}
    UNet(char* data, int n) :DNet(data, n) {}
public:
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
    void insertArc(int v1, int v2, int w) {
        DNet::insertArc(v1, v2, w);
        DNet::insertArc(v2, v1, w);
        --arcNum;
    }
    void deleteArc(int v1, int v2) {
        DNet::deleteArc(v1, v2);
        DNet::deleteArc(v2, v1);
        ++arcNum;
    }
    void setWeight(int v1, int v2, int w) {
        DNet::setWeight(v1, v2, w);
        DNet::setWeight(v2, v1, w);
    }
};