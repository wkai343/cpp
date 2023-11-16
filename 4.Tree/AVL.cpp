#include "BST.hpp"
#include <algorithm>
    void leftRotate(BNode*&);
    void rightRotate(BNode*&);
    int getHeight(BNode*);
class AVL :public BST{
public:
    // bool insertData(int i) {
    //     if(root == nullptr) {
    //         root = new BNode(i);
    //     }
    //     BNode* p, * t = root;
    //     if((t = searchData(i, p))) return false;
    //     t = root;
    //     while(t) {
    //         ++t->height;
    //         if(i < t->data) {
    //             t = t->left;
    //         } else {
    //             t = t->right;
    //         }
    //     }
    //     if(i < p->data) {
    //         p->left = new BNode(i);
    //     } else {
    //         p->right = new BNode(i);
    //     }
    //     return true;
    // }
    void insertNode(int i) {
        BNode* p;
        if(!searchNode(i)) {
            root = insertNode(root, i);
        }
    }
    BNode* insertNode(BNode* node, int i) {
        if(node == nullptr) {
            return new BNode(i);
        }
        if(i < node->data) {
            node->left = insertNode(node->left, i);
        } else if(i > node->data) {
            node->right = insertNode(node->right, i);
        }
        // node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
        ++node->height;
        if(node->getBalance() > 1 && node->left->getBalance() > 0) {
            rightRotate(node);
        }
        if(node->getBalance() < -1 && node->right->getBalance() < 0) {
            leftRotate(node);
        }
        if(node->getBalance() > 1 && node->left->getBalance() < 0) {
            leftRotate(node->left);
            leftRotate(node);
        }
        if(node->getBalance() < -1 && node->right->getBalance() > 0) {
            rightRotate(node->right);
            rightRotate(node);
        }
        return node;
    }
    // bool deleteData(int i) {
    //     return false;
    // }
};
void leftRotate(BNode*& p) {
    BNode* temp = p->right;
    p->right = temp->left;
    temp->left = p;
    p = temp;
    p->left->height = std::max(getHeight(p->left->left),  getHeight(p->left->right));
    p->height = std::max(getHeight(p->left), getHeight(p->right));
}
void rightRotate(BNode*& p) {
    BNode* temp = p->left;
    p->left = temp->right;
    temp->right = p;
    p = temp;
    p->right->height = std::max(getHeight(p->left->left),  getHeight(p->left->right));
    p->height = std::max(getHeight(p->left), getHeight(p->right));
}
int getHeight(BNode* p) {
    if(p == nullptr) return 0;
    return p->height;
}