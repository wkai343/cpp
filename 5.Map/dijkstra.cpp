#include "ALNet.hpp"
#include <queue>
void dijkstra(const DNet& net, int v) {
    int dist[net.getVexNum()], path[net.getVexNum()], min = -1, temp;
    bool selected[net.getVexNum()];
    ArcNode* p = net.vex[v].arc;
    for(int i = 0; i < net.getVexNum(); ++i) {
        dist[i] = INT32_MAX;
        path[i] = -1;
        selected[i] = false;
    }
    selected[v] = true;

    while(p != nullptr) {
        dist[p->vex] = p->weight;
        path[p->vex] = v;
        p = p->next;
    }

    for(int j = 1; j < net.getVexNum(); ++j) {
        for(int k = 0; k < net.getVexNum(); ++k) {
            if(!selected[k] && path[k] != -1) {
                if(min == -1) {
                    min = k;
                } else if(dist[k] < dist[min]) {
                    min = k;
                }
            }
        }
        if(min == -1) break;
        selected[min] = true;
        p = net.vex[min].arc;
        while(p != nullptr) {
            if(!selected[p->vex] && dist[min] + p->weight < dist[p->vex]) {
                dist[p->vex] = dist[min] + p->weight;
                path[p->vex] = min;
            }
            p = p->next;
        }
        min = -1;
    }

    for(int t = 0; t < net.getVexNum(); ++t) {
        if(selected[t] && t != v) {
            std::cout << "Weight:" << dist[t] << " Path: ";
            temp = t;
            while(temp != v) {
                std::cout << temp << " <-";
                temp = path[temp];
            }
            std::cout << ' ' << v << std::endl;
        }
    }
}
struct QNode {
    int v, dist;
    QNode(int v, int dist = 0): v(v), dist(dist) {}
    bool operator<(const QNode& qN) const {
        return dist > qN.dist;
    }
};
void dijkstra1(const DNet& net, int v) {
    int dist[net.getVexNum()], path[net.getVexNum()], temp;
    bool selected[net.getVexNum()];
    std::priority_queue<QNode> q;
    QNode qN(v);
    ArcNode* p = net.vex[v].arc;
    for(int i = 0; i < net.getVexNum(); ++i) {
        dist[i] = INT32_MAX;
        path[i] = -1;
        selected[i] = false;
    }
    dist[v] = 0;

    q.push(QNode(v));
    for(int i = 0; i < net.getVexNum(); ++i) {
        qN = q.top();
        q.pop();
        selected[qN.v] = true;
        p = net.vex[qN.v].arc;

        while(p != nullptr) {
            if(!selected[p->vex] && dist[qN.v] + p->weight < dist[p->vex]) {
                dist[p->vex] = dist[qN.v] + p->weight;
                path[p->vex] = qN.v;
                q.push(QNode(p->vex, dist[p->vex]));
            }
            p = p->next;
        }
    }

    for(int t = 0; t < net.getVexNum(); ++t) {
        if(selected[t] && t != v) {
            std::cout << "Weight:" << dist[t] << " Path: ";
            temp = t;
            while(temp != v) {
                std::cout << temp << " <-";
                temp = path[temp];
            }
            std::cout << ' ' << v << std::endl;
        }
    }
}