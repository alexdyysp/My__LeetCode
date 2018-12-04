#include<stdio.h>
#include<iostream>
using namespace std;
/*
将一个排好序的数组除重
时间复杂度：n^2;
空间复杂度: 1;
*/
int fun_answer(int x[],int len){
    for(int i=0;i<len;i++){
        for(int j=i+1;j<len;j++){
            if(x[j]==x[i]){
                for(int k=j+1;k<len;k++)
                    x[k-1]=x[k];//后续数组依次往前移移位
                len--;    //数组长度-1
                j--;    //重复点再次进行查重
            }
        }
    }
    return len;
}
int main()
{
    int n,i,m;
    while(true){
        int n = 0;
        cin>>n;
        int *c;
        c=new int[n];
        for (i=0;i<n;i++)
        {
            cin >> c[i]; // 键盘输入 n 个数
        }
        m = fun_answer(c,n);
        for(i = 0;i < m;i ++)
            cout<<c[i]<<" ";
        cout<<endl;
        delete []c;
    }
    return 0;
}
