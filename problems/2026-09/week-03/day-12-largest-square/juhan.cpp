#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> board){
    int N=(int)board.size();
    int M=(int)board[0].size();
    int answer=0;
    vector<vector<int>> dp(N,vector<int>(M));
    for(int i=0;i<M;++i){dp[0][i]=board[0][i];answer=max(answer,dp[0][i]);}
    for(int i=0;i<N;++i){dp[i][0]=board[i][0];answer=max(answer,dp[i][0]);}
    for(int i=1;i<N;++i)
        for(int j=1;j<M;++j){
            if(board[i][j]==0)dp[i][j]=0;
            else dp[i][j]=min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1])+1;
            if(answer<dp[i][j])answer=dp[i][j];
        }
    return answer*answer;
}
