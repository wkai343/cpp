#include "breakCircle.cpp"
int main() {
    UNet net(6);
    for(int i = 0; i < 6; ++i)
        net.insertVex('A' + i);
    net.insertArc(0, 1, 6);
    net.insertArc(0, 2, 1);
    net.insertArc(0, 3, 5);
    net.insertArc(1, 2, 5);
    net.insertArc(3, 2, 5);
    net.insertArc(1, 4, 3);
    net.insertArc(4, 2, 6);
    net.insertArc(4, 5, 6);
    net.insertArc(2, 5, 4);
    net.insertArc(3, 5, 2);
    breakCircle(net);
    return 0;
}