#include <iostream>
#include <vector>
using namespace std;

int solution(int n) {
    const int MOD = 1000000007;
    int answer = 0;

    vector<int> v(3, 0);

    for (int i = 0; i < n; ++i) {
        if (i <= 2) {
            answer = i + 1;
        } else {
            answer = static_cast<int>((2LL * v[1] + v[0]) % MOD);
        }

        v[0] = v[1];
        v[1] = v[2];
        v[2] = answer;
    }

    return answer;
}

int main() {
    cout << solution(4) << '\n';
}