#include "ALNet.hpp"
#include "dijkstra.cpp"
int main() {
    char ch[] = "ABCDEFGHI";
    DNet n(ch, 9);
    n.insertArc(0, 1, 12);
    n.insertArc(0, 2, 3);
    n.insertArc(0, 4, 9);
    n.insertArc(1, 3, 2);
    n.insertArc(1, 4, 6);
    n.insertArc(2, 5, 6);
    n.insertArc(3, 2, 2);
    n.insertArc(3, 4, 4);
    n.insertArc(3, 6, 5);
    n.insertArc(4, 5, 4);
    n.insertArc(5, 0, 10);
    n.insertArc(5, 3, 7);
    n.insertArc(6, 1, 8);
    n.insertArc(7, 6, 12);
    n.insertArc(7, 8, 10);
    n.getMinPath(0);
    dijkstra(n, 0);
    return 0;
}