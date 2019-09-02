#include <bits/stdc++.h>
using namespace std;
/*

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
