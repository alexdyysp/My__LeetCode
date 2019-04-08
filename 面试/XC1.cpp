#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
int main(){
    set<char> s;
    vector<char> vc;
    char c;
    string line;
    getline(cin, line);
    stringstream ss(line);
    while(ss>>c){
        vc.push_back(c);
    }
    for(int i=0;i<vc.size();i++){
        if(vc[i]!=','){
            if(s.count(vc[i])){
                cout<<"true"<<endl;
                return 0;
            }
            s.insert(vc[i]);
        }
    }
    cout<<"false"<<endl;;
}
