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

