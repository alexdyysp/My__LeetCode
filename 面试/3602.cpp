/*
input:
6
1 1 1 2 2 2
output:
2

将不同种类小球装进output个篮子里，每个篮子球数相等
思路:
求最大公约数
*/
#include<bits/stdc++.h>
using namespace std;
int maxgongyur(map<int,int> BMap){
    int k,n;
    long a,b,c,r,m[100];
    n=BMap.size();
    for(k=1;k<=n;k++){
        m[k] = BMap[k];
    }
    b=m[0];
  for(k=1;k<=n-1;k++)
  { a=m[k];
    if(a<b)
      { c=a;a=b;b=c;}
    r=a%b;
    while(r!=0)
      { a=b;
        b=r;
        r=a%b;
      }
  }
    return b;
}
int zhengli(vector<int>& ball, int N){
    int result=0;
    int Z=0;
    map<int,int> BMap;
    for(int i=0;i<N;i++){
        BMap[ball[i]]++;
    }
    result = maxgongyur(BMap);
    if(N%result == 0)
        return N/result;
    else
        return 0;
}


int main(){
    int N;
    int res;
    cin>>N;
    vector<int> ball(N,0);
    for(int i=0;i<N;i++)
        cin >> ball[i];
    sort(ball.begin(),ball.end());
    res = zhengli(ball, N);
    cout<<res<<endl;
    return 0;
}
