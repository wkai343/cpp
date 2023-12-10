#include "seqSearch.cpp"
#include "binSearch.cpp"
int seqSearch(int*, int, int); // 顺序查找
int seqSearch(std::vector<int>& v, int key);
int binSearch(int*, int, int); // 二分查找(有序序列)
// todo: 折半查找变形