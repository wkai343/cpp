struct ArcNode {
    int vex;
    ArcNode* next1,* next2;
    ArcNode(int n = -1) {
        vex = n;
        next1 = nullptr;
        next2 = nullptr;
    }
};
struct VexNode {
    char ch;
    ArcNode* arc;
    VexNode(char c = '\0', ArcNode* p = nullptr) {
        ch = c;
        arc = p;
    }
};
class UGraph {
private:
    int vexNum, arcNum, size;
    VexNode* vex;
    bool* visited;
};