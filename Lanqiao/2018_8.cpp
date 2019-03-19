#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector <char>> &sea, vector<vector <int>> &tmp, int x, int y,int line){
    if(x<0||x>=line||y<0||y>=line) return;
    if(sea[x][y] == '#' && tmp[x][y]!=1){
        tmp[x][y] = 1;
        dfs(sea, tmp, x+1, y, line);
        dfs(sea, tmp, x-1, y, line);
        dfs(sea, tmp, x, y+1, line);
        dfs(sea, tmp, x, y-1, line);
    }
}

int cou(vector<vector <char>> &sea, vector<vector <int>> &tmp, int line){
    int num = 0;
    for(int i=0; i<line; i++)
        for(int j=0; j<line; j++){
            if(sea[i][j] == '#' && tmp[i][j] != 1){
                num++;
                dfs(sea, tmp, i, j, line);
            }
        }
    return num;
}

void shift(vector<vector <char>> &sea, vector<vector <int>> &tmp, int line){
    for(int i=0; i<line; i++)
        for(int j=0; j<line; j++){
            if(sea[i][j] == '#' && (tmp[i+1][j]==0 || tmp[i-1][j]==0 || tmp[i][j+1]==0 || tmp[i][j-1]==0)){
                sea[i][j] = '.';
                tmp[i][j] = -1;
            }
        }
    for(int i=0; i<line; i++)
        for(int j=0; j<line; j++)
                tmp[i][j]=0;
}




int main(){
    int line;
    cin>>line;
    vector<vector<char> > sea(line, vector<char>(line,'.'));
    vector<vector<int> > tmp(line, vector<int>(line,0));
    for(int i=0; i<line; i++)
        for(int j=0; j<line; j++)
            cin>>sea[i][j];

    int n;
    n = cou(sea, tmp, line);
    cout<<n<<endl;
    shift(sea, tmp, line);
    for(int i=0; i<line; i++){
        for(int j=0; j<line; j++)
            cout<<sea[i][j];
        cout<<endl;
    }
    n = cou(sea, tmp, line);
    cout<<n<<endl;
    for(int i=0; i<line; i++){
        for(int j=0; j<line; j++)
            cout<<tmp[i][j];
        cout<<endl;
    }
}
