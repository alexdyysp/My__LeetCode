#include<stdio.h>
#include<iostream>
using namespace std;
/*
2
+ +
+ -
���Ԥ���ʵ�ʽ������ȷ�ʣ������ʽ'50.00%'
*/
double F1score(int N,char **List){
    double sum=double(N);
    double wrong = 0;
    for(int i=0;i<N;i++){
        if(List[i][0]!=List[i][1])
            wrong +=1;
    }
    double score = wrong/sum*100;
    return score;
}
int main(){
    int N;
    while(true){
        cin>>N;
        char **s;
        s = new char*[N];
        for(int i=0;i<N;i++)
            s[i]=new char[2];
        for (int i=0;i<N;i++)
            for(int j=0;j<2;j++)
                cin >> s[i][j]; // �������� n ����
        cout.fill('0'); //������Ŀո���0���
        cout.setf(ios::showpoint); //��С�����Ⱥ����0��ʾ����
        cout.precision(4); //����������ȣ�������Ч����
        cout<<F1score(N,s)<<"%"<<endl;
        delete []s;
    }
    return 0;
}
