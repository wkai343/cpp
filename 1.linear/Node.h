#pragma once
template<class DataType>
struct Node {
    DataType data;
    Node<DataType>* next;
    Node(const DataType& d, Node* n = nullptr) :data(d), next(n) {}
    Node(Node* n = nullptr) :next(n) {}
};