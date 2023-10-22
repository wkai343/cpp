#include"Status.h"
#include"Node.h"
template<class DataType>
class OrderedLinkList {
private:
    Node<DataType>* head;
    int length;
public:
    OrderedLinkList() :length(0) {
        head = new Node<DataType>;
    }
    OrderedLinkList(const DataType* data, int n) :length(n) {
        head = new Node<DataType>;
        for(int i = 0; i < n; ++i) {
            insertElem(data[i]);
        }
    }
    ~OrderedLinkList() {
        clear();
        delete head;
    }
    bool isEmpty() const {
        return length == 0;
    }
    int getLength() const {
        return length;
    }
    void clear() {
        Node<DataType>* p = head;
        while(p->next != nullptr) {
            head = head->next;
            delete p;
            p = head;
        }
        length = 0;
    }
    Status insertElem(const DataType& e) {
        Node<DataType>* p = head;
        while(p->next != nullptr && p->next->data < e) {
            p=p->next;
        }
        Node<DataType>* n = new Node<DataType>(e, p->next);
        p->next = n;
        ++length;
        return SUCESESS;
    }
    void deleteNext(Node<DataType>* p) {
        Node<DataType>* t = p->next;
        p->next = t->next;
        delete t;
    }
    Status deleteElem(const DataType& e) {
        if(length == 0) return UNDER_FLOW;
        Node<DataType>* p = head,* q = nullptr;
        while(p->next != nullptr && p->next->data != e) p = p->next;
        do deleteNext(p);
        while(p->next->data == e);
        return SUCESESS;
    }
    Status mergeList(const OrderedLinkList& l) {
        if (l.length == 0) return SUCESESS;
        Node<DataType>* p = l.head;
        while (p->next != nullptr) {
            p = p->next;
            insertElem(p->data);
        }
        length += l.length;
        return SUCESESS;
    }
    template<class DataStruct>
    friend void lTraverse(const DataStruct& d);
};