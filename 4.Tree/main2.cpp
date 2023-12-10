#include "BST.hpp"
#include "AVL.cpp"
int main() {
    int a[]{1,4,9,2,7,6,8,3,5};

    AVL t(a, 9);
    t.deleteNode(9);
    t.inOrder();
    std::cout << std::endl;
    t.dispTree();
}