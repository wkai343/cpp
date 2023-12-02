#include "ALNet.hpp"
int main() {
    DNet net(6);
    for(int i = 0; i < 6; ++i) {
        net.insertVex('A' +i);
    }
    net.insertArc(0, 1);
    net.insertArc(1, 2);
    net.insertArc(2, 3);
    net.insertArc(4, 1);
    net.insertArc(4, 5);
    net.insertArc(5, 3);
    net.topSort();
    return 0;
}