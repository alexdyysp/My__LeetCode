#include <bits/stdc++.h>
using namespace std;
/*
/*
窗口只能显示N个字符
输入：abaabaabaaaaa
字符串只能显示: abaabaaba

给你一连串字符串，求出可以反复copypaste形成的上述显示
a
aba
abb
ba
...
...

时间复杂度要求很高，我加了很多预判才过的
*/
*/
int main(){
    int N;
    cin>>N;
    string src;
    cin>>src;
    int result=0;
    string recstring;
    for(int i=0;i<src.length();i++)
        if(recstring.find(src[i])==string::npos)
            recstring += src[i];
    int srcl = recstring.length();
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        string ssrc;
        // 元素不一致
        for(int i=0;i<s.length();i++)
            if(ssrc.find(s[i])==string::npos)
                ssrc += s[i];
        if(ssrc.length()!=srcl) continue;
        //仅有1元素
        if(ssrc.length()==1&&srcl==1&&ssrc==recstring) {
            result++;
            continue;
        }
        string stmp;
        if(src.substr(0,s.length())!=s) continue;
        for(int i=0;i<=N/s.length();i++){
            stmp += s;
        }
        //cout<<stmp.substr(0,9)<<endl;
        if(stmp.substr(0,N)==src) result++;
    }
    cout<<result<<endl;
    return 0;
}
