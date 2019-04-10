/* 输入： 2 abc 123456789
   输出： 12345678 90000000 abc00000
   
   输入 2个字符，输出成8位的一个个串，然后排序输出
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int str_num;
    cin>>str_num;
    int i=0;
    vector<string> ss(0,"");
    for(int i=0;i<str_num;i++){
        string s;
        cin>>s;
        if(s.size()%8 != 0){
            s = s + "00000000";
        }
        while(s.size() >= 8){
            string temp = s.substr(0,8);
            ss.push_back(temp);
            s = s.substr(8);
        }
    }
    sort(ss.begin(),ss.end());
    for(vector<string>::iterator i = ss.begin();i!=ss.end();i++){
        cout<<*i;
        if((i+1) !=ss.end())
            cout<<" ";
    }
    return 0;
}

