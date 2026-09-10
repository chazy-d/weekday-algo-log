#include <algorithm>
#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> maps)
{
    int rows = maps.size();
    int cols = maps[0].size();

    vector<vector<int>> visited(rows, vector<int>(cols, 0));
    vector<int> answer;

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            if (maps[r][c] == 'X' || visited[r][c] == 1)
            {
                continue;
            }

            int sum = 0;
            queue<pair<int, int>> q;

            q.push({r, c});
            visited[r][c] = 1;

            while (!q.empty())
            {
                pair<int, int> current = q.front();
                q.pop();

                int currentR = current.first;
                int currentC = current.second;

                sum += maps[currentR][currentC] - '0';

                for (int d = 0; d < 4; d++)
                {
                    int nextR = currentR + dr[d];
                    int nextC = currentC + dc[d];

                    if (nextR < 0 || nextR >= rows ||
                        nextC < 0 || nextC >= cols)
                    {
                        continue;
                    }

                    if (maps[nextR][nextC] == 'X' ||
                        visited[nextR][nextC] == 1)
                    {
                        continue;
                    }

                    visited[nextR][nextC] = 1;
                    q.push({nextR, nextC});
                }
            }
            answer.push_back(sum);
        }
    }

    if (answer.empty())
    {
        return {-1};
    }

    sort(answer.begin(), answer.end());

    return answer;
}

/*
start 11:01

입력: 배열 크기 * maps.size() 배열이 주어짐. 배열안의 값은 1~9의 자연수.

구하는것은 나 잔신의 상하좌우에 값이 지금 존재하는지를 파악한후에 붙어있는 값이 없다면,
해당 값만이 값을 가짐.

우하단으로 움직이면서 계산을 하는데. 위, 왼쪽이 존재한다면 해당 set에 추가.

근데 해당 set이 어떤건지 어떻게앎?

이런 느낌으로 풀면 될듯

*/