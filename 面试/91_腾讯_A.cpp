#include <bits/stdc++.h>
using namespace std;
/*
给出一个数组，
可以按两两不同数字的规则删除这两数字
判断数组能否完全删除。
*/
int main(){
    int a;
    cin>>a;
    while(a--){
        int N;
        cin>>N;
        vector<int> arr(N,0);
        for(int i=0; i<N; i++)
            cin>>arr[i];
        map<int,int> dict;
        // to dict
        for(int i=0;i<N;i++)
            if(dict.count(arr[i]))
                dict[arr[i]]++;
            else
                dict[arr[i]]=1;
        vector<int> tmp;
        for(map<int,int>::iterator it=dict.begin();it!=dict.end();it++){
            tmp.push_back(it->second);
        }

        sort(tmp.begin(), tmp.end(), greater<int>());
        int now=tmp[0];
        for(int i=1;i<tmp.size();i++){
            if(now<0) now+=tmp[i];
            else now -= tmp[i];
        }
        cout<<now<<endl;
        if (now==0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
