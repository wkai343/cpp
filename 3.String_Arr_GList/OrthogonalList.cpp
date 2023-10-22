#include <iostream>
using namespace std;
struct OLNode {
    int row, col, value;
    OLNode* right,* down;
};
struct OLink {
    int n;
    OLNode* next;
};
class OrthogonalList {
private:
    OLink* rowHead,* colHead;
    int m, n;
public:
    OrthogonalList(int m, int n) :m(m), n(n) {
        rowHead = new OLink[m];
        colHead = new OLink[n];
    }
    ~OrthogonalList() {
        for(int i = 0; i < m; ++i) {
            
        }
    }
};
int main() {

    return 0;
}