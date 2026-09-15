#include <vector>

using namespace std;

int func(vector<int> &numbers, int sum, int target)
{
    if (numbers.empty())
    {
        return sum == target;
    }

    int number = numbers.back();
    numbers.pop_back();

    int answer = 0;

    answer += func(numbers, sum + number, target);
    answer += func(numbers, sum - number, target);

    numbers.push_back(number);

    return answer;
}

int solution(vector<int> numbers, int target)
{
    return func(numbers, 0, target);
}

/*
    경우의 수를 찾는 문제이므로 그리디는 아님. 완전탐색하거나 dp로 풀어야할듯?
    앞 인덱스의 배열의 값부터 더하거나 빼는 케이스로 나누고, 쓰면 될듯.? 근데 0 어케 다시 넣어주지.

*/