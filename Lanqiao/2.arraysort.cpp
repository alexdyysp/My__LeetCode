#include<stdio.h>
#include<iostream>
using namespace std;
/*
��һ���ź�����������
ʱ�临�Ӷȣ�n^2;
�ռ临�Ӷ�: 1;
*/
int fun_answer(int x[],int len){
    for(int i=0;i<len;i++){
        for(int j=i+1;j<len;j++){
            if(x[j]==x[i]){
                for(int k=j+1;k<len;k++)
                    x[k-1]=x[k];//��������������ǰ����λ
                len--;    //���鳤��-1
                j--;    //�ظ����ٴν��в���
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
            cin >> c[i]; // �������� n ����
        }
        m = fun_answer(c,n);
        for(i = 0;i < m;i ++)
            cout<<c[i]<<" ";
        cout<<endl;
        delete []c;
    }
    return 0;
}
