#include <string>
#include <vector>

using namespace std;
int answer;
void f(vector<int>& v,int idx,int target,int cur){
     if(idx==(int)v.size()){
         if(target==cur) answer++;
         return;
     }
    f(v,idx+1,target,cur+v[idx]);
    f(v,idx+1,target,cur-v[idx]);
}

int solution(vector<int> numbers, int target) {
    f(numbers,0,target,0);

    return answer;
}