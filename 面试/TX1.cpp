#include<bits/stdc++.h>
using namespace std;
int erase01(char input[], int a){
    int num_0=0;
    int num_1=0;
    for(int i=0;i<a;i++){
        if(input[i]=='0') num_0++;
        if(input[i]=='1') num_1++;
    }
    cout<<num_0<<num_1<<endl;
    return abs(num_0 - num_1);
}
int main(){
    int a;
    cin>>a;
    char input[a];
    for(int i=0;i<a;i++)
        cin>>input[i];
    int num = erase01(input,a);
    cout<<num<<endl;
}
