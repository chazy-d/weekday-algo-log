#include <iostream>
#include <cmath>
#include<vector>
using namespace std;

int dp[1001][1001];

int solution(vector<vector<int>> board)
{
    int r = board.size();
    int c = board[0].size();
    int answer = 0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(board[i][j]==0){
                dp[i+1][j+1] = 0;
            }
            else{
                dp[i+1][j+1] = min(min(dp[i+1][j],dp[i][j+1]),dp[i][j]) + 1;
            }
            if(answer < dp[i+1][j+1]){
                answer = dp[i+1][j+1];
            }
        }
    }
    

    return answer*answer;
}




// 기존 풀이
/*
#include <iostream>
#include<vector>
using namespace std;
vector<vector<int>> vec;
int len;
bool checkNum(int x,int y, int width){
    for(int i=x;i<x+width;i++){
        for(int j=y;j<y+width;j++){
            if(vec[i][j]!=1){
                return false;
            }
        }
    }
    return true;
}

int solution(vector<vector<int>> board)
{
    int answer=0;
    vec = board;
    int r = board.size();
    int c = board[0].size();
    if(r>c){
        len = c;
    }
    else{
        len =r;
    }
    
    for(int k=len;k>=1;k--){
        bool returnCheck=false;
        for(int i=0;i<=r-k;i++){
            for(int j=0;j<=c-k;j++){
                if(checkNum(i,j,k)){
                    returnCheck=true;
                    break;
                }
            }
            if(returnCheck){
                break;
            }
        }
        if(returnCheck){
            answer=k*k;
            break;
        }
        
    }

    return answer;
}
*/