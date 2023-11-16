#include "ALGraph.hpp"
int main() {
    char chs[] = "ABCDEFG";
    UGraph g(chs, 7);
    g.insertArc(0, 1);
    g.insertArc(0, 2);
    g.insertArc(1, 3);
    g.insertArc(1, 4);
    g.insertArc(2, 4);
    g.insertArc(4, 6);
    g.insertArc(4, 5);
    int n = g.BFS();
    std::cout << '\n' << n;
    return 0;
}