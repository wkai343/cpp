#include <iostream>
#include <string>
using namespace std;

int find1(string_view,string_view);//BF1
int find2(string_view,string_view);//BF2
int find3(string_view,string_view,int*);//KMP
int* getNext1(string_view);//暴力next数组
int* getNext2(string_view);//线性next数组
int* nextVal(string_view,int*);//nextval数组
void traverse(int*,int);//遍历next数组

int main() {
    string s1 = "aabaac", s2 = "abababc";
    // cout<<find1(s1, s2)<<endl;
    // cout<<find2(s1, s2)<<endl;
    int *p = getNext2(s2);
    // cout<<find3(s1, s2, nextVal(s2, p)) << endl;
    for(int i = 0; i < s2.length(); ++i) {
        cout << p[i] << ' ';
    }
    cout << endl;
    delete[] p;//删除堆内存的数组
    return 0;
}
int find1(string_view s1, string_view s2) {
    int len1 = s1.length(), len2 = s2.length();
    if (!len1 || !len2) return -1;
    int i = 0, j = 0;
    while (len1 - i >= len2 - j) {
        while (s2[j] == s1[i] && j < len2) {
            ++i, ++j;
        }
        if (j < len2) {
            i = i - j + 1;
            j = 0;
            continue;
        }
        return i - len2 + 1;  
    }
    return -1;
}
int find2(string_view s1, string_view s2) {
    int i = 1, j = 1;
    int len1 = s1.length(), len2 = s2.length();
    if(!len1 || !len2) return -1;
    while(i <= len1 && j <= len2 && len1 - i >= len2 - j) {
        if(s1[i - 1] == s2[j - 1]) { ++i, ++j; }
        else {
            i = i - j + 2;
            j = 1;
        }
    }
    return j > len2 ? i - len2 : -1;
}
int find3(string_view s1, string_view s2, int *next) {
    int i = 0, j = 0;
    int len1 = s1.length(), len2 = s2.length();
    if(!len1 || !len2) return -1;
    while(i < len1 && j < len2 && len1 - i >= len2 - j) {
        if(s1[i] == s2[j]) { i++, j++; }
        else {
            j >= 0 ? j = next[j] : j=0, i-= j;
        }

    }
    return j == len2 ? i - len2 + 1 : -1;
}
int* getNext1(string_view s) {
    int l = s.length();
    int* next = new int[l];
    if(l == 1) next[0] = -1;
    else if(l == 2) {
        next[0] = -1;
        next[1] = 0;
    }
    else {
        next[0] = -1, next[1] = 0;
        for(int i = 2; i < l; ++i) {
            int count = 0, max = 0;
            for(int j = 1; j < i; ++j) {
                for(int k = 0; k < j; ++k) {
                    if(s[k] == s[i-j+k]) ++count;
                    else{
                        count = 0;
                        break;
                    }
                }
                max = count ? count : max;
                count = 0;
            }
            next[i] = max;
        }
    }
    return next;
}
int* getNext2(string_view s) {
    int l = s.length();
    int* next = new int[l];
    if(l == 1) next[0] = -1;
    else if(l == 2) {
        next[0] = -1;
        next[1] = 0;
    }
    else {
        next[0] = -1, next[1] = 0;
        for(int i = 2; i < l; ++i) {
            int temp = i-1;
            while(s[i-1] != s[next[temp]] && next[temp] != -1) {
                temp = next[temp];
            }
            next[i] = next[temp] + 1;
        }
    }
    return next;
}
int* nextVal(string_view s, int* next) {
    for(int i = 2; i < s.length(); ++i) {
        if(!next[i]) continue;
        if(s[i] == s[next[i]]) next[i] = next[s[i]];
    }
    return next;
}
void traverse(int* next, int n) {
    for(int i = 0; i < n; ++i) {
        cout<<next[i]<<' ';
    }
    cout << endl;
}