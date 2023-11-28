#include <cstring>
#include <iostream>
#include "BinaryTree.hpp"
using namespace std;
int main() {
    string str = "A(B(D(, H), E(I, )), C(F(J, ), G))";
    string sqTree = "ABCDEFG#HI#J###";
    char pre[10]{'A', 'B', 'D', 'H', 'E', 'I', 'C', 'F', 'J', 'G'};
    char in[10]{'D', 'H', 'B', 'I', 'E', 'A', 'J', 'F', 'C', 'G'};
    // char post[10]{'H', 'D', 'I', 'E', 'B', 'J', 'F', 'G', 'C', 'A'};
    // char level[10]{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    // string pre = "ABDG#L##HM###EIN##O###C#FJ##K##";
    BinaryTree tree;
    // tree.createTree(str); // 用括号表示串创建树
    // tree.transTree(sqTree);
    tree.transTree(sqTree);
    BinaryTree tree2;
    tree2.createByPre(tree.preOrderSeq());
    tree2.dispTree();
    std::cout << std::endl;
    BinaryTree tree3;
    tree3.createByPre(tree2.preOrderSeq());
    tree3.dispTree();
    return 0;
}