#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct pos{
    int x;
    int y;
    int len;
    pos(int x,int y,int len){
        this->x=x;
        this->y=y;
        this->len=len;
    }
};

bool visited[101][101];

int solution(vector<string> board) {
    int answer = 0;
    
    pair<int,int> goal;
    pair<int,int> starts;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].length();j++){
            if(board[i][j]=='G'){
                goal = {i,j};
                break;
            }
            else if(board[i][j]=='R'){
                starts = {i,j};
            }
        }
    }
    
    queue<pos> q;
    q.push(pos(starts.first,starts.second,0));
    visited[starts.first][starts.second] = true;
    while(!q.empty()){
        
        pos cur = q.front();
        q.pop();
        int curx = cur.x;
        int cury = cur.y;
        int len = cur.len;
        if(goal == pair(curx,cury)){
            answer = len;
            break;
        }
        
        //go to left
        int nextX = curx;
        int nextY = cury;
        while(1){
            if(nextY-1<0){
                break;
            }
            else if(board[nextX][nextY-1]=='D'){
                break;
            }
            nextY--;
        }
        if(!visited[nextX][nextY]){
            q.push(pos(nextX,nextY,len+1));
            visited[nextX][nextY] = true;
        }
        
        //go to up
        nextX = curx;
        nextY = cury;
        while(1){
            if(nextX-1<0){
                break;
            }
            else if(board[nextX-1][nextY]=='D'){
                break;
            }
            nextX--;
        }
        if(!visited[nextX][nextY]){
            q.push(pos(nextX,nextY,len+1));
            visited[nextX][nextY] = true;
        }
        
        //go to right
        nextX = curx;
        nextY = cury;
        while(1){
            if(nextY+1>=board[0].length()){
                break;
            }
            else if(board[nextX][nextY+1]=='D'){
                break;
            }
            nextY++;
        }
        if(!visited[nextX][nextY]){
            q.push(pos(nextX,nextY,len+1));
            visited[nextX][nextY] = true;
        }
        
        //go to down
        nextX = curx;
        nextY = cury;
        while(1){
            if(nextX+1>=board.size()){
                break;
            }
            else if(board[nextX+1][nextY]=='D'){
                break;
            }
            nextX++;
        }
        if(!visited[nextX][nextY]){
            q.push(pos(nextX,nextY,len+1));
            visited[nextX][nextY] = true;
        }
        
        
    }
    if(answer==0){
        answer=-1;
    }
    
    return answer;
}