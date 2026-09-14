# Day 09 — 타겟 넘버

- 날짜: 2026-09-14 (월)
- 문제: [프로그래머스 — 타겟 넘버](https://school.programmers.co.kr/learn/courses/30/lessons/43165)

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
- 소요 시간: 10분 이내
- 생각 또는 막힌 지점: 특별히 막힌 건 없음
- 다음에 확인할 점: 없음
- 참고: 클로드가 DP로 더 좋은 풀이를 알려줌 (아래 참고)

### 더 좋은 풀이 (DP)

```cpp
int solution(vector<int> numbers, int target) {
    const int OFFSET = 1000;
    const int SIZE = 2001;

    vector<int> dp(SIZE, 0);
    dp[OFFSET] = 1;                 // 합 0에서 시작

    for (int x : numbers) {
        vector<int> nxt(SIZE, 0);   // 매번 새 배열
        for (int s = 0; s < SIZE; s++) {
            if (!dp[s]) continue;   // 도달 불가능한 합은 스킵
            if (s + x < SIZE) nxt[s + x] += dp[s];
            if (s - x >= 0)   nxt[s - x] += dp[s];
        }
        dp = move(nxt);
    }

    int idx = target + OFFSET;
    return (idx >= 0 && idx < SIZE) ? dp[idx] : 0;
}
```
