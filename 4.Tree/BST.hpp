#pragma once
#include <iostream>
#include <queue>
struct BNode {
    int data;
    int height;
    BNode* left,* right;
    BNode(int i = -1, BNode* l= nullptr, BNode* r = nullptr) :data(i), height(1), left(l), right(r) {}
    int getBalance() {
        int lH = left == nullptr ? 0 : left->height, rH = right == nullptr ? 0 : right->height;
        return lH - rH;
    }
};
class BST {
protected:
    BNode* root;
    friend int main();
public:
    BST() :root(nullptr) {}
    BST(int* data, int n) :BST() {
        for(int i = 0; i < n; ++i) {
            insertData(data[i]);
        }
    }
    ~BST() {
        clear();
    }
    void destroy(BNode* p) {
        if(p->left != nullptr) destroy(p->left);
        if(p->right != nullptr) destroy(p->right);
        delete p;
    }
    void clear() {
        destroy(root);
        root = nullptr;
    }
    BNode* searchData(int i, BNode*& p) const {
        BNode* t = p = root;
        while(t && t->data != i) {
            p = t;
            if(i < t->data) {
                t = t->left;
            } else {
                t = t->right;
            }
        }
        return t;
    }
    bool searchNode(int i) const {
        BNode* p = root;
        while(p) {
            if(i < p->data) {
                p = p->left;
            } else if(i > p->data) {
                p = p->right;
            } else {
                return true;
            }
        }
        return false;
    }
    bool insertData(int i) {
        if(root == nullptr) {
            root = new BNode(i);
        }
        BNode* p;
        if(searchData(i, p)) return false;
        if(i < p->data) {
            p->left = new BNode(i);
        } else {
            p->right = new BNode(i);
        }
        return true;
    }
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
        return node;
    }
    bool deleteData(int i) {
        BNode* p, * t;
        if(root == nullptr || !(t = searchData(i, p))) {
            return false;
        }
        if(t->left == nullptr || t->right == nullptr) {
            if(t->left == nullptr) {
                if(t == p->left) {
                    p->left = t->right;
                    delete t;
                } else {
                    p->right = t->right;
                    delete t;
                }
            } else if(t->right == nullptr) {
                if(t == p->left) {
                    p->left = t->left;
                    delete t;
                } else {
                    p->right = t->left;
                    delete t;
                }
            }
        } else {
            BNode* temp = t;
            t = t->left;
            while(t->right != nullptr) {
                p = t;
                t = t->right;
            }
            int tem = t->data;
            t->data = temp->data;
            temp->data = tem;
            p->right = t->left;
            delete t;
        }
        return true;
    }
    void inOrder(const BNode* BN) {
        if(BN->left != nullptr) inOrder(BN->left);
        std::cout << BN->data << ' ';
        if(BN->right != nullptr) inOrder(BN->right);
    }
    void inOrder() {
        if(root == nullptr) return;
        inOrder(root);
    }
    void levelOrder() {
        std::queue<BNode*> q;
        if(root != nullptr) q.push(root);
        while(!q.empty()) {
            std::cout << q.front()->data << ' ';
            if(q.front()->left != nullptr) q.push(q.front()->left);
            if(q.front()->right != nullptr) q.push((q.front()->right));
            q.pop();
        }
    }
};
