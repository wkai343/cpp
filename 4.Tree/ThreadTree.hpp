#include <cstddef>
#include <iostream>
#include <stack>
#include <mutex>
using namespace std;
struct TBNode {
    char data;
    TBNode* left, * right;
    bool lTag, rTag;
    TBNode(char ch, TBNode* l, TBNode* r, bool lt = 0, bool rt = 0) :data(ch), left(l), right(r), lTag(lt), rTag(rt) {}
};
class PreThreadTree {
private:
    TBNode* root;
    TBNode* _createByPre(char* in, char* pre, int n) {
        if(n == 0) return nullptr;
        int i = 0;
        while(pre[0] != in[i]) ++i;
        return new TBNode(pre[0], _createByPre(in, pre + 1, i), _createByPre(in + i + 1, pre + i + 1, n - i - 1));
    }
    void thread(TBNode* p) {
        static TBNode* pre = p;
        if(p) {
            if(p->left == nullptr) {
                p->left = pre;
                p->lTag = 1;
            }
            if(pre->right == nullptr) {
                pre->right = p;
                pre->rTag = 1;
            }
            pre = p;
            if(!p->lTag) thread(p->left);
            if(!p->rTag) thread(p->right);
        }
    }
public:
    PreThreadTree() :root(nullptr) {}
    ~PreThreadTree() {clear();}
    void clear() {}
    void createByInAndPre(char* in, char* pre, int n) {
        if(root != nullptr) clear();
        int i = 0;
        while(pre[0] != in[i]) ++i;
        root = new TBNode(pre[0], _createByPre(in, pre + 1, i), _createByPre(in + i + 1, pre + i + 1, n - i - 1));
    }
    TBNode* getNext(TBNode* p){
        if(p->rTag) {
            return p->right;
        }
        if(!p->lTag && p->left) {
            return p->left;
        } else {
            return p->right;
        }
    }
    void preOrder() {
        TBNode* p = root;
        while(p != nullptr) {
            cout << p->data << ' ';
            p = getNext(p);
        }
    }
    void thread() {
        thread(root);
    }
};
class InThreadTree {
private:
    TBNode* root;
    TBNode* _createByPre(char* in, char* pre, int n) {
        if(n == 0) return nullptr;
        int i = 0;
        while(pre[0] != in[i]) ++i;
        return new TBNode(pre[0], _createByPre(in, pre + 1, i), _createByPre(in + i + 1, pre + i + 1, n - i - 1));
    }
    void thread(TBNode* p) {
        static TBNode* pre = nullptr;
        if(p) {
            thread(p->left);
            if(p->left == nullptr) {
                p->left = pre;
                p->lTag = 1;
            }
            if(pre && pre->right == nullptr) {
                pre->right = p;
                pre->rTag = 1;
            }
            pre = p;
            thread(p->right);
        } 
    }
public:
    InThreadTree() :root(nullptr) {}
    ~InThreadTree() {clear();}
    TBNode* getRoot() {
        return root;
    }
    bool isEmpty() {
        return root == nullptr;
    }
    void createByInAndPre(char* in, char* pre, int n) {
        if(root != nullptr) clear();
        int i = 0;
        while(pre[0] != in[i]) ++i;
        root = new TBNode(pre[0], _createByPre(in, pre + 1, i), _createByPre(in + i + 1, pre + i + 1, n - i - 1));
    }
    TBNode* getNext(TBNode* p) {
        if(p->rTag) {
            return p->right;
        }
        if(p->right == nullptr) return nullptr;
        p = p->right;
        while(!p->lTag) p = p->left;
        return p;
    }
    TBNode* getPre(TBNode* p) {
        if(p->lTag) {
            return p->left;
        }
        p = p->left;
        while(!p->rTag) p = p->right;
        return p;
    }
    void inOrder() {
        TBNode* p = root;
        while(!p->lTag) p = p->left;
        while(p != nullptr) {
            cout << p->data << ' ';
            p = getNext(p);
        }
    }
    void thread() {
        thread(root);
    }
    void clear() {}
};
class PostThreadTree {
private:
    TBNode* root;
    TBNode* _createByPre(char* in, char* pre, int n) {
        if(n == 0) return nullptr;
        int i = 0;
        while(pre[0] != in[i]) ++i;
        return new TBNode(pre[0], _createByPre(in, pre + 1, i), _createByPre(in + i + 1, pre + i + 1, n - i - 1));
    }
    void thread(TBNode* p) {
        static TBNode* pre = nullptr;
        if(p) {
            thread(p->left);
            thread(p->right);
            if(pre && p->left == nullptr) {
                p->left = pre;
                p->lTag = 1;
            }
            if(pre && pre->right == nullptr) {
                pre->right = p;
                pre->rTag = 1;
            }
            pre = p;
        } 
    }
public:
    PostThreadTree() :root(nullptr) {}
    ~PostThreadTree() {clear();}
    TBNode* getRoot() {
        return root;
    }
    bool isEmpty() {
        return root == nullptr;
    }
    void createByInAndPre(char* in, char* pre, int n) {
        if(root != nullptr) clear();
        int i = 0;
        while(pre[0] != in[i]) ++i;
        root = new TBNode(pre[0], _createByPre(in, pre + 1, i), _createByPre(in + i + 1, pre + i + 1, n - i - 1));
    }
    TBNode* getPre(TBNode* p) {
        if(p->lTag) {
            return p->left;
        }
        if(!p->rTag && p->right) {
            return p->right;
        } else {
            return p->left;
        }
    }
    void postOrder() {
        stack<char> s;
        TBNode* p = root;
        while(p != nullptr) {
            s.push(p->data);
            p = getPre(p);
        }
        while(!s.empty()) {
            cout << s.top() << ' ';
            s.pop();
        }
    }
    void thread() {
        thread(root);
    }
    void clear() {}
};
class LevelThreadTree {};