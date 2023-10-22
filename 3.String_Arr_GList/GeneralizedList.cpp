#include <iostream>
using namespace std;
struct GNode {
    bool tag;
    union {
        int data;
        GNode* subList;
    }value;
    GNode* next;
};
int main() {
    
    return 0;
}