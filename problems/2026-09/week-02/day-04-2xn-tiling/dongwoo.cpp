#include <string>
#include <iostream>
#include <vector>
#define ll long long int
#define div 1000000007
using namespace std;

ll dp[600001];

ll fibo(int n){
    if(n<=3){
        return n;
    }
    else{
        ll a,b;
        if(dp[n-1]==0){
            dp[n-1] = fibo(n-1)%div;
        }
        if(dp[n-2]==0){
            dp[n-2] = fibo(n-2)%div;
        }
        
        return (dp[n-1] + dp[n-2])%div;
    }
}

int solution(int n) {
    int answer = 0;
    answer = fibo(n);
    return answer;
}