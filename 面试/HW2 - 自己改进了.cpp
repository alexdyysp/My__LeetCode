/*
输入：
4 5
0 1 0 0 0
0 2 3 0 0
0 0 4 5 0
0 0 7 6 0
0 1 3 2
输出：
2

一个山地，数组值是高度，求出有多少路径
要求每一步都比上次要高

当时没做出来，但是之后做出来了，原因：
1. 不知道怎么处理访问标记矩阵，需要有还原操作
2. 判断顺序很重要，需要仿佛思考，一般走到目的地的判断放第一个
/*

#include<bits/stdc++.h>
using namespace std;
int result = 0;
void dfscount(vector<vector<int>>& Map, vector<vector<int>>& Mappath,int Z, int W, int tempx, int tempy, int lasth){
    if(tempx == Z && tempy == W && lasth < Map[tempx][tempy]){
        result++;
    }
    if(tempx<0 || tempx>= Map.size() || tempy <0 || tempy > Map[0].size()) return ;
    int temph = Map[tempx][tempy];
    if(lasth>=temph) return ;
    if(Mappath[tempx][tempy] == 1) return ;
    Mappath[tempx][tempy] = 1;
    //cout<<tempx<<" "<<tempy<<endl;
    dfscount(Map,Mappath,Z,W,tempx+1,tempy,temph);
    dfscount(Map,Mappath,Z,W,tempx-1,tempy,temph);
    dfscount(Map,Mappath,Z,W,tempx,tempy+1,temph);
    dfscount(Map,Mappath,Z,W,tempx,tempy-1,temph);
    Mappath[tempx][tempy] = 0;  //最关键的一步！！！要想求出所有路径，需要把访问标记归0！！！
}
int main(){
    int N,M;
    cin>>N>>M;
    vector<vector<int>> Map(N, vector<int>(M,0));
    vector<vector<int>> Mappath(N, vector<int>(M,0));
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>Map[i][j];
    int X,Y,Z,W;
    cin>>X>>Y>>Z>>W;
    dfscount(Map,Mappath,Z,W,X,Y+1,Map[X][Y]);
    dfscount(Map,Mappath,Z,W,X+1,Y,Map[X][Y]);
    dfscount(Map,Mappath,Z,W,X-1,Y,Map[X][Y]);
    dfscount(Map,Mappath,Z,W,X,Y-1,Map[X][Y]);
    cout<<result<<endl;
}
