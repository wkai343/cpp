class Net {
private:
    int vexNum, arcNum, size;
    char* vex;
    int** arc;
public:
    Net(int s) :size(s), vexNum(0), arcNum(0) {
        vex = new char[size];
        arc = new int*[size];
        for(int i = 0; i < size; ++i) {
            arc[i] = new int[size];
        }
        for(int i = 0; i < size; ++i) {
            for(int j = 0; j < size; ++j) {
                arc[i][j] = -1;
            }
        }
    }
};