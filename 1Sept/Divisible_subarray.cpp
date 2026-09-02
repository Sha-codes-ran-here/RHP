#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    long long K;
    cin >> N >> K;
    vector<int> dp(N + 1, 0);
    unordered_map<long long, int> best;
    long long sum = 0;
    best[0] = 0;
    for (int i = 1; i <= N; i++) {
        long long x;
        cin >> x;
        sum = (sum + x) % K;
        dp[i] = dp[i - 1];
        if (best.count(sum)) {
            dp[i] = max(dp[i], best[sum] + 1);
        }
        if (!best.count(sum)) {
            best[sum] = dp[i];
        } else {
            best[sum] = max(best[sum], dp[i]);
        }
    }
    cout << dp[N] << '\n';
    return 0;
}