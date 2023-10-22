#include<iostream>
template<class DataStruct>
void sqTraverse(const DataStruct& d) {
    if(d.isEmpty()) return;
    for(int i = 0; i < d.getLength(); ++i) {
        std::cout << d.elem[i] << ' ';
    }
    std::cout << std::endl;
}