#include "AMNet.hpp"
#include <cstdio>
#include <vector>
#include <queue>
struct Edge {
    int u, v, w;
    Edge(int u, int v, int w):u(u), v(v), w(w) {}
};
bool bellmanFord(const DNet& net, int v) {
    int dist[net.getVexNum()], path[net.getVexNum()], p = 0;
    std::queue<int> q;
    Edge* edge[net.getArcNum()];
    bool flag = true;

    for(int i = 0; i < net.getVexNum(); ++i) {
        dist[i] = INT32_MAX, path[i] = -1;
    }
    dist[v] = 0;

    q.push(v);
    while(!q.empty()) {
        net.visited[q.front()] = true;
        for(int i = 0; i < net.getVexNum(); ++i) {
            if(!net.visited[i] && q.front() != i && net.arc[q.front()][i] != INT32_MAX)
                q.push(i);
            if(q.front() != i && net.arc[q.front()][i] != INT32_MAX)
                edge[p++] = new Edge(q.front(), i, net.arc[q.front()][i]);
        }
        q.pop();
    }

    for(int i = 1; i < net.getVexNum() && flag; ++i) {
        flag = false;
        for(p = 0; p < net.getArcNum(); ++p) {
            if(dist[edge[p]->u] != INT32_MAX && dist[edge[p]->u] + edge[p]->w < dist[edge[p]->v]) {
                dist[edge[p]->v] = dist[edge[p]->u] + edge[p]->w;
                path[edge[p]->v] = edge[p]->u;
                flag = true;
            }
        }
    }

    for(p = 0; p < net.getArcNum(); ++p) {
        if(dist[edge[p]->u] != INT32_MAX && dist[edge[p]->u] + edge[p]->w < dist[edge[p]->v]) {
            dist[edge[p]->v] = dist[edge[p]->u] + edge[p]->w;
            path[edge[p]->v] = edge[p]->u;
            return false;
        }
    }
    // for(auto e: dist) std::cout << e << ' ';
    // std::cout << std::endl;
    // for(auto e: path) std::cout << e << ' ';
    // std::printf("\n");
    for(int i = 0; i < net.getVexNum(); ++i) {
        if(i !=v && path[i] != -1) {
            p = i;
            std::cout << "Weight: " << dist[i] << ", path: ";
            while(path[p] != -1) {
                std::cout << p << " <= ";
                p = path[p];
            }
            std::cout << v << std::endl;
        }
    }
    for(auto e: edge) delete e;
    return true;
}