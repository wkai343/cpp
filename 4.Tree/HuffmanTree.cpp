#include <string>
#include <iostream>
#include <vector>
using namespace std;
struct ch {
    char c;
    int n;
    ch(char c = '\0', int n = 0) :c(c), n(n) {}
};
struct BNode {
    ch data;
    BNode* left,* right;
};
void printCode(BNode* p, string s = "") {
    if(p->left == nullptr && p->right == nullptr) {
        cout << p->data.c << ':' << s << endl;
        return;
    }
    printCode(p->left, s + '0');
    printCode(p->right, s + '1');

}
string getCode(char ch, BNode* root, string code = "") {
    if(root->left == nullptr && root->right == nullptr) {
        if(root->data.c == ch) return code;
        else return "";
    }
    string str;
    if((str = getCode(ch, root->left, code + '0')) != "") return str;
    if((str = getCode(ch, root->right, code + '1')) != "") return str;
    return "";
}
int main() {
    BNode* root;
    ch chs[5]{{'c', 22}, {'d', 33}, {'e', 15},{'k', 25}, {'l', 5}};
    vector<BNode*> v;
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 5 - i - 1; ++j) {
            if(chs[j].n > chs[j + 1].n) {
                ch tmp = chs[j];
                chs[j] = chs[j + 1];
                chs[j + 1] = tmp;
            }
        }
    }
    for(int i = 0; i < 5; ++i) {
        v.push_back(new BNode{chs[i], nullptr, nullptr});
    }
    while(!v.empty()) {
        root = new BNode{ch{'\0', v[0]->data.n + v[1]->data.n}, v[0], v[1]};
        v.erase(v.begin());
        v.erase(v.begin());
        int j = 0;
        for(; j < v.size() && root->data.n > v[j]->data.n; ++j) {}
        if(!v.empty()) v.insert(v.begin() + j, root);
    }
    printCode(root);
    pair<char, string> p[5];
    for(int i = 0; i < 5; ++i) {
        p[i].first = chs[i].c;
        p[i].second = getCode(p[i].first, root);
    }
    string str = "ekeklcd", code, tmp, result;
    for(int i = 0; i < str.size(); ++i) {
        code += getCode(str[i], root);
    }
    cout << "编码：" << code << endl;
    for(int i = 0; i < code.size(); ++i) {
        tmp += code[i];
        for(int j = 0; j < 5; ++j) {
            if(tmp == p[j].second) {
                result += p[j].first;
                tmp = "";
                break;
            }
        }
    }
    cout << "解码：" << result << endl;
    return 0;
}