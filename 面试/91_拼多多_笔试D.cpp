#include <bits/stdc++.h>
using namespace std;
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
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    map<int,int> dict;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=m;j++){
            int tmp = i*j;
            if(dict.count(tmp))
                dict[tmp]++;
            else{
                dict[tmp]=1;
            }
        }
    //sort(matrix.begin(),matrix.end(),greater<int>());

    //for (map<int,int>::iterator it = dict.begin(); it != dict.end(); it++)
     //   cout << it->first << ':' << it->second << '\n';
    int topn;
    for (map<int,int>::reverse_iterator it = dict.rbegin(); it != dict.rend(); it++){
        //cout << it->first << ':' << it->second << '\n';
        if(k<=0) break;
        k -= it->second;
        topn = it->first;
    }
    cout<<topn<<endl;
    return 0;
}
