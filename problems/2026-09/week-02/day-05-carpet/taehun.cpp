#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int width = brown + yellow;
    int center = sqrt(width);

    for (int i = 1; i < center+1;i ++)
    {
        if(width%i==0 && brown == 2*i + 2*(width/i) -4)
        {
            answer.push_back(width / i);
            answer.push_back(i);
        }
    }
    
    return answer;
}

int main( )
{
    vector<int> cor = solution(10, 2);
    cout << cor[0] << " " << cor[1] << endl;
}

/*
격자 모양 카펫. -> 색은 노란색 or 갈색

input = brown, yellow 수

output = 가능한 것. -> 가로 >=세로 

1. rc = y + b 전부 구하기
2. b 만족 필터 
3. 리턴
*/