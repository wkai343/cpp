#include "bubbleSort.cpp"
#include "cocktailSort.cpp"
#include "quickSort.cpp"
#include "selectSort.cpp"
#include "heapSort.cpp"
#include "insertSort.cpp"
#include "binInsertSort.cpp"
#include "shellSort.cpp"
#include "mergeSort.cpp"
#include "countSort.cpp"
#include "bucketSort.cpp"
#include "radixSort.cpp"

// 交换排序
void bubbleSort(int*, int); // 冒泡排序
void cocktailSort(int*, int); // 鸡尾酒排序
void quickSort(int*, int); // 快速排序

// 选择排序
void selectSort(int*, int); // 简单选择排序
void heapSort1(int*, int); // 小顶堆，优先队列
void heapSort2(int*, int); // 大顶堆，优先队列
void heapSort(int*, int); // 堆排序

// 插入排序
void insertSort(int*, int); // 直接插入排序
void binInsertSort(int*, int); // 二分插入排序
void shellSort(int*, int); // 希尔排序

// 归并排序
void mergeSort(int*, int); // 自底向上二路归并排序
void mergeSort2(int*, int); // 自顶向下二路归并排序

// 分配排序
void countSort(int*, int); // 计数排序
void bucketSort(int*, int); // 桶排序
void radixSort(int*, int); // 基数排序
void radixSort(int*, int, int); // 基数排序