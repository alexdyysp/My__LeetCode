#include<stdio.h>
#include<iostream>
using namespace std;
/*
һ���ּ���ľ����ÿ�������X��ľ��������X����
ֱ��ľ�����Ⱥ�Ϊ0Ϊֹ
*/
void cut_stick(int N,int s[]){
    int min = s[0];
    int M=N;
    int stick_sum=0;
    for(int i=0;i<N;i++){//find min length stick
        if(min>s[i])
            min = s[i];
    }
    for(int i=0;i<N;i++){
        s[i] = s[i] - min;//cut stick
        if(s[i]==0){
            M -= 1;
        }
    }
    for(int i=0;i<N;i++){//delete stick
        if(s[i]==0){
            s[i]=s[i+1];
        }
    }

    for(int i=0;i<M;i++)//���
        stick_sum += s[i];
    cout<<stick_sum<<endl;
    if(M!=0)
        cut_stick(M,s);
}
int main(){
    int N;
    while(true){
        cin>>N;
        int *s;
        s = new int[N];
        for (int i=0;i<N;i++)
            cin >> s[i]; // �������� n ����
        cut_stick(N,s);
    }
    return 0;
}
