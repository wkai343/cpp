#include "floyed.cpp"
int main() {
    DNet net(4);
    for(int i = 0; i < 4; ++i) {
        net.insertVex('A' + i);
    }
    net.insertArc(0, 1, 2);
    net.insertArc(0, 2, 6);
    net.insertArc(0, 3, 4);
    net.insertArc(1, 2, 3);
    net.insertArc(2, 0, 7);
    net.insertArc(2, 3, 1);
    net.insertArc(3, 0, 5);
    net.insertArc(3, 2, 12);
    floyed(net);
    return 0;
}