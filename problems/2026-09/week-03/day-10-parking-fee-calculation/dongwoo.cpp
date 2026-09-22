#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int fee[10001];
bool valid[10001];
int start_time[10001];

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<int> car_num;
    
    for(int i=0;i<records.size();i++){
        string rec = records[i];
        int tim = ((rec[0]-'0')*10 + (rec[1]-'0'))*60 + (rec[3]-'0')*10 + (rec[4]-'0');
        int car = (rec[6]-'0')*1000 + (rec[7]-'0')*100 + (rec[8]-'0')*10 + (rec[9]-'0');
        if(!valid[car]){
            valid[car] = true;
            car_num.push_back(car);
        }
        if(rec[11]=='I'){
            start_time[car] = tim;
        }
        else{
            fee[car] += tim - start_time[car];
            start_time[car] = -1;
        }
    }
    sort(car_num.begin(),car_num.end());
    
    for(int i=0;i<car_num.size();i++){
        int car = car_num[i];
        if(start_time[car]!=-1){
            fee[car]+=1439-start_time[car];
        }
        int k=0;
        if(fee[car]<=fees[0]){
            k = fees[1];
        }
        else{
            k = fees[1] + ((fee[car]-fees[0]+fees[2]-1)/fees[2])*fees[3];
        }
        answer.push_back(k);
    }
    return answer;
}