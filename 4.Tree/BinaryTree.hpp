#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <string_view>
using namespace std;
struct BNode {
    char data;
    BNode* left,* right;
    BNode(char ch = '\0', BNode* l= nullptr, BNode* r = nullptr) :data(ch), left(l), right(r) {}
};
class BinaryTree {
private:
    BNode* root;
    BNode* _createByPre(char* in, char* pre, int n) {
        if(n == 0) return nullptr;
        int i = 0;
        while(pre[0] != in[i]) ++i;
        return new BNode(pre[0], _createByPre(in, pre + 1, i), _createByPre(in + i + 1, pre + i + 1, n - i - 1));
    }
    BNode* _createByPost(char* in, char* post, int n) {
        if(n == 0) return nullptr;
        int i = 0;
        while(post[n - 1] != in[i]) ++i;
        return new BNode(post[n - 1], _createByPost(in, post, i), _createByPost(in + i +1, post + i, n - i - 1));
    }
    BNode* _createByInAndLevel(char* in, char* level, int n) {
        if(n == 0) return nullptr;
        if(n == 1) return new BNode(level[0]);
        int pos = 0, leftN = 0, rightN = 0, leftP = 0, rightP = 0;
        bool flag = false;
        while(in[pos] != level[0]) ++pos;
        leftN = pos, rightN = n - 1 - pos;
        char leftTree[leftN], rightTree[rightN];
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < pos; ++j) {
                if(in[j] == level[i]) flag = true;
            }
            if(flag) leftTree[leftP++] = level[i];
            else rightTree[rightP++] = level[i];
            flag = false;
        }
        return new BNode(level[0], _createByInAndLevel(in, leftTree, leftN), _createByInAndLevel(in + pos + 1, rightTree, rightN));
    }
    BNode* _createByPre(string_view pre) {
        static int pos = -1;
        ++pos;
        if(pre[pos] == '#') return nullptr;
        return new BNode(pre[pos], _createByPre(pre), _createByPre(pre));
    }
