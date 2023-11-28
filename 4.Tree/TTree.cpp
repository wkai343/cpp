#include "ThreadTree.hpp"
int main() {
    char pre[10]{'A', 'B', 'D', 'H', 'E', 'I', 'C', 'F', 'J', 'G'};
    char in[10]{'D', 'H', 'B', 'I', 'E', 'A', 'J', 'F', 'C', 'G'};
    PreThreadTree tree;
    tree.createByInAndPre(in, pre, 10);
    tree.thread();
    tree.preOrder();
    return 0;
}