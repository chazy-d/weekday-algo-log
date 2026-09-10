#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    unordered_map<string,int> mp;
    vector<string>vec;
    
    for(int i=0;i<cities.size();i++){
        string s = "";
        for(int j=0;j<cities[i].length();j++){
            if('a'<=cities[i][j]&& cities[i][j]<='z'){
                s+='A'+(cities[i][j]-'a');
            }
            else{
                s+=cities[i][j];
            }
        }
        if(cacheSize==0){
            answer+=5;
            continue;
        }
        
        if(mp[s]==0){
            if(vec.size()>=cacheSize){
                mp[vec[0]]=0;
                vec.erase(vec.begin());
            }
            vec.push_back(s);
            answer+=5;
            mp[s]=1;
        }
        else{
            answer+=1;
            for(int j=0;j<vec.size();j++){
                if(vec[j]==s){
                    vec.erase(vec.begin()+j);
                    break;
                }
            }
            vec.push_back(s);
        }
        
    }
    
    return answer;
}