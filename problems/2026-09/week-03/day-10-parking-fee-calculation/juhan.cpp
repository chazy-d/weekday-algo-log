#include <string>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

int time(int t){
    return t%100+(t/100)*60;
}
int ceill(int i, int t){
    if(i%t!=0){
        return i/t+1;
    }
    return i/t;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    // fees = {기본 시간(분), 기본 요금(원), 단위 시간(분), 단위 요금(원)}
    // records[i] = "HH:MM 0000 IN/OUT" (시각을 기준으로 오름차순)
    vector<int> answer;
    map<string,int> um;
    unordered_map<string,int> tmp;
    for(string &s:records){
        string ss=s.substr(0,2)+s.substr(3,2); int t=stoi(ss);
        string num=s.substr(6,4);
        if(s.substr(11)=="IN"){
            tmp.insert({num,time(t)});
        }else{
            auto i=tmp.find(num);
            int tt=time(t) - i->second;
            tmp.erase(i->first);
            if(um.end()!=um.find(num)) um.find(num)->second+=tt;
            else um.insert({num,tt});
        }
    }
    for(auto& i:tmp){
        if(um.end()!=um.find(i.first)) um.find(i.first)->second+=(23*60+59)-(i.second);
        else um.insert({i.first,(23*60+59)-(i.second)});
    }
    for(auto& i:um){
        if(i.second <= fees[0])  answer.push_back(fees[1]);
        else answer.push_back(fees[1]+ceill(i.second - fees[0],fees[2])*fees[3]);
    }
    return answer;
}
