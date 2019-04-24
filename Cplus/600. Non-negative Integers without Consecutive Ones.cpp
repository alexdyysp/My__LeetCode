#include<bits/stdc++.h>
using namespace std;
int main(){
    int num = 5;
    string str_num;
    while(num){
        str_num.push_back(num % 2 + '0');
        num /= 2;
    }
    int size = str_num.size();
    vector<int> dp0(size, 0);
    vector<int> dp1(size, 0);
    dp0[0] = 1;
    dp1[0] = 1;
    for(int i = 1; i < size; i++){
        dp0[i] = dp0[i - 1] + dp1[i - 1];
        dp1[i] = dp0[i - 1];
    }
    int cnt = dp0[size - 1] + dp1[size - 1];
    for (int i = size - 2; i >= 0; i--) {
        if (str_num[i] == '1' && str_num[i + 1] == '1') {
            break;
        }
        if (str_num[i] == '0' && str_num[i + 1] == '0') {
            cnt -= dp1[i];
        }
    }
    cout<< cnt;
    return 0;
}
