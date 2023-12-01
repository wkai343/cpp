#include<iostream>
int main() {
    unsigned sum = 0, t = 1;
    int n, count = 1;
    std::cin >> n;
    while(count <= n) {
        t *= count;
        sum += t;
        ++count;
    }
    std::cout << sum;
    return 0;
}