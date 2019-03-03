#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    int num_2=0;
    int num_5=0;
    int a[10][10];
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++){
            cin>>a[i][j];
    }
    // 贴上数据
    int sum=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            while(a[i][j]%10==0){
                sum++;
                a[i][j]/=10;//含有末尾0的话，sum直接+1; 
            }
            while(a[i][j]%2==0){
                num_2++;
                a[i][j]/=2;
            }
            while(a[i][j]%5==0){
                num_5++;
                a[i][j]/=5;
            }
        }
    }
    cout<<sum+((num_2<num_5)?num_2:num_5)<<endl;
    return 0;
}
