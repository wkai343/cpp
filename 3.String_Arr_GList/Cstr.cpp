#include <iostream>
#include <cstring>
using namespace std;
int main() {
    char s1[] = "Hello",* p;
    p = strchr(s1, 'e');
    p = strstr(s1, "el");
    cout << s1 << ' ' << sizeof(s1) << ' ' << strlen(s1) << endl;
    cout << p << endl;
}