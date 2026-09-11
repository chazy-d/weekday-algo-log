#include <algorithm>
#include <list>
#include <string>
#include <vector>

using namespace std;

int solution(int cacheSize, vector<string> cities)
{
    int answer = 0;
    list<string> cache;

    for (string city : cities)
    {
        for (char &ch : city)
        {
            ch = tolower(ch);
        }

        auto it = find(cache.begin(), cache.end(), city);

        if (it != cache.end())
        {
            answer += 1;
            cache.erase(it);
        }
        else
        {
            answer += 5;

            if (cacheSize == 0)
            {
                continue;
            }

            if (cache.size() == cacheSize)
            {
                cache.pop_back();
            }
        }

        cache.push_front(city);
    }

    return answer;
}

/*
    데이터베이스에서 게시물을 가져오는 부분의 실행시간이 넘 ㅜ오래 걸려서
    DB 캐시를 적용하여 성능 개선을 해야하는데 캐시 크기를 얼마로 해야하는가
    를 몰라서 캐시 크기에 따른 실행시간 측정 프로그램을 작성하시오!

    입력: cacheSize (0이상 30이하), cities (10^5)

    출력: 캐시를 이용한 총 실행시간

    스택안되고, 그냥 배열 놓고 앞뒤 O(N)으로 하거나 list, deque 써야할듯? 근데 성능 똑같을듯? -> 저번에 틀린 문제에서 썼던 list를 다시 써보자.


*/