#include <bits/stdc++.h>
using namespace std;

int min(int a, int  b , int c){
	if( a < b ){
		return (a<c)?a:c;
	}
	else{
		return (b<c)?b:c;
	}
}

void StrSplit(const string& src, const string& sep, vector<string>& dst){
    string s;
    for (string::const_iterator it = src.begin(); it != src.end(); it++){
        if (sep.find(*it) != string::npos){
            if (s.length()) dst.push_back(s);
            s.clear();
        }
        else
            s += *it;
    }

    if (s.length())
        dst.push_back(s);
}

int main(){
    string RC;
    cin>>RC;
    vector<string> RCstr;
    StrSplit(RC, ",", RCstr);
    int R = atoi(RCstr[0].c_str());
    int C = atoi(RCstr[1].c_str());
    cin.ignore();
    vector<vector<int> > M(R, vector<int>(C, 0));
    vector<vector<string> > S;
    vector<vector<int> > dp(R, vector<int>(C, 0));
    for(int i=0; i<R; i++){
        string input;
        getline(cin, input);
        vector<string> tmp;
        StrSplit(input, ",", tmp);
        for(int j=0; j<C; j++){
            if(tmp[j]=="1")
                dp[i][j] = 1;
            else
                dp[i][j] = 0;
        }
    }
    /*
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            cout<<M[i][j];
    */
    for(int i=1; i<R; i++){
        for(int j=1; j<C; j++){
            if(dp[i][j]!=0)
                dp[i][j] += min(dp[i-1][j], dp[i-1][j-1], dp[i][j-1]);
        }
    }

    int m = dp[0][0];
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++){
            if(dp[i][j]>m)
                m = dp[i][j];
        }

    cout<<m*m<<endl;
    return 0;
}
