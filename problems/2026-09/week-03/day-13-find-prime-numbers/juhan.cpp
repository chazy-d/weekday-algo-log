#include <bits/stdc++.h>
using namespace std;
bool isPrime[10000000];

int solution(string numbers) {
    int answer = 0;
    const int MAX=9999999;
    fill(isPrime+2,isPrime+MAX+1,true);
    for(int i=2;(long long)i*i<=MAX;++i)
        if(isPrime[i])
            for(int j=i*i;j<=MAX;j+=i)isPrime[j]=false;
    sort(numbers.begin(),numbers.end());
    set<int> sset;
    do{
        for(int i=1;i<=(int)numbers.size();++i)
            sset.insert(stoi(numbers.substr(0, i)));
    }while(next_permutation(numbers.begin(),numbers.end()));
    for(int x:sset) if(isPrime[x]) answer++;
    return answer;
}
