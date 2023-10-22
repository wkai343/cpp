#include"Status.h"
#include"Node.h"
template<class DataType>
class LinkList {
private:
    Node<DataType>* head;
    int length;
public:
    LinkList() :length(0) {
        head = new Node<DataType>;
    }
    LinkList(const DataType* data, int s) :length(s) {
        head = new Node<DataType>;
        Node<DataType>* p = head;
        for(int i = 0; i < s; ++i) {
            p->next = new Node<DataType>(data[i]);
            p = p->next;
        }
    }
    ~LinkList() {
        clear();
        delete head;
    }
    int getLength() const {
        return length;
    }
    bool isEmpty() const {
        return length == 0;
    }
    void clear() {
        Node<DataType>* p = head;
        while (p->next != nullptr) {
            head = head->next;
            delete p;
            p = head;
        }
        length = 0;
    }
    Status insertElem(const DataType& e) {
        Node<DataType>* p = head;
        while(p->next != nullptr) {
            p = p->next;
        }
        p->next = new Node<DataType>(e);
        ++length;
        return SUCESESS;
    }
    Status insertElem(const DataType& e, int n) {
        if(n < 0 || n > length) return INVALID;
        Node<DataType>* p = head;
        for(int i = 0; i < n; ++i) {
            p = p->next;
        }
        p->next = new Node<DataType>(e, p->next);
        return SUCESESS;
    }
    void deleteNext(Node<DataType>* p) {
        Node<DataType>* t = p->next;
        p->next = t->next;
        delete t;
        --length;
    }
    Status deleteN(int n) {
        if(length == 0) return UNDER_FLOW;
        if(n < 0 || n >= length) return INVALID;
        Node<DataType>* p = head;
        for(int i = 0; i < n; ++i) {
            p = p->next;
        }
        deleteNext(p);
        return SUCESESS;
    }
    Status deleteElem(const DataType& e) {
        if(length == 0) return UNDER_FLOW;
        Node<DataType>* p = head;
        while(p->next != nullptr) {
            if(p->next->data == e) {
                deleteNext(p);
                continue;
            }
            p = p->next;
        }
        return SUCESESS;
    }
    Status setElem(const DataType& e, int n) {
        if (n < 0 || n >= length) return INVALID;
        Node<DataType>* p = head;
        for (int i = 0; i < n; ++i) {
            p = p->next;
        }
        p->next->data = e;
        return SUCESESS;
    }
    Node<DataType>* locateN(int i) const {
        if(i<0 || i > length) return nullptr;
        Node<DataType>* p = head->next;
        for(int j = 0; j < i; ++j) {
            p = p->next;
        }
        return p;
    }
    int locateElem(const DataType& e) const {
        Node<DataType>* p = head;
        int count = 0;
        while(p->next != nullptr) {
            p = p->next;
            if(p->data == e) return count;
            ++count;
        }
        return -1;
    }
    Status mergeList(const LinkList& l) {
        if(l.length == 0) return SUCESESS;
        Node<DataType>* p = head, * q = l.head;
        while(p->next != nullptr) {
            p = p->next;
        }
        while(q->next != nullptr) {
            q = q->next;
            p->next = new Node<DataType>(q->data);
            p = p->next;
        }
        length += l.length;
        return SUCESESS;
    }
    // int countElem(const DataType& e) {
    //     int count = 0;
    //     Node<DataType>* p = head;
    //     while(p = p->next, p != nullptr) {
    //         if(p->data == e) ++count;
    //     }
    //     return count;
    // }
    template<class DataStruct>
    friend void lTraverse(const DataStruct& d);
};