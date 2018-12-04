#include<stdio.h>
#include<map>
#include<string.h>
#include <algorithm>
using namespace std;

/*
https://www.cnblogs.com/scidylanpno/p/7470478.html
小Ho决定写个程序把历史书上出现过的皇室名字排序：
首先按英文名字的字典序排序，如果英文名字相同，
再按罗马数字从小到大的顺序排序。
*/
map<char,int> MAP;
void init(){
    MAP['I']=1;
    MAP['V']=5;
    MAP['X']=10;
    MAP['L']=50;
    MAP['C']=100;
    MAP['D']=500;
    MAP['M']=1000;
}

int Trans(char *str){
    int Len=strlen(str);
    int sum=0;
    int i=0;
    while(i<Len)
    {
        if(i<Len-1)
        {
            if(MAP[str[i+1]]>MAP[str[i]])
                sum-=MAP[str[i]];
            else
                sum+=MAP[str[i]];
        }else
            sum+=MAP[str[i]];
        ++i;
    }
    return sum;
}

const int MAXN = 100000+10;
struct word{
    char S[1000];
    char xx[1000];
    int num;
}W[MAXN];

bool cmp(const word &a,const word &b){
    int pos=strcmp(a.S,b.S);
    if(pos!=0)  return pos<0;
    return a.num<b.num;
}

char str[1000];

int main(){
    init();
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%s%s",W[i].S,W[i].xx);
        W[i].num=Trans(W[i].xx);
    }
    sort(W,W+N,cmp);
    for(int i=0;i<N;++i)
    {
        printf("%s %s\n",W[i].S,W[i].xx);
    }
    return 0;
}
