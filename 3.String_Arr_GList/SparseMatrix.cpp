#include <iostream>
using namespace std;
struct Triple {
    int row, col, value;
    Triple() {}
    Triple(int row, int col, int value): row(row), col(col), value(value) {}
};
class TSMatrix {
private:
    int m, n, num;
    Triple *data;
public:
    TSMatrix(): m(0), n(0), num(0), data(NULL) {}
    TSMatrix(int m, int n, int num): m(m), n(n), num(num) {
        data = new Triple[num];
        for(int i = 0; i < num; i++) {
            cin >> data[i].row >> data[i].col >> data[i].value;
        }
    }
    void getTranspose(const TSMatrix& t) {
        m = t.n, n = t.m, num = t.num;
        if(data) {
            delete[] data;
        }
        data = new Triple[num];
        if(num) {
            int tNum[m], tPos[m];
            for(int i = 0; i < num; ++i) {
                ++tNum[t.data[i].col];
            }
            tPos[0] = 0;
            for(int i = 1; i < m; ++i) {
                tPos[i] = tPos[i - 1] + tNum[i - 1];
            }
            for(int i = 0; i < num; ++i) {
                int& temp = tPos[t.data[i].col];
                data[temp].row = t.data[i].col, data[temp].col = t.data[i].row, data[temp].value = t.data[i].value;
                ++temp;
            }
        }
    }
    ~TSMatrix() {
        delete [] data;
    }
    void print() {
        int k = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(data[k].row == i && data[k].col == j) {
                    cout << data[k++].value << " ";
                } else {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
};
int main() {
    TSMatrix matrix(3, 4, 3);
    matrix.print();
    TSMatrix test;
    test.getTranspose(matrix);
    test.print();
    return 0;
}
// int *rowSize = new int[n];
            // int *rowStart = new int[n];
            // for(int i = 0; i < n; ++i) {
            //     rowSize[i] = 0;
            // }
            // for(int i = 0; i < num; ++i) {
            //     ++rowSize[t.data[i].col];
            // }
            // rowStart[0] = 0;
            // for(int i = 1; i < n; ++i) {
            //     rowStart[i] = rowStart[i - 1] + rowSize[i - 1];
            // }
            // for(int i = 0; i < num; ++i) {
            //     int col = t.data[i].col;
            //     int j = rowStart[col];
            //     data[j].row = t.data[i].col;
            //     data[j].col = t.data[i].row;
            //     data[j].value = t.data[i].value;
            //     ++rowStart[col];
            // }
            // delete [] rowSize;
            // delete [] rowStart;