/*
 原地倒转字符串，允许O(1)space
 使用迭代器
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<char> s = {'a','b','c'};

    if(s.size()<2) return 0;
    vector<char>::iterator ibeg=s.begin();
    vector<char>::iterator iend=s.end()-1;
    while(ibeg<iend){
        char temp = *ibeg;
        *ibeg = *iend;
        *iend = temp;
        ibeg++;
        iend--;
    }
    for(auto i:s)
        cout<<i<< " ";
    return 0;
}