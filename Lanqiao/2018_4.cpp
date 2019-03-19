#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
int main(){
    long long count = 0;
    long long max = 59084709587505;
    for(long i = 0; pow(3,i)<=max; i++)
        for(long j=0; pow(5,j)<=max; j++)
            for(long k=0; pow(7,k)<=max; k++){
                if(pow(3,i)*pow(5,j)*pow(7,k)<=max)
                    count++;
                else
                    break;
            }
    cout<<count<<endl;
}
