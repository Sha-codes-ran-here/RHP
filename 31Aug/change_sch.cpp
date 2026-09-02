#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;

    vector<int> cnt(K + 1, 0);

    // Count students in each class
    for (int i = 0; i < N; i++) {
        int c;
        cin >> c;
        cnt[c]++;
    }

    // Find the maximum number of students in any class
    int maxi = *max_element(cnt.begin() + 1, cnt.end());

    int canJoin = 0;

    // Check each class
    for (int i = 1; i <= K; i++) {
        // Takahashi joins this class, so its size becomes cnt[i] + 1
        if (cnt[i] + 1 >= maxi) {
            canJoin++;
        }
    }

    cout << canJoin << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}