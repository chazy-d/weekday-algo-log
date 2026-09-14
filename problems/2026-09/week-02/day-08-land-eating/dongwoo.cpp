#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[100001][4];

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int n = land.size();
    
    for(int i=0;i<4;i++){
        dp[0][i] = land[0][i];
    }
    
    for(int i=1;i<n;i++){
        for(int j=0;j<4;j++){
            int mx = 0;
            for(int k=0;k<4;k++){
                if(k!=j){
                    mx = max(mx,dp[i-1][k]);
                }
            }
            dp[i][j] = mx + land[i][j];
        }
    }
    
    for(int i=0;i<4;i++){
        answer = max(answer,dp[n-1][i]);
    }

    return answer;
}