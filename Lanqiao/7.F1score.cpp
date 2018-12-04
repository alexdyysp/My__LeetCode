#include<stdio.h>
#include<iostream>
using namespace std;
/*
2
+ +
+ -
检测预测和实际结果的正确率，输出格式'50.00%'
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
                cin >> s[i][j]; // 键盘输入 n 个数
        cout.fill('0'); //将多余的空格用0填充
        cout.setf(ios::showpoint); //将小数精度后面的0显示出来
        cout.precision(4); //设置输出精度，保留有效数字
        cout<<F1score(N,s)<<"%"<<endl;
        delete []s;
    }
    return 0;
}
