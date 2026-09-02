#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W, K;
    cin >> H >> W >> K;

    vector<string> S(H);

    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }

    // rowBomb[i] = whether row i contains a bomb
    // colBomb[j] = whether column j contains a bomb
    vector<bool> rowBomb(H, false);
    vector<bool> colBomb(W, false);

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') {
                rowBomb[i] = true;
                colBomb[j] = true;
            }
        }
    }

    // dist[i][j] = shortest distance from a safe cell
    vector<vector<int>> dist(H, vector<int>(W, -1));

    queue<pair<int, int>> q;

    // Find all safe empty cells
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '.' &&
                !rowBomb[i] &&
                !colBomb[j]) {

                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    // Multi-source BFS
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            // Outside grid
            if (nr < 0 || nr >= H || nc < 0 || nc >= W)
                continue;

            // Cannot move through bomb
            if (S[nr][nc] == '#')
                continue;

            // Already visited
            if (dist[nr][nc] != -1)
                continue;

            dist[nr][nc] = dist[r][c] + 1;
            q.push({nr, nc});
        }
    }

    int ans = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {

            // IMPORTANT:
            // dist == -1 means unreachable
            if (S[i][j] == '.' &&
                dist[i][j] != -1 &&
                dist[i][j] <= K) {

                ans++;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}