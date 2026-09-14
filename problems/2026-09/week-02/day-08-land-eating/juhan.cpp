#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> land) {
    vector<int> prev(land[0].begin(), land[0].end());

    for (size_t i = 1; i < land.size(); ++i) {
        vector<int> cur(4);
        for (int j = 0; j < 4; ++j) {
            int best = 0;
            for (int k = 0; k < 4; ++k)
                if (k != j) best = max(best, prev[k]);
            cur[j] = land[i][j] + best;
        }
        prev = cur;
    }
    int ans=0;
    for(int& i : prev) ans=max(ans,i);
    return ans;
}
