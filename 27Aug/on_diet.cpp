#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    long long K;

    cin >> N >> M >> K;

    vector<long long> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    long long sum = 0;

    for (int i = 0; i < N; i++) {

        // Remove the snack from M days ago
        if (i >= M) {
            sum -= A[i - M];
        }

        // Check if today's snack can be eaten
        if (sum + A[i] <= K) {
            sum += A[i];
            cout << "Yes\n";
        }
        else {
            // Don't eat today's snack
            A[i] = 0;
            cout << "No\n";
        }
    }

    return 0;
}