public:
    BinaryTree() :root(nullptr) {}
    ~BinaryTree() {clear();}
    BNode* getRoot() {
        return root;
    }
    bool isEmpty() {
        return root == nullptr;
    }
    void preOrder(const BNode* BN) {
        cout << BN->data << ' ';
        if(BN->left != nullptr) preOrder(BN->left);
        if(BN->right != nullptr) preOrder(BN->right);
    }
    void preOrder() {
        if(root == nullptr) return;
        preOrder(root);
    }
    void sPreOrder() {
        stack<BNode*> s;
        BNode* p = root;
        while(!(s.empty() && p == nullptr)) {
            if(p == nullptr) {
                p = s.top();
                s.pop();
                p = p->right;
                continue;
            }
            s.push(p);
            cout << p->data << ' ';
            p = p->left;
        }

    }
    void ssPreOrder() {
    BNode* p = root;
    if (p == nullptr) {
        return;
    }
    std::stack<const BNode*> nodeStack;
    std::vector<char> preOrderTraversal;
    nodeStack.push(p);
    while (!nodeStack.empty()) {
        const BNode* currentNode = nodeStack.top();
        nodeStack.pop();
        preOrderTraversal.push_back(currentNode->data);
        if (currentNode->right != nullptr) {
            nodeStack.push(currentNode->right);
        }
        if (currentNode->left != nullptr) {
            nodeStack.push(currentNode->left);
        }
    }
    for (char c : preOrderTraversal) {
        std::cout << c << " ";
    }
}
    void inOrder(const BNode* BN) {
        if(BN->left != nullptr) inOrder(BN->left);
        cout << BN->data << ' ';
        if(BN->right != nullptr) inOrder(BN->right);
    }
    void inOrder() {
        if(root == nullptr) return;
        inOrder(root);
    }
    void sInOrder() {
        stack<BNode*> s;
        BNode* p = root;
        while(!(s.empty() && p == nullptr)) {
            if(p == nullptr) {
                cout << s.top()->data << ' ';
                p = s.top()->right;
                s.pop();
                continue;
            }
            s.push(p);
            p = p->left;
        }
    }
    void ssInOrder() {
    stack<BNode*> s;
    BNode* p = root;
    vector<char> v;
    while(!s.empty() || p != nullptr) {
        if(p != nullptr) {
            s.push(p);
            p = p->left;
        } else {
            p = s.top();
            s.pop();
            v.push_back(p->data);
            p = p->right;
        }
    }
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
}
    void postOrder(const BNode* BN) {
        if(BN->left != nullptr) postOrder(BN->left);
        if(BN->right != nullptr) postOrder(BN->right);
        cout << BN->data << ' ';
    }
    void postOrder() {
        if(root != nullptr) return;
        postOrder(root);
    }
    void sPostOrder1() {
        stack<BNode*> s;
        stack<char> t;
        BNode* p = root;
        while(!(s.empty() && p == nullptr)) {
            if(p == nullptr) {
                p = s.top();
                s.pop();
                p = p->left;
                continue;
            }
            s.push(p);
            t.push(p->data);
            // cout << p->data << ' ';
            p = p->right;
        }
        while(!t.empty()) {
                cout << t.top() << ' ';
                t.pop();
            }
    }
    void sPostOrder2() {
        stack<BNode*> s;
        BNode* p;
        s.push(root);
        while(!s.empty()) {
            if(s.top() != nullptr) {
                s.push(s.top()->left);
            } else {
                s.pop();
                if(s.top() != nullptr) {
                    if(s.top()->right != nullptr) {
                        p = s.top()->right;
                        s.push(nullptr);
                        s.push(p);
                    } else {
                        cout << s.top()->data << ' ';
                        s.pop();
                        s.push(nullptr);
                    }
                } else {
                    s.pop();
                    cout << s.top()->data << ' ';
                    s.pop();
                    if(s.empty()) return;
                    s.push(nullptr);
                } 
            }
        }
    }
    void ssPostOrder() {
        stack<BNode*> s;
        BNode* p = root;
        vector<char> v;
        if(p != nullptr) s.push(p);
        while(!s.empty()) {
            p = s.top();
            s.pop();
            v.insert(v.begin(), p->data);
            if(p->left != nullptr) s.push(p->left);
            if(p->right != nullptr) s.push(p->right);
        }
        for(int i = 0; i < v.size(); i++) {
            cout << v[i] << ' ';
        }
    }
    void levelOrder() {
        queue<BNode*> q;
        if(root != nullptr) q.push(root);
        while(!q.empty()) {
            cout << q.front()->data << ' ';
            if(q.front()->left != nullptr) q.push(q.front()->left);
            if(q.front()->right != nullptr) q.push((q.front()->right));
            q.pop();
        }
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
    void sCreateByPre(char* pre) {
        stack<BNode*> s1;
        stack<char> s2;
        char p2;
        BNode* p1;
        for(int i = strlen(pre); i > 0; --i) {
            s2.push(pre[i - 1]);
        }
        p2 = s2.top();
        s2.pop();
        root = new BNode(p2);
        s1.push(root);
        while(!s2.empty()) {
            p2 = s2.top();
            s2.pop();
            if(s1.top() != nullptr) {
                if(p2 == '#') s1.push(nullptr);
                else {
                p1 = new BNode(p2);
                s1.top()->left = p1;
                s1.push(p1);
                }
            } else {
                if(p2 == '#') {
                    s1.pop();
                    s1.pop();
                    if(s1.top() != nullptr) s1.push(nullptr);
                }
                else {
                    p1 = new BNode{p2};
                    s1.pop();
                    s1.top()->right = p1;
                    s1.pop();
                    s1.push(nullptr);
                    s1.push(p1);
                }
            }
        }
    }
    void createByPre(string pre) {
        if(root != nullptr) clear();
        root = _createByPre(pre);
    }
    void createByPost(char* post) {}
    void createByLevel(char* level) {}
    void createByInAndPre(char* in, char* pre, int n) {
        if(root != nullptr) clear();
        int i = 0;
        while(pre[0] != in[i]) ++i;
        root = new BNode(pre[0], _createByPre(in, pre + 1, i), _createByPre(in + i + 1, pre + i + 1, n - i - 1));
    }
    void createByInAndPost(char* in, char* post, int n) {
        if(root != nullptr) clear();
        int i = 0;
        while(post[n - 1] != in[i]) ++i;
        root = new BNode(post[n - 1], _createByPost(in, post, i), _createByPost(in + i +1, post + i, n - i - 1));
    }
    void createByInAndLevel(char* in, char* level, int n) {
        root = _createByInAndLevel(in, level, n);
    }
    void insertLeft(BNode* p, char val) {
        if(p) p->left = new BNode(val);
    }
    void insertRight(BNode* p, char val) {
        if(p) p->right = new BNode(val);
    }
    BNode* parent(BNode* t, BNode* p) {
        if(p == nullptr) return nullptr;
        if(p->left == t || p->right == t) return p;
        BNode* q;
        if((q = parent(t, p->left))) return q;
        if((q = parent(t, p->right))) return q;
        return nullptr;
    }
    int height(BNode* p) {
        if(p == nullptr) return 0;
        return height(p->left) >= height(p->right) ? height(p->left) + 1 : height(p->right) + 1;
    }
    int height() {
        return height(root);
    }
    int level(BNode* t, BNode* p, int l = 0) {
        if(root == nullptr) return 0;
        if(p == nullptr) return 0;
        if(p == t) return l;
        int n;
        if((n = level(t, p->left, l + 1))) return n;
        if((n = level(t, p->right, l + 1))) return n;
        return 0;
    }
    int width() {
        int h = height(root);
        int w[h];
        for(auto& e : w) e = 0;
        BNode* p = root;
        stack<BNode*> s;
         while(!(s.empty() && p == nullptr)) {
            if(p == nullptr) {
                p = s.top();
                s.pop();
                p = p->right;
                continue;
            }
            s.push(p);
            ++w[level(p, root)];
            p = p->left;
        }
        int max = w[0];
        for(int i = 1; i < h; ++i) {
            if(w[i] > max) max = w[i];
        }
        return max;
    }
    int leafCount(BNode* p) {
        if(p == nullptr) return 0;
        if((p->left == nullptr) && (p->right == nullptr)) return 1;
        return leafCount(p->left) + leafCount(p->right);
    }
    int leafCount() {
        return leafCount(root);
    }
};