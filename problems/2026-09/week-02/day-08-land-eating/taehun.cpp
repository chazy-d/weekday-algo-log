#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(vector<vector<int>> land)
{
    int answer = 0;
    for (int i = 1; i < land.size(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            land[i][j] = land[i][j] + max({land[i - 1][(j + 1) % 4], land[i - 1][(j + 2) % 4], land[i - 1][(j + 3) % 4]});
        }
    }
    return *max_element(land[land.size() - 1].begin(), land[land.size() - 1].end());
}

/*
    N:10^5
    열 무조건 4개

    최선 이랑 차선을 두개 구하면서 나아가고 최선과 같은 방향의 최대 값이 존재한다면 차선에 2번째를 더해보고,
    아니라면 최대 리턴

    아니면 각 열마다 지금까지 왔을때의 최대 수를 유지해가며 바꿔주고 마지막 열에 도착하면 각 열의 값을 비교하여 최대값을 리턴
*/