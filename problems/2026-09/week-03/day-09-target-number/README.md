# Day 09 — 타겟 넘버

- 날짜: 2026-09-14 (월)
- 문제: [프로그래머스 — 타겟 넘버](https://school.programmers.co.kr/learn/courses/30/lessons/43165)

## 태훈

- 결과: WA
- 소요 시간: 20분
- 생각 또는 막힌 지점: 보고서 떠오른 아이디어로는 부분집합을 구하는 완전탐색의 아이디어가 떠오르긴했음. 포함하거나 안하거나 처럼 여기에서는 더하거나 빼거나 해서 다음 인덱스에게 넘기는? 여기서 나는 vector 자료구조를 사용하여 pop_back()을 사용하였는데. 다시보니 그냥 뺴지 말고 index로 접근하고 인자에 인덱스를 넣긴해도 될듯? 틀린 지점은 내가 만든 재귀함수에서 answer를 관리해야하는데 인자로 넣고 더해주는 과정이 잘 떠오르지 않았음. answer에 dfs를 더해야하는데 그냥 재귀를 돌린게 문제였음.
- 다음에 확인할 점: 이 문제는 제한사항을 통해서 완전탐색 문제라는 것을 쉽게 알 수 있었으나 함수를 잘 세우지 못하였는데.. 머리를 잘 굴려보자.. 특히 count해야할때!
- 참고:

## 동우

- 결과: AC
- 소요 시간: 10분
- 생각 또는 막힌 지점: bfs로 전부 탐색
- 다음에 확인할 점: x
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
