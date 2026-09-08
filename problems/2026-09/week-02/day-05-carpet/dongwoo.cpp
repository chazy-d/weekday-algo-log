#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int brown, int yellow)
{
    vector<int> answer;

    int sum = brown + yellow;

    for (int i = 1; i <= sqrt(sum); i++)
    {
        if (sum % i != 0)
        {
            continue;
        }
        int x = i;
        int y = sum / i;
        if (2 * (x + y) - 4 == brown)
        {
            answer.push_back(y);
            answer.push_back(x);
            break;
        }
    }

    return answer;
}