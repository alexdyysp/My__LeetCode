/*
思科面试: 输出字符串所有的不重复子串
 当时没做好，一开始想用dfs遍历一个01二叉树，后来发现想复杂了
 思路： 只需要用substr遍历，然后用去重即可
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s ;
    cin>>s;
    vector<string> result;
    for(int i=0; i<s.size(); i++)
        for(int j=1; j<s.size()-i; j++){
            string temp = s.substr(i,j);
            if (find(result.begin(), result.end(), temp) == result.end())
                result.push_back(temp);
        }
    for(auto i:result)
        cout<< i << " ";
    return 0;
}