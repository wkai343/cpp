#include "AMNet.hpp"
void floyd(const DNet& net) {
    int matrix[net.getVexNum()][net.getVexNum()], path[net.getVexNum()][net.getVexNum()];
    for(int i = 0; i < net.getVexNum(); ++i)
        for(int j = 0; j < net.getVexNum(); ++j) {
            matrix[i][j] = net.arc[i][j];
            if(i != j && matrix[i][j] != INT32_MAX)
                path[i][j] = i;
            else path[i][j] = -1;
        }

    for(int k = 0; k < net.getVexNum(); ++k)
        for(int i = 0; i < net.getVexNum(); ++i)
            for(int j = 0; j < net.getVexNum(); ++j)
                if(matrix[i][k] != INT32_MAX && matrix[k][j] != INT32_MAX) {
                    if(matrix[i][k] + matrix[k][j] < matrix[i][j]) {
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                        path[i][j] = k;
                    }
                }
    
    for(int i = 0; i < net.getVexNum(); ++i) {
        for(int j = 0; j < net.getVexNum(); ++j) {
            if(matrix[i][j] == INT32_MAX) {
                std::cout << "inf ";
            } else {
                std::cout << matrix[i][j] << ' ';
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    int t;
    for(int i = 0; i < net.getVexNum(); ++i) {
        for(int j = 0; j < net.getVexNum(); ++j) {
            if(path[i][j] != -1) {
                t = j;
                std::cout << "Weight: " << matrix[i][j] << " path: ";
                while(path[i][t] != -1) {
                    std::cout << t << " <- ";
                    t = path[i][t];
                }
                std::cout << i << std::endl;
            }
        }
    }
}