#include <bits/stdc++.h>
using namespace std;

int dfs(int n, int count, int *dp) {
    if (!n) return count;
    int c = 0;
    if ((c = dp[n - 1]) != 0) { 
        return count + c;       
    }
    int result = INT_MAX;
    int j = (int) sqrt(n);
    for (int i = j; i >= (j / 2 + 1); i--) {
        int num = n - pow(i, 2); 
        int c = dfs(num, count + 1, dp);
        result = min(result, c);
    }
    dp[n - 1] = result - count; 
    return result;
}
int numSquares(int n) {
    int dp[n];
    memset(dp, 0, n * sizeof(n));
    int result = dfs(n, 0, dp);
    return result;
}

int main(){
    int N;
    cin>>N;
    cout<<numSquares(N)<<endl;
}
