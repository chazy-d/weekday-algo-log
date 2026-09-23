#include <bits/stdc++.h>
using namespace std;

int answer=0;
bool visited[8];

void DFS(int k,int cnt,vector<vector<int>>& d){
    answer=max(answer,cnt);
    for(int i=0;i<d.size();++i){
        if(k>=d[i][0]&&!visited[i]){
            visited[i]=true;
            DFS(k-d[i][1],cnt+1,d);
            visited[i]=false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    DFS(k,0,dungeons);
    return answer;
}
