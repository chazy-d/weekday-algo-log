#include <bits/stdc++.h>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    if(cacheSize==0) return 5*(int)cities.size();
    deque<string> cache(cacheSize);
    for(int i=0;i<(int)cities.size();++i){
        string s=cities[i];
        transform(s.begin(),s.end(),s.begin(),[](unsigned char c){return tolower(c);});
        auto it=find(cache.begin(),cache.end(),s);
        if(it==cache.end()){
            cache.pop_front(); cache.push_back(s);
            answer+=5;
        }else{
            cache.erase(it); cache.push_back(s);
            answer+=1;
        }
    }
    return answer;
}
