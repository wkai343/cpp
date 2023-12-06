#include "AMNet.hpp"
#include "isConnect.cpp"
#include <queue>
struct Edge {
    int u, v, w;
    Edge(int u, int v, int w):u(u), v(v), w(w) {}
    bool operator<(const Edge& edge) const {
        return w < edge.w;
    }
};
void breakCircle(const UNet& net) {
    UNet temp(net);
    std::priority_queue<Edge> q;
    for(int i = 0; i < net.getVexNum() - 1; ++i) {
        for(int j = i + 1; j < net.getVexNum(); ++j) {
            if(i != j && net.arc[i][j] != INT32_MAX)
                q.push(Edge(i, j, net.arc[i][j]));
        }
    }
    while(temp.getArcNum() + 1 > temp.getVexNum()) {
        temp.deleteArc(q.top().u, q.top().v);
        if(isConnect(temp)) {
            std::cout << "已删除权值为" << q.top().w << "的边: (" << q.top().u << ", " << q.top().v << ')' << std::endl;
        } else {
            temp.insertArc(q.top().u, q.top().v, q.top().w);
        }
        q.pop();
    }
}