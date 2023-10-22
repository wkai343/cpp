#include"Node.h"
#include"Status.h"
template<class DataType>
class CirLinkList {
private:
    Node<DataType>* head;
    int length;
public:
    CirLinkList() {
        head = new Node<DataType>(head);
    }
    CirLinkList(DataType* data, int n) :length(n) {
        head = new Node<DataType>;
        Node<DataType>* p = head;
        for(int i = 0; i < n; ++i) {
            p->next = new Node<DataType>(data[i], head);
        }
    }
    ~CirLinkList() {
        Node<DataType>* p = head;
        for(int i = 0; i <= length; ++i) {
            head = head->next;
            delete p;
            p = head;
        }
    }
    int getLength() const {
        return length;
    }
    bool isEmpty() const {
        return length == 0;
    }
    void clear() {
        Node<DataType>* p = head->next,* q = p;
        head->next = head;
        for (int i = 0; i < length; ++i) {
            q = q->next;
            delete p;
            p = q;
        }
        length = 0;
    }
};