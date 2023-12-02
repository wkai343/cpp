#include "AMNet.hpp"
#include "keyPath.cpp"
int main() {
    DNet net(9);
    for(int i = 0; i < 9; ++i) {
        net.insertVex('A' +i);
    }
    net.insertArc(0, 1, 6);
    net.insertArc(0, 2, 4);
    net.insertArc(0, 3, 5);
    net.insertArc(1, 4, 1);
    net.insertArc(2, 4, 1);
    net.insertArc(4, 5, 9);
    net.insertArc(4, 6, 7);
    net.insertArc(3, 7, 2);
    net.insertArc(5, 8, 2);
    net.insertArc(6, 8, 4);
    net.insertArc(7, 8, 4);
    std::cout << keyPath(net);
    return 0;
}