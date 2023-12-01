#pragma once
#include <iostream>
class DNet {
protected:
    int vexNum, arcNum, size;
    char* vex;
    int** arc;
    bool* visited;
public:
    DNet(int s) :size(s), vexNum(0), arcNum(0) {
        vex = new char[size];
        arc = new int*[size];
        visited = new bool[size];
        for(int i = 0; i < size; ++i) {
            arc[i] = new int[size];
        }
        for(int i = 0; i < size; ++i) {
            for(int j = 0; j < size; ++j) {
                if(i == j) arc[i][j] = 0;
                else arc[i][j] = -1;
            }
        }
        for(int i = 0; i < size; ++i) {
            visited[i] = false;
        }
    }
    DNet(char* data, int n) :DNet(n + 10) {
        vexNum += n;
        for(int i = 0; i < n; ++i) {
            vex[i] = data[i];
        }
    }
    ~DNet() {
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
                arc[i][j] = -1;
            }
        }
        vexNum = 0, arcNum = 0;
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
        int count;
        for(int i = 0; i < vexNum; ++i) {
            if(arc[i][v] == true) ++count;
        }
        return count;
    }
    int getOArcNum(int v) const {
        int count;
        for(int i = 0; i < vexNum; ++i) {
            if(arc[v][i] == true) ++count;
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
    void insertArc(int v1, int v2, int w) {
        if(v1 < 0 || v1 >= vexNum || v2 < 0 || v2 >= vexNum || v1 == v2) return;
        arc[v1][v2] = w;
        ++arcNum;
    }
    void deleteVex(int v) {
        if(v < 0 || v >= vexNum) return;
        arcNum -= getArcNum(v);
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
            arc[vexNum - 1][i] = -1;
            arc[i][vexNum - 1] = -1;
        }
        vexNum -= 1;
    }
    void deleteArc(int v1, int v2) {
        if(v1 < 0 || v1 >= vexNum || v2 < 0 || v2 >= vexNum || v1 == v2) return;
        arc[v1][v2] = -1;
        --arcNum;
    }
};
class UNet: public DNet {
public:
    friend void kruskal(const UNet&);
    friend void prim(const UNet&, int);
    UNet(int s): DNet(s) {}
    UNet(char* data, int n): DNet(data, n) {}
    int getIArcNum(int v) const {
        return getOArcNum(v);
    }
    int getOArcNum(int v) const {
        int count;
        for(int i = 0; i < vexNum; ++i) {
            if(arc[v][i] == true) ++count;
        }
        return count;
    }
    int getArcNum(int v) const {
        return getOArcNum(v);
    }
    void insertArc(int v1, int v2, int w) {
        arc[v1][v2] = w;
        arc[v2][v1] = w;
        ++arcNum;
    }
    void deleteArc(int v1, int v2) {
        arc[v1][v2] = -1;
        arc[v2][v1] = -1;
        --arcNum;
    }
    void DFS(int v) const {
        std::cout << vex[v] << ' ';
        visited[v] = true;
        for(int i = 0; i < vexNum; ++i) {
            if(!visited[i] && v != i && arc[v][i] != -1) DFS(i);
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