#pragma once
template<class DataType>
struct DNode {
    DataType data;
    DNode<DataType>* prior,* next;
    DNode(const DataType& d, DNode* p = nullptr, DNode* n = nullptr) :data(d), prior(p), next(n) {}
    DNode(DNode* p = nullptr, DNode* n = nullptr) :prior(p), next(n) {}
};