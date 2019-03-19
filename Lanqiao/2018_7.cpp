#include <bits/stdc++.h>
using namespace std;
int main(){
    int A,B,C,m;
    string str;
    getline(cin,str);
    sscanf(str.c_str(), "%d %d %d %d", &A,&B,&C,&m);
    int d[A][B][C];
    int i=0,j=0,k=0;
    char c;int temp;
    cin>>d[i][j][k++];
    while ((c = getchar()) != '\n'){
        cin >> temp;
        d[i][j][k++] = temp;
        if(k>=C){
            k=0;
            j++;
        }
        if(j>=B){
            j=0;
            i++;
        }
    }
    int lat,rat,lbt,rbt,lct,rct,ht;
    int count = 0;
    bool flag = false;
    while(!flag){
        string str;
        getline(cin,str);
        sscanf(str.c_str(), "%d %d %d %d %d %d %d", &lat,&rat,&lbt,&rbt,&lct,&rct,&ht);
        //while (cin >> lat>>rat>>lbt>>rbt>>lct>>rct>>ht){
            int i,j,k=0;
            count += 1;
            for(int i=lat-1; i<=rat-1;i++){
                if(flag) break;
                for(int j=lbt-1; j<=rbt-1;j++){
                    if(flag) break;
                    for(int k=lct-1; k<=rct-1;k++){
                        d[i][j][k] -= ht;
                        if(d[i][j][k]<=0){
                            cout<<count<<endl;
                            flag = true;
                            break;
                        }
                    }
                }
            }
    }
    return 0;
}
