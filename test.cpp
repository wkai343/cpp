#include <iostream>
#include <list>
int main() {
    std::list<int> l(5);
    std::list<int>::iterator it = l.begin();
    for (int i = 0; i < 5; i++) {
        *it = i;
        it++;
    }
    for (it = l.begin(); it != l.end(); it++) {
        std::cout << *it << std::endl;
    }
    return 0;
}