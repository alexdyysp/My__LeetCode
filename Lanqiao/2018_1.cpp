/*
    标题：分数

    1/1 + 1/2 + 1/4 + 1/8 + 1/16 + .... 
    每项是前一项的一半，如果一共有20项,
    求这个和是多少，结果用分数表示出来。
    类似：
    3/2
    当然，这只是加了前2项而已。分子分母要求互质。

    注意：
    需要提交的是已经约分过的分数，中间任何位置不能含有空格。
    请不要填写任何多余的文字或符号。
*/

#include<stdio.h>
#include<cmath>
#include<iostream>
using namespace std;

int main(){
    int sum_1 = 0;
    for(int i=0; i<20; i++){
        sum_1 = sum_1 + pow(2, i);
    }
    int sum_2 = pow(2,19);
    cout<<sum_1<<"/"<<sum_2<<endl;
    int min = sum_2;
    for(int i = 2; i<=min;i++){
        while(sum_1%i == 0 && sum_2%i == 0){
            sum_1 = sum_1/i;
            sum_2 = sum_2/i;
            min = min/i;
        }
    }
    cout<<sum_1<<"/"<<sum_2<<endl;
    return 0;
}

