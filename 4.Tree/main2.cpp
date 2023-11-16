#include "BST.hpp"
#include "AVL.cpp"
int main() {
    int a[]{1,4,9,2,7,6,8,3,5};
    // BST t(a, 9);
    // t.deleteData(5);
    // t.inOrder();
    // BNode* root = new BNode(10);
    // root->right = new BNode(20);
    // root->right->right = new BNode(30);
    // leftRotate(root);
    // std::cout << root->left->data;

    AVL t;
    t.insertNode(10);
    t.insertNode(20);
    t.insertNode(30);
    std::cout << t.root->left->data << ' ' << t.root->right->data;
}