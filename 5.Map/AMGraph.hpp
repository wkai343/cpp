#pragma once
#include <iostream>
#include <stack>
class DGraph {
protected:
    int vexNum, arcNum, size;
    char* vex;
    bool** arc;
    bool* visited;
public:
    DGraph(int s) :size(s), vexNum(0), arcNum(0) {
        vex = new char[size];
        arc = new bool*[size];
        for(int i = 0; i < size; ++i) {
            arc[i] = new bool[size];
        }
        visited = new bool[size];
        for(int i = 0; i < size; ++i) {
            for(int j = 0; j < size; ++j) {
                arc[i][j] = false;
            }
        }
        for(int i = 0; i < size; ++i) {
            visited[i] = false;
        }
    }
    DGraph(char* data, int n) :DGraph(n + 10) {
        vexNum += n;
        for(int i = 0; i < n; ++i) {
            vex[i] = data[i];
        }
    }
    ~DGraph() {
        delete[] vex;
        for(int i = 0; i < size; ++i) {
            delete[] arc[i];
        }
        delete[] arc;
        delete[] visited;
    }
    void clear() {
        for(int i = 0; i < vexNum; ++i) {
            for(int j = 0; j < vexNum; ++j) {
                arc[i][j] = false;
            }
        }
        vexNum = 0, arcNum = 0;
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
    int locate(char ch) const {
        for(int i = 0; i < vexNum; ++i) {
            if(vex[i] == ch) return i;
        }
        return -1;
    }
    int getID(int v) const {
        int count = 0;
        for(int i = 0; i < vexNum; ++i) {
            if(arc[i][v] == true) ++count;
        }
        return count;
    }
    int getOD(int v) const {
        int count = 0;
        for(int i = 0; i < vexNum; ++i) {
            if(arc[v][i] == true) ++count;
        }
        return count;
    }
    int getD(int v) const {
        return getID(v) + getOD(v);
    }
    void insertVex(char ch) {
        if(vexNum == size) {
            return;
        }
        vex[vexNum++] = ch;
    }
    void insertArc(int v1, int v2) {
        if(v1 < 0 || v1 >= vexNum || v2 < 0 || v2 >= vexNum || v1 == v2) return;
        arc[v1][v2] = true;
        ++arcNum;
    }
    void deleteVex(int v) {
        if(v < 0 || v >= vexNum) return;
        arcNum -= getD(v);
        for(int i = v; i < vexNum - 1; ++i) {
            for(int j = 0; j < v; ++j) {
                arc[i][j] = arc[i + 1][j];
                arc[j][i] = arc[j][i + 1];
            }
            for(int k = v; k < vexNum - 1; ++k) {
                arc[i][k] =arc[i + 1][k + 1];
            }
        }
        for(int i = 0; i < vexNum; ++i) {
            arc[vexNum - 1][i] = false;
            arc[i][vexNum - 1] = false;
        }
        vexNum -= 1;
    }
    void deleteArc(int v1, int v2) {
        if(v1 < 0 || v1 >= vexNum || v2 < 0 || v2 >= vexNum || v1 == v2) return;
        arc[v1][v2] = false;
        --arcNum;
    }
    void topSort() {
        std::stack<int> s;
        int ind[vexNum], temp;
        for(int i = 0; i < vexNum; ++i) {
            ind[i] = getID(i);
        }
        for(int i = 0; i < vexNum; ++i) {
            if(ind[i] == 0) s.push(i);
        }
        while(!s.empty()) {
            temp = s.top();
            s.pop();
            std::cout << vex[temp] << ' ';
            for(int i = 0; i < vexNum; ++i) {
                if(arc[temp][i] != 0) {
                    if(--ind[i] == 0) s.push(i);
                }
            }
        }
    }
};
class UGraph :public DGraph {
public:
    UGraph(int s) :DGraph(s) {}
    UGraph(char* data, int n) :DGraph(data, n) {}
    int getID(int v) const {
        return getOD(v);
    }
    int getOD(int v) const {
        int count;
        for(int i = 0; i < vexNum; ++i) {
            if(arc[v][i] == true) ++count;
        }
        return count;
    }
    int getD(int v) const {
        return getOD(v);
    }
    void insertArc(int v1, int v2) {
        arc[v1][v2] = true;
        arc[v2][v1] = true;
        ++arcNum;
    }
    void deleteArc(int v1, int v2) {
        arc[v1][v2] = false;
        arc[v2][v1] = false;
        --arcNum;
    }
    void DFS(int v) const {
        std::cout << vex[v] << ' ';
        visited[v] = true;
        for(int i = 0; i < vexNum; ++i) {
            if(!visited[i] && arc[v][i]) DFS(i);
        }
    }
};