#include<stdio.h>
#include<iostream>
using namespace std;
/*
找出一门成绩大于等于90.其他成绩小于等于70的偏科生
*/
int find_student(int n,int **list)
{
    int num = 0;
    for(int i=0;i<n;i++){
        int j = 0;
        if(list[i][j]>=90 && list[i][j+1]<=70 && list[i][j+2]<=70)
            num += 1;
        if(list[i][j]<=70 && list[i][j+1]>=90 && list[i][j+2]<=70)
            num += 1;
        if(list[i][j]<=70 && list[i][j+1]<=70 && list[i][j+2]>=90)
            num += 1;
    }
    return num;
}
int main(){
    int num_stu;
    while(true){
        cin>>num_stu;
        if(num_stu<1||num_stu>10000) continue;
        int **l;
        l = new int*[num_stu];
        for(int i=0;i<num_stu;i++)
            l[i]=new int[3];
        for(int i=0;i<num_stu;i++){
            for(int j=0;j<3;j++)
                cin>>l[i][j];
        }
        cout<<find_student(num_stu,l)<<endl;
    }
    return 0;
}
