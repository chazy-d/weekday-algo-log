#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> board) {
    int n=board.size(), m=board[0].size();
    vector<vector<int>> dist(n,vector<int>(m,-1));
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(board[i][j]=='R'){
                dist[i][j] = 0;
                q.push({i, j});
            }
    int X[]={-1,1,0,0}, Y[]={0,0,-1,1};
    while(!q.empty()){
        auto [x,y]=q.front(); q.pop();
        if(board[x][y]=='G') return dist[x][y];
        for(int i=0;i<4;++i){
            int xx=x, yy=y;
            while(1){
                int dx=xx+X[i], dy=yy+Y[i];
                if(dx<0||dx>=n||dy<0||dy>=m||board[dx][dy]=='D') break;
                xx=dx; yy=dy;
            }
            if(dist[xx][yy]==-1){
                dist[xx][yy]=dist[x][y]+1;
                q.push({xx,yy});
            }
        }
    }
    return -1;
}
