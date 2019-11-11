#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> s(n, 0);
    for(int i=0; i<n; i++)
       cin>>s[i];
    //
    int result = 0;
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=2; j++){
            dp[i][j]=0;
        }
        dp[i][1]=1;
    }
    for(int i=1;i<=n;i++){
        for(int k=1;k<=i;k++){
            set<int> flag;
            for(int j=i-1; j>=1; j--)
                if(s[j-1]<s[i-1])
                    if(flag.find(s[j-1])==flag.end()){
                        flag.insert(s[j-1]);
                        dp[i][k]=dp[i][k]+dp[j][k-1];
                    }
                else
                    continue;
        }
    }
    set<int> flag;
    for(int i=n;i>=1;i--){
        if(flag.find(s[i-1])==flag.end()){
            flag.insert(s[i-1]);
            for(int j=2;j<=n;j++)
                result += dp[i][j];
        }else
            continue;
    }
    cout<<result<<endl;
}
