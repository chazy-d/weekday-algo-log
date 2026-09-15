# Day 10 — 주차 요금 계산

- 날짜: 2026-09-15 (화)
- 문제: [프로그래머스 — 주차 요금 계산](https://school.programmers.co.kr/learn/courses/30/lessons/92341)

## 태훈

- 결과:
- 소요 시간:
- 생각 또는 막힌 지점:
- 다음에 확인할 점:
- 참고:

## 동우

- 결과:
- 소요 시간:
- 생각 또는 막힌 지점:
- 다음에 확인할 점:
- 참고:

## 주한

- 결과: 정답 (AC)
- 소요 시간: 60분
- 생각 또는 막힌 지점: 함수 사용이 꼬여서 신텍스 에러가 났었음 + 출력조건을 확인 못했었음
- 다음에 확인할 점: 없음
- 참고: 클로드가 더 좋은 풀이를 알려줌 (아래 참고, 차량 번호 범위가 0000~9999이므로 해시를 굳이 쓸 필요 없음)

### 더 좋은 풀이 (배열 사용)

```cpp
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    const int END = 23 * 60 + 59;
    vector<int> total(10000, 0);      // 차량별 누적 시간 (분)
    vector<int> state(10000, -1);     // -1: 기록 없음, 0: 출차 상태, 1: 입차 중

    for (const string& r : records) {
        int t   = stoi(r.substr(0, 2)) * 60 + stoi(r.substr(3, 2));
        int car = stoi(r.substr(6, 4));

        if (r[11] == 'I') {
            total[car] -= t;
            state[car] = 1;
        } else {
            total[car] += t;
            state[car] = 0;
        }
    }

    vector<int> answer;
    for (int car = 0; car < 10000; ++car) {
        if (state[car] == -1) continue;

        int m = total[car] + (state[car] == 1 ? END : 0);
        int fee = fees[1];
        if (m > fees[0])
            fee += (m - fees[0] + fees[2] - 1) / fees[2] * fees[3];
        answer.push_back(fee);
    }
    return answer;
}
```
