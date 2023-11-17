#include "BST.hpp"
#include <algorithm>
    void leftRotate(BNode*&);
    void rightRotate(BNode*&);
    int getHeight(BNode*);
class AVL :public BST{
public:
    AVL() {}
    AVL(int* data, int n) {
        for(int i = 0; i < n; ++i) {
            insertNode(data[i]);
        }
    }
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
        root = insertNode(root, i);
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
        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
        // ++node->height;
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
    void deleteNode(int i) {
        root = deleteNode(root, i);
    }
    BNode* deleteNode(BNode* node, int i) {
        if(node == nullptr) {
            return nullptr;
        }
        if(i < node->data) {
            node->left = deleteNode(node->left, i);
        } else if(i > node->data) {
            node->right = deleteNode(node->right, i);
        } else {
            BNode* t;
            if(node->left == nullptr || node->right == nullptr) {
                if(node->left == nullptr) {
                    t = node->right;
                    delete node;
                    return t;
                } else {
                    t = node->left;
                    delete node;
                    return t;
                }
            } else {
                t = node->left;
                while (t->right != nullptr) {
                    t = t->right;
                }
                node->data = t->data;
                node->left = deleteNode(node->left, node->data);
            }
        }
        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
        // ++node->height;
        if(node->getBalance() > 1 && node->left->getBalance() >= 0) {
            rightRotate(node);
        }
        if(node->getBalance() < -1 && node->right->getBalance() <= 0) {
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