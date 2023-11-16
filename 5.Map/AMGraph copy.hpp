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
    }
    void clear() {
        for(int i = 0; i < vexNum; ++i) {
            for(int j = 0; j < vexNum; ++j) {
                arc[i][j] = false;
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
    int getIArcNum(char ch) const {
        int count;
        for(int i = 0; i < vexNum; ++i) {
            if(arc[locate(ch)][i] == true) ++count;
        }
        return count;
    }
    int getOArcNum(char ch) const {
        int count;
        for(int i = 0; i < vexNum; ++i) {
            if(arc[locate(ch)][i] == true) ++count;
        }
        return count;
    }
    int getArcNum(char ch) const {
        return getIArcNum(ch) + getOArcNum(ch);
    }
    int locate(char ch) const {
        for(int i = 0; i < vexNum; ++i) {
            if(vex[i] == ch) return i;
        }
        return -1;
    }
    void insertVex(char ch) {
        if(vexNum == size) {
            return;
        }
        vex[vexNum++] = ch;
    }
    void insertArc(char ch1, char ch2) {
        arc[locate(ch1)][locate(ch2)] = true;
    }
    void deleteVex(char ch) {
        arcNum -= getArcNum(ch);
        int pos = locate(ch);
        for(int i = pos; i < vexNum - 1; ++i) {
            for(int j = 0; j < pos; ++j) {
                arc[i][j] = arc[i + 1][j];
                arc[j][i] = arc[j][i + 1];
            }
            for(int k = pos; k < vexNum - 1; ++k) {
                arc[i][k] =arc[i + 1][k + 1];
            }
        }
        for(int i = 0; i < vexNum; ++i) {
            arc[vexNum - 1][i] = false;
            arc[i][vexNum - 1] = false;
        }
        vexNum -= 1;
    }
    void deleteArc(char ch1, char ch2) {
        arc[locate(ch1)][locate(ch2)] = false;
    }
};
class UGraph :public DGraph {
public:
    void insertArc(char ch1, char ch2) {
        arc[locate(ch1)][locate(ch2)] = true;
        arc[locate(ch2)][locate(ch1)] = true;
    }
    void deleteArc(char ch1, char ch2) {
        arc[locate(ch1)][locate(ch2)] = false;
        arc[locate(ch2)][locate(ch1)] = false;
    }
    void DFS(int v) {}
};