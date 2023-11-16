struct BNode {
    char data;
    BNode* left,* right;
    BNode(char ch = '\0', BNode* l= nullptr, BNode* r = nullptr) :data(ch), left(l), right(r) {}
};
class MaxHeap {
private:
    int* elem, size, length;
    void siftUp(int n) {}
    void siftDown(int n) {}
public:
    MaxHeap(int s) :size(s), length(0) {
        elem = new int[size];
    }
    MaxHeap(int* arr, int n) :size(n + 10), length(n) {
        elem = new int[size];
    }
    ~MaxHeap() {
        delete[] elem;
    }
    int getSize() const {
        return size;
    }
    int getLength() const {
        return length;
    }
    bool isEmpty() const {
        return length == 0;
    }
    bool isFull() const {
        return length == size;
    }
    int getTop() const {
        return elem[0];
    }
    void insertElem(int e) {}
    void deleteTop() {}
};
class MinHeap {};