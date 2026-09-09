#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool check[101][101];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    int r = maps.size();
    int c = maps[0].length();
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(maps[i][j]=='X'||check[i][j]){
                continue;
            }
            check[i][j]=true;
            int sum = maps[i][j]-'0';
            vector<pair<int,int>>vec;
            vec.push_back({i,j});
            
            while(!vec.empty()){
                pair<int,int> cur = vec.back();
                vec.pop_back();
                
                for(int k=0;k<4;k++){
                    int nx = cur.first+dx[k];
                    int ny = cur.second+dy[k];
                    if(nx<0||ny<0||nx>=r||ny>=c||check[nx][ny]||maps[nx][ny]=='X'){
                        continue;
                    }
                    else{
                        sum+=maps[nx][ny]-'0';
                        check[nx][ny]=true;
                        vec.push_back({nx,ny});
                    }
                }
                
            }
            answer.push_back(sum);
        }
    }
    if(answer.empty()){
        answer.push_back(-1);
    }
    else{
        sort(answer.begin(),answer.end());
    }
    return answer;
}