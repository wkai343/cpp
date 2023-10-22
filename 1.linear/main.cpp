#include"sqTraverse.cpp"
#include"lTraverse.cpp"
#include"SqList.hpp"
#include"LinkList.hpp"
#include"SLinkList.hpp"
#include"OrderedSqList.hpp"
#include"OrderedLinkList.hpp"
#include"DLinkList.hpp"
int main() {
    int arr[]{3, 4, 1, 2, 5}, arr2[]{6, 7, 8, 9, 10};
    SLinkList<int> s;
    s.insertElem(3);
    s.insertElem(4);
    s.insertElem(5);
    s.deleteElem(4);
    s.traverse();
    return 0;
}