#pragma once
#include <iostream>
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
    // 查找可用递归
    // 查找，p是双亲，返回值是查找到的地址，查找失败返回空指针
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
    // 只返回找到的节点
    BNode* searchData(int i) const {
        BNode* t = root;
        while(t && t->data != i) {
            if(i < t->data) {
                t = t->left;
            } else {
                t = t->right;
            }
        }
        return t;
    }
    // 仅判断在否
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
    // 插入，调用查找
    bool insertData(int i) {
        if(root == nullptr)
            root = new BNode(i);
        BNode* p;
        if(searchData(i, p)) return false;
        if(i < p->data) {
            p->left = new BNode(i);
        } else {
            p->right = new BNode(i);
        }
        return true;
    }
    // 递归插入
    void insertNode(int i) {
        root = insertNode(root, i);
    }
    BNode* insertNode(BNode* node, int i) {
        if(node == nullptr)
            node = new BNode(i);
        if(i < node->data) {
            node->left = insertNode(node->left, i);
        } else if(i > node->data) {
            node->right = insertNode(node->right, i);
        }
        return node;
    }
    // 删除，调用查找
    bool deleteData(int i) {
        BNode* p, * t;
        if(root == nullptr || !(t = searchData(i, p)))
            return false;
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
            t->data = temp->data, temp->data = tem;
            p->right = t->left;
            delete t;
        }
        return true;
    }

    // 中序遍历
    void inOrder(const BNode* BN) {
        if(BN->left != nullptr) inOrder(BN->left);
        std::cout << BN->data << ' ';
        if(BN->right != nullptr) inOrder(BN->right);
    }
    void inOrder() {
        if(root == nullptr) return;
        inOrder(root);
    }
    // 输出括号表示串
    void dispTree(BNode* p) {
        if(p) {
            std::cout << p->data;
            if(p->left || p->right) {
                std::cout << '(';
                dispTree(p->left);
                std::cout << ", ";
                dispTree(p->right);
                std::cout << ')';
            }
        }
    }
    void dispTree() {
        dispTree(root);
    }
};
