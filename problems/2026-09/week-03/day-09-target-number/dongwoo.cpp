#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        if(cur.first==numbers.size()){
            if(target == cur.second){
                answer++;
            }
            continue;
        }
        
        q.push({cur.first+1, cur.second + numbers[cur.first]});
        q.push({cur.first+1, cur.second - numbers[cur.first]});
    }
    
    
    return answer;
}