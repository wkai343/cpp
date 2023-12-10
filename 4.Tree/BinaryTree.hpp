#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
struct BNode {
    char data;
    BNode* left,* right;
    BNode(char ch = '\0', BNode* l= nullptr, BNode* r = nullptr) :data(ch), left(l), right(r) {}
};
class BinaryTree {
private:
    BNode* root;
    BNode* _createByInAndPre(char* in, char* pre, int n) {
        if(n == 0) return nullptr;
        int i = 0;
        while(pre[0] != in[i]) ++i;
        return new BNode(pre[0], _createByInAndPre(in, pre + 1, i), _createByInAndPre(in + i + 1, pre + i + 1, n - i - 1));
    }
    BNode* _createByInAndPost(char* in, char* post, int n) {
        if(n == 0) return nullptr;
        int i = 0;
        while(post[n - 1] != in[i]) ++i;
        return new BNode(post[n - 1], _createByInAndPost(in, post, i), _createByInAndPost(in + i +1, post + i, n - i - 1));
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
    BNode* _createByPre(std::string_view pre, int& pos) {
        ++pos;
        if(pre[pos] == '#') return nullptr;
        return new BNode(pre[pos], _createByPre(pre, pos), _createByPre(pre, pos));
    }
    int _width(BNode* p, int t, int& count, int d = 0) {
        if(p) {
            if(d < t) {
                _width(p->left, t, count, d + 1);
                _width(p->right, t, count, d + 1);
            }
            if(d == t) {
                ++count;
            }
            if(p == root) return count;
        }
        return -1;
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

    // 先序、中序、后序的递归实现, 当flag==true, 序列化
    void preOrder(const BNode* BN, bool flag) {
        if(BN) {
            std::cout << BN->data << ' ';
            preOrder(BN->left, flag);
            preOrder(BN->right, flag);
        } else if(flag) {
            std::cout << '#' << ' ';
        }
    }
    void preOrder(bool flag = false) {
        if(root == nullptr) return;
        preOrder(root, flag);
    }
    std::string preOrderSeq(BNode* p) {
        if(p == nullptr) return "#";
        std::string s(1, p->data);
        s += preOrderSeq(p->left);
        s += preOrderSeq(p->right);
        return s;
    }
    std::string preOrderSeq() {
        return preOrderSeq(root);
    }
    void inOrder(const BNode* BN, bool flag) {
        if(BN) {
            inOrder(BN->left, flag);
            std::cout << BN->data << ' ';
            inOrder(BN->right, flag);
        } else if(flag) {
            std::cout << '#' << ' ';
        }
    }
    void inOrder(bool flag = false) {
        if(root == nullptr) return;
        inOrder(root, flag);
    }
    std::string inOrderSeq(BNode* p) {
        if(p == nullptr) return "#";
        std::string s;
        s += inOrderSeq(p->left);
        s += p->data;
        s += inOrderSeq(p->right);
        return s;
    }
    std::string inOrderSeq() {
        return inOrderSeq(root);
    }
    void postOrder(const BNode* BN, bool flag) {
        if(BN) {
            postOrder(BN->left, flag);
            postOrder(BN->right, flag);
            std::cout << BN->data << ' '; 
        } else if(flag) {
            std::cout << '#' << ' ';
        }  
    }
    void postOrder(bool flag = false) {
        if(root == nullptr) return;
        postOrder(root, flag);
    }
    std::string postOrderSeq(BNode* p) {
        if(p == nullptr) return "#";
        std::string s;
        s += postOrderSeq(p->left);
        s += postOrderSeq(p->right);
        s += p->data;
        return s;
    }
    std::string postOrderSeq() {
        return postOrderSeq(root);
    }
    // 层次遍历, 当flag==1, 序列化
    void levelOrder(bool flag = false) {
        std::queue<BNode*> q;
        if(root != nullptr) q.push(root);
        while(!q.empty()) {
            if(q.front() != nullptr) std::cout << q.front()->data << ' ';
            else {
                std::cout << '#' << ' ';
                q.pop();
                continue;
            }
            if(q.front()->left != nullptr) q.push(q.front()->left);
            else if(flag) q.push(nullptr);
            if(q.front()->right != nullptr) q.push((q.front()->right));
            else if(flag) q.push(nullptr);
            q.pop();
        }
    }
    std::string levelOrderSeq() {
        std::string s;
        std::queue<BNode*> q;
        if(root != nullptr) q.push(root);
        while(!q.empty()) {
            if(q.front() != nullptr) s += q.front()->data;
            else {
                s += '#';
                q.pop();
                continue;
            }
            if(q.front()->left != nullptr) q.push(q.front()->left);
            else q.push(nullptr);
            if(q.front()->right != nullptr) q.push((q.front()->right));
            else q.push(nullptr);
            q.pop();
        }
        return s;
    }

    // 先序遍历的非递归实现
    void sPreOrder1() {
        std::stack<BNode*> s;
        BNode* p = root;
        while(!(s.empty() && p == nullptr)) {
            if(p == nullptr) {
                p = s.top();
                s.pop();
                p = p->right;
            } else {
                s.push(p);
                std::cout << p->data << ' ';
                p = p->left;
            }
        }
    }
    void sPreOrder2() {
        if(root == nullptr) return;
        std::stack<BNode*> s;
        BNode* p;
        s.push(root);
        while(!s.empty()) {
            p = s.top();
            s.pop();
            std::cout << p->data << ' ';
            if(p->right) s.push(p->right);
            if(p->left) s.push(p->left);
        }
    }
    // 中序遍历的非递归实现
    void sInOrder1() {
        std::stack<BNode*> s;
        BNode* p = root;
        while(!(s.empty() && p == nullptr)) {
            if(p == nullptr) {
                std::cout << s.top()->data << ' ';
                p = s.top()->right;
                s.pop();
                continue;
            }
            s.push(p);
            p = p->left;
        }
    }
    void sInOrder2() {
        if(root == nullptr) return;
        std::stack<std::pair<BNode*, bool>> s;
        BNode* p;
        bool flag;
        s.push(std::pair(root, false));
        while(!s.empty()) {
            p = s.top().first;
            flag = s.top().second;
            s.pop();
            if(flag) {
                std::cout << p->data << ' ';
            } else {
                if(p->right) s.push(std::pair(p->right, false));
                s.push(std::pair(p, true));
                if(p->left) s.push(std::pair(p->left, false));
            }
        }
    }
    // 后序遍历的非递归实现
    void sPostOrder1() {
        std::stack<BNode*> s;
        BNode* p = root;
        std::vector<char> res;
        while(!(s.empty() && p == nullptr)) {
            if(p == nullptr) {
                p = s.top();
                s.pop();
                p = p->left;
                continue;
            }
            s.push(p);
            res.push_back(p->data);
            // cout << p->data << ' ';
            p = p->right;
        }
        std::vector<char>::reverse_iterator rit;
        for(rit = res.rbegin(); rit != res.rend(); ++rit) {
            std::cout << *rit << ' ';
        }
    }
    void sPostOrder2() {
        if(root == nullptr) return;
        std::stack<BNode*> s;
        BNode* p;
        std::vector<char> res;
        s.push(root);
        while(!s.empty()) {
            p = s.top();
            s.pop();
            res.push_back(p->data);
            if(p->left) s.push(p->left);
            if(p->right) s.push(p->right);
        }
        std::vector<char>::reverse_iterator rit;
        for(rit = res.rbegin(); rit != res.rend(); ++rit) {
            std::cout << *rit << ' ';
        }
    }
    //如果栈顶的节点不为空，将其左子节点压入栈中。如果栈顶的节点为空，弹出栈顶元素，然后检查新的栈顶节点。
    // 如果新的栈顶节点的右子节点不为空，将其右子节点压入栈中。如果新的栈顶节点的右子节点为空，输出其数据，然后将其弹出栈，并将一个空节点压入栈中。
    void sPostOrder3() {
        if(root == nullptr) return;
        std::stack<BNode*> s;
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
                        std::cout << s.top()->data << ' ';
                        s.pop();
                        s.push(nullptr);
                    }
                } else {
                    s.pop();
                    std::cout << s.top()->data << ' ';
                    s.pop();
                    if(s.empty()) return;
                    s.push(nullptr);
                } 
            }
        }
    }
    void sPostOrder4() {
    std::stack<BNode*> s1;
    std::stack<bool> s2;
    BNode* p = root;
    bool visited;
    while(p != nullptr || !s1.empty()) {
        while(p != nullptr) {
            s1.push(p);
            s2.push(false);
            p = p->left;
        }
        if(!s1.empty()) {
            p = s1.top();
            visited = s2.top();
            if(visited == false) { // 如果右子树还没有被访问过
                p = p->right;
                s2.pop();
                s2.push(true); // 标记右子树已经被访问过
            } else { // 如果右子树已经被访问过
                std::cout << p->data << ' ';
                s1.pop();
                s2.pop();
                p = nullptr;
            }
        }
    }
}
    void sPostOrder5() {
        std::stack<BNode*> s;
        BNode* p = root,* q;
        bool flag;
        do {
            while(p != nullptr) { // 进左
                s.push(p);
                p = p->left;
            }
            q = nullptr;
            flag = true; // 处理栈顶顶点
            while(!s.empty() && flag) { // 出栈
                p = s.top();
                if(p->right == q) { // p的右子树已访问或为空
                    std::cout << p->data << ' ';
                    s.pop();
                    q = p;
                } else { // 处理右子树
                    p = p->right;
                    flag = false;
                }
            }
        } while(!s.empty());
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

    //(层次反序列化)
    // 根据顺序存储创建树，非递归
    void transTree(std::string_view str) {
        if(root) clear();
        std::queue<BNode*> q1;
        std::queue<char> q2;
        for(char e: str) {
            if(e != ' ') {
                q2.push(e);
            }
        }
        if(q2.empty()) return;
        q1.push(new BNode(q2.front()));
        q2.pop();
        root = q1.front();
        while(!q2.empty()) {
            if(q2.front() != '#') {
                q1.front()->left = new BNode(q2.front());
                q1.push(q1.front()->left);
            }
            q2.pop();
            if(!q2.empty()) {
                if(q2.front() != '#') {
                    q1.front()->right = new BNode(q2.front());
                    q1.push(q1.front()->right);
                }
                q2.pop();
            }
            q1.pop();
        }
    }
    // 根据顺序存储创建树， 递归
    void transTree2(std::string_view str, int i, BNode*& p) {
        if(i <= str.length() && str[i] != '#') {
            p = new BNode(str[i]);
            transTree2(str, 2 * i + 1, p->left);
            transTree2(str, 2 * i + 2, p->right);
        }
    }
    void transTree2(std::string_view str) {
        if(root) clear();
        transTree2(str, 0, root);
    }
    // 根据括号表示法创建树
    void createTree(std::string_view str) {
        if(root) clear();
        BNode* p;
        std::stack<BNode*> s;
        bool flag = true;
        for(int i = 0; i < str.length(); ++i) {
            switch (str[i]) {
            case ' ':
                break;
            case '(':
                s.push(p);
                flag = true;
                break;
            case ',':
                flag = false;
                break;
            case ')':
                s.pop();
                break;
            default:
                p = new BNode(str[i]);
                if(root == nullptr) {
                    root = p;
                    break;
                }
                if(!s.empty()) {
                    if(flag) {
                        s.top()->left = p;
                    } else {
                        s.top()->right = p;
                    }
                }
            }
        }
    }
    // 根据中序与先序遍历结果创建树
    void createByInAndPre(char* in, char* pre, int n) {
        if(root) clear();
        int i = 0;
        while(pre[0] != in[i]) ++i;
        root = new BNode(pre[0], _createByInAndPre(in, pre + 1, i), _createByInAndPre(in + i + 1, pre + i + 1, n - i - 1));
    }
    // 根据中序与后序遍历结果创建树
    void createByInAndPost(char* in, char* post, int n) {
        if(root) clear();
        int i = 0;
        while(post[n - 1] != in[i]) ++i;
        root = new BNode(post[n - 1], _createByInAndPost(in, post, i), _createByInAndPost(in + i +1, post + i, n - i - 1));
    }
    // 根据中序与层序遍历结果创建树
    void createByInAndLevel(char* in, char* level, int n) {
        if(root) clear();
        root = _createByInAndLevel(in, level, n);
    }
    // 先序反序列化非递归实现
    void sCreateByPre(char* pre) {
        std::stack<BNode*> s1;
        std::stack<char> s2;
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
    // 先序反序列化递归实现
    void createByPre(std::string pre) {
        if(root != nullptr) clear();
        int i = -1;
        root = _createByPre(pre, i);
    }
    // 后序反序列化
    void createByPost(std::string post) {}

    void destroy(BNode* p) {
        if(p->left != nullptr) destroy(p->left);
        if(p->right != nullptr) destroy(p->right);
        delete p;
    }
    void clear() {
        destroy(root);
        root = nullptr;
    }
    // 插入左
    void insertLeft(BNode* p, char val) {
        if(p) p->left = new BNode(val);
    }
    // 插入右
    void insertRight(BNode* p, char val) {
        if(p) p->right = new BNode(val);
    }
    // 求双亲
    BNode* parent(BNode* t, BNode* p) {
        if(p == nullptr) return nullptr;
        if(p->left == t || p->right == t) return p;
        BNode* q;
        if((q = parent(t, p->left))) return q;
        if((q = parent(t, p->right))) return q;
        return nullptr;
    }
    // 求高度
    int height(BNode* p) {
        if(p == nullptr) return 0;
        return std::max(height(p->left), height(p->right)) + 1;
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
    // 求第i层节点数
    int width(int i) {
        if(i <= 0 || root == nullptr) return -1;
        int count = 0;
        return _width(root, i, count);
    }
    int width2(int i) {
        int count = 0;
        std::queue<std::pair<BNode*, int>> q; //second表示节点的层数
        q.push(std::pair(root, 1));
        while(!q.empty()) {
            if(q.front().second > i) return -1;
            if(q.front().second == i) ++count;
            else {
                if(q.front().first->left != nullptr)
                    q.push(std::pair(q.front().first->left, q.front().second + 1));
                if(q.front().first->right != nullptr)
                    q.push(std::pair(q.front().first->right, q.front().second + 1));
            }
            q.pop();
        }
        return count;
    }
    int width3(int i) {
        int count = 0, cur = 1; // count表示第i层个数,cur指当前层数
        BNode* last = root; // last表示当前层最后一个节点
        std::queue<BNode*> q;
        q.push(root);
        while(!q.empty()) {
            if(cur > i) return -1;
            if(cur == i) ++count;
            else {
                if(q.front()->left != nullptr) q.push(q.front()->left);
                if(q.front()->right != nullptr) q.push(q.front()->right);
                if(q.front() == last) {
                    ++cur;
                    last = q.back();
                }
            }
            q.pop();
        }
        return count;
    }
    int width4(int i) {
        if(i < 1) return -1;
        std::queue<BNode*> q;
        int cur = 1, n;
        q.push(root);
        while(!q.empty()) {
            if(cur == i) return q.size();
            n = q.size();
            for(int i = 0; i < n; ++i) {
                if(q.front()->left != nullptr) q.push(q.front()->left);
                if(q.front()->right != nullptr) q.push(q.front()->right);
                q.pop();
            }
            ++cur;
        }
        return -1;
    }
    // 求树宽度
    int maxWidth() {
        int h = height(root);
        int w[h];
        for(int i = 0; i < h; ++i) {
            w[i] = width(i + 1);
        }
        int max = w[0];
        for(int i = 1; i < h; ++i) {
            if(w[i] > max) max = w[i];
        }
        return max;
    }
    // 求叶子节点个数
    int leafCount(BNode* p) {
        if(p == nullptr) return 0;
        if((p->left == nullptr) && (p->right == nullptr)) return 1;
        return leafCount(p->left) + leafCount(p->right);
    }
    int leafCount() {
        return leafCount(root);
    }
    // 交换左右子树
    void swapTree(BNode* p) {
        if(p) {
            swapTree(p->left);
            swapTree(p->right);
            std::swap(p->left, p->right);
        }
    }
    void swapTree() {
        swapTree(root);
    }

    // 树的层序遍历
    // void levelOrder() {
    //     std::queue<BNode*> q;
    //     BNode* p;
    //     q.push(root);
    //     while(!q.empty()) {
    //         p = q.front()->left;
    //         while(p != nullptr) {
    //             q.push(p);
    //             p = p->right;
    //         }
    //         std::cout << q.front()->data << ' ';
    //         q.pop();
    //     }
    // }
};