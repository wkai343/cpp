#include "ALNet.hpp"
int main() {
    DNet net(5);
    for(int i = 0; i < 5; ++i) {
        net.insertVex('A' + i);
    }
    net.insertArc(0, 1, 90);
    net.insertArc(0, 4, 75);
    net.insertArc(3, 4, 10);
    net.insertArc(1, 2, -30);
    net.insertArc(3, 2, -30);
    net.insertArc(2, 4, 10);
    net.insertArc(0, 3, 80);
    net.getMinPath(0);
    return 0;
}