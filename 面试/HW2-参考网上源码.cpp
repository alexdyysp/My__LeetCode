#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> path;
vector<vector<pair<int,int>>> allpath;
int X,Y,Z,W;
int N,M;
void dfs(vector<vector<int>>& Map, vector<vector<int>>& Mappath, int x, int y, int lasth) {
    // 找到目的地
	if (x == Z && y == W && Map[x][y]>lasth) {
		path.push_back(make_pair(x, y));
		allpath.push_back(path);
		path.pop_back();
		return;
	}
	// 出界
	if (x<0 || x>=N || y<0 || y>M) return;
	if (Mappath[x][y]) return;  //访问过则返回
	if (Map[x][y]<=lasth) return;
	path.push_back(make_pair(x, y));
	Mappath[x][y] = 1;
    dfs(Map, Mappath, x+1, y, Map[x][y]);
    dfs(Map, Mappath, x-1, y, Map[x][y]);
    dfs(Map, Mappath, x, y-1, Map[x][y]);
    dfs(Map, Mappath, x, y+1, Map[x][y]);
	//4
	Mappath[x][y] = 0;
	path.pop_back();
	return ;
}

int main(){
    cin>>N>>M;
    vector<vector<int>> Map(N, vector<int>(M,0));
    vector<vector<int>> Mappath(N, vector<int>(M,0));
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>Map[i][j];
    cin>>X>>Y>>Z>>W;
    dfs(Map,Mappath,X,Y,-1);
    int result = allpath.size();
    cout<<result<<endl;
}
