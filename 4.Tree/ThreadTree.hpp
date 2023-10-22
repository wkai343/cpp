#include "BinaryTree.hpp"
struct TBNode {
    char data;
    TBNode* left, * right;
    bool lTag, rTag;
    TBNode(char ch, TBNode* l, TBNode* r, bool lt, bool rt) :data(ch), left(l), right(r), lTag(lt), rTag(rt) {}
};
class PreThreadTree {};
class InThreadTree {
private:
    TBNode* root;
};
class PostThreadTree {};
class LevelThreadTree {};