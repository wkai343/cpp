#include "AMNet.hpp"
#include <cstdint>
#include <stack>
int keyPath(const DNet& net) {
    int ve[net.getVexNum()], vl[net.getVexNum()], m = 0, topo[net.getVexNum()], key = 0; // ve是事件最早，vl是事件最迟，topo记录拓扑次序，key是关键路径长度
    std::stack<int> s;
    int ind[net.getVexNum()], temp;
    for(int i = 0; i < net.getVexNum(); ++i) {
        ind[i] = net.getID(i);
    }
    // 建立拓扑次序与计算ve
    for(int i = 0; i < net.getVexNum(); ++i) {
        if(ind[i] == 0) s.push(i);
    }
    for(int k = 0; k < net.getVexNum(); ++k) {
        temp = s.top();
        s.pop();
        topo[k] = temp;
        for(int i = 0; i < net.getVexNum(); ++i) {
            if(i != temp && net.arc[i][temp] != INT32_MAX) {
                if(ve[i] + net.arc[i][temp] > m) m = ve[i] + net.arc[i][temp];
            }
        }
        ve[temp] = m;
        m = 0;
        for(int i = 0; i < net.getVexNum(); ++i) {
            if(i != temp && net.arc[temp][i] != INT32_MAX) {
                if(--ind[i] == 0) s.push(i);
            }
        }
    }
    // 根据拓扑次序计算vl
    m = INT32_MAX;
    int t;
    vl[net.getVexNum() - 1] = ve[net.getVexNum() - 1];
    for(int k = 1; k < net.getVexNum(); ++k) {
        t = net.getVexNum() - k - 1;
        for(int i = 0; i < net.getVexNum(); ++i) {
            if(t != i && net.arc[t][i] != INT32_MAX) {
                if(vl[i] - net.arc[t][i] < m) m = vl[i] - net.arc[t][i];
            }
        }
        vl[t] = m;
        m = INT32_MAX;
    }
    // 按拓扑次序计算关键路径长度
    bool flag[net.getVexNum()];
    for(bool& e: flag) e = false;
    flag[topo[0]] = true;
    for(int i = 0; i < net.getVexNum(); ++i) {
        t = topo[i];
        if(flag[t]) {
            for(int j = 0; j < net.getVexNum(); ++j) {
                if(topo[i] != j && net.arc[topo[i]][j] != INT32_MAX) {
                    if(vl[j] - net.arc[topo[i]][j] - ve[topo[i]] == 0) {
                        flag[j] = true;
                        key += net.arc[topo[i]][j];
                        break;
                    }
                }
            }
        }   
    }
    return key;
}