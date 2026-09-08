# weekday-algo-log

평일마다 같은 문제를 풀고, 각자의 코드와 짧은 기록을 남기는 저장소입니다.

## 학습 방식

- 매일 아침 Claude에게 현재 진도와 학습 흐름에 맞는 문제를 추천받아 풀이한다.
- 첫 풀이에서는 [프로그래머스 가림판](https://chromewebstore.google.com/detail/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EA%B0%80%EB%A6%BC%ED%8C%90/bbmpfkionnjggoeioleplhfbagmopgcb)을 사용해 문제 유형과 난이도를 가린다.
- 문제를 푼 뒤에는 코드와 함께 막힌 지점, 사용한 핵심 개념, 다음에 보완할 점을 기록한다.

## 폴더 구조

```text
problems/
└── 2026-09/
    └── week-02/
        └── day-04-2xn-tiling/
            ├── README.md
            ├── taehun.cpp
            └── dongwoo.cpp
templates/
└── problem-README.md
```

- 월과 주차는 폴더로 구분한다.
- 주차 폴더에는 `README.md`를 만들지 않는다.
- 문제 하나당 폴더 하나를 만들고, 각자 자신의 C++ 파일만 수정한다.

## 매일 기록하기

1. 새 주가 시작되면 그 주에 풀 5개 문제 폴더를 미리 만들고 `templates/problem-README.md`를 각 폴더의 `README.md`로 복사한다.
2. `taehun.cpp`, `dongwoo.cpp`에 각자 풀이를 작성한다.
3. 문제 README에 결과와 짧은 생각, 다음에 확인할 점을 남긴다.

주말에는 새 문제를 추가하지 않는다. 그 주에 미처 풀지 못했거나 해결하지 못한 문제를 다시 시도하고 보완한다. 다음 주차는 평일 5문제를 기준으로 만든다.

## 함께 지킬 규칙

- 문제 본문 전체 대신 문제 링크만 남긴다.
- 다른 사람의 소스 파일은 수정하지 않는다.
- 힌트나 다른 풀이를 참고했다면 회고에 표시한다.
- 성공하지 못한 날에도 막힌 지점을 한 줄 남긴다.

## 커밋 메시지

```text
solve: 태훈 4일차 2 x n 타일링
solve: 동우 4일차 2 x n 타일링
docs: 2주차 진행 현황 갱신
```
