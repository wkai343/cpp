#include "AMNet.hpp"
void prim(const UNet& n, int e) {
    int lowest[n.getVexNum()], closest[n.getVexNum()], min = -1;
    for(int i = 0; i < n.getVexNum(); ++i) {
        lowest[i] = INT32_MAX;
        closest[i] = i;
    }
    for(int j = 0; j < n.getVexNum(); ++j) {
        if(n.arc[e][j] != INT32_MAX) {
            lowest[j] = n.arc[e][j]; // 0表示已添加
            closest[j] = e;
        }
    }

    for(int k = 1; k < n.getVexNum(); ++k) {
        for(int m = 0; m < n.getVexNum(); ++m) {
            if(lowest[m] != 0) {
                if(min == -1) {
                    min = m;
                }
                if(lowest[m] < lowest[min]) min = m;
            }
        }
        std::cout << "权值为" << lowest[min] << "的边: (" << closest[min] << ',' << min << ")\n";
        for(int l = 0; l < n.getVexNum(); ++l) {
            if(n.arc[min][l] != INT32_MAX && min != l && n.arc[min][l] < lowest[l]) {
                lowest[l] = n.arc[min][l];
                closest[l] = min;
            }
        }
        lowest[min] = 0;
        min = -1;
    }
}