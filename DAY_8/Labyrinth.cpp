#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

void backTrack(vector<vector<char>> & grid, int pRow, int pCol);

int main()
{
    int R, C; cin >> R >> C;
    vector<vector<char>> grid (R, vector<char>(C, '#'));

    queue<pair<int, int>> q;
    constexpr int diff[5] = {0, -1, 0, 1, 0};
    const string dir = "LURD";

    for (int row = 0; row < R; row++)
        for (int col = 0; col < C; col++) {
            char c; cin >> c;
            if (c != '#')
               grid[row][col] = c;
            if (c == 'A')
                q.emplace(row,col);
        }

    int pathRow = -1, pathCol = -1;
    bool found = false;
    while (!q.empty()) {
        int qsize = q.size();

        while (qsize--) {
            auto [row, col] = q.front();
            q.pop();
            for (int i  = 0; i < 4; i++) {
                int ar = row + diff[i], ac = col + diff[i + 1];
                if (ar >= 0 && ar < R && ac >= 0 && ac < C) {
                    if (grid[ar][ac] == '.') {
                        q.emplace(ar,ac);
                        grid[ar][ac] = dir[i];
                    }
                    if (grid[ar][ac] == 'B') {
                        pathRow = ar; pathCol = ac;
                        grid[ar][ac] = dir[i];
                        found = true;
                        break;
                    }
                }
            }
        }
    }



    if (!found) {
        cout << "NO" << endl;
        return 0;
    }

    backTrack(grid,pathRow,pathCol);
    
}

void backTrack(vector<vector<char>> & grid, int pRow, int pCol)
{
    string path;
    while (grid[pRow][pCol] != 'A') {
        char ch = grid[pRow][pCol];
        path += ch;
        grid[pRow][pCol] = '.';

        if (ch == 'L') pCol++;
        else if ( ch == 'R') pCol--;
        else if (ch == 'U') pRow++;
        else if (ch == 'D') pRow--;

    }
    reverse(path.begin(),path.end());
    cout << "YES" << endl;
    cout << path.length() << endl;
    cout << path << endl;
}