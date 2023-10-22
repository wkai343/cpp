#include<iostream>
using namespace std;
int** summonYH(int n);
void printMatrix(int** p, int);
void rePrintMatrix(int** p, int);
int* zipMatrix(int** p, int);
void printZippedMatrix(int* p, int);
int main() {
    int n, **p;
    cout << "___\b\b\b";
    cin >> n;
    p = summonYH(n);
    printMatrix(p, n);
    rePrintMatrix(p, n);
    int* np = zipMatrix(p, n);
    printZippedMatrix(np, n);
    delete[] np;
    for(int i = 0; i < n; ++i) {
        delete[] p[i];
    }
    delete[] p;
    return 0;
}
int **summonYH(int n) {
    int** p = new int*[n];
    for(int i = 0; i < n; ++i) {
        p[i] = new int[n]{};
    }
    p[0][0] = 1;
    for(int i = 0; i < n; ++i) {
        p[i][0] = 1;
    }
    for(int i = 1; i < n; ++i) {
        for(int j = 1; j < i + 1; ++j) {
            p[i][j] = p[i - 1][j - 1] + p[i - 1][j];
        }
    }
    return p;
}
void printMatrix(int** p, int n) {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < i + 1; ++j) {
            cout << p[i][j] << ' ';
        }
        cout << endl;
    }
}
void rePrintMatrix(int** p, int n) {
    for(int i = 0; i < n; ++i) {
        for(int j = i; j < n; ++j) {
            cout << p[j][i] << ' ';
        }
        cout << endl;
    }
}
int* zipMatrix(int** p, int n) {
    int* np = new int[(1 + n) * n / 2 + n - 1]{};
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < i + 1; ++j) {
            np[(1 + i) * i / n + j + i] = p[i][j];
        }
    }
    return np;
    // int count = 1;
    // for(int i = 1; i < n; ++i) {
    //     count = count + 1;
    //     np[count] = 0;
    // }
}
void printZippedMatrix(int* p, int n) {
    for(int i = 0; i < (1 + n) * n / 2 + n - 1; ++i) {
        if(p[i] == 0) {
            cout << endl;
            continue;
        }
        cout << p[i] << ' ';
    }
}