#include <bits/stdc++.h>
using namespace std;

using combo = vector<int>;

vector<combo> ans;

void dfs(int slot, int bal, combo &arr) {

    // A1 is determined by the remaining balance
    if (slot == 1) {
        arr[0] = bal;
        ans.push_back(arr);
        return;
    }

    // Try A_slot = 0, 1, 2, ...
    arr[slot - 1] = 0;

    while (bal >= 0) {

        dfs(slot - 1, bal, arr);

        // Increase A_slot by 1
        arr[slot - 1]++;

        // Coefficient of A_slot is slot
        bal -= slot;
    }
}

void solve() {

    int N, K;
    cin >> N >> K;

    combo arr(N, 0);

    dfs(N, K, arr);

    // Backward DFS does NOT give lexicographical order
    sort(ans.begin(), ans.end());

    // Print in lexicographical order
    for (auto &v : ans) {
        for (int i = 0; i < N; i++) {
            cout << v[i] << " ";
        }
        cout << '\n';
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}