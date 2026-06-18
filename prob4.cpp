#include <iostream>
#include <vector>

using namespace std;

int R, C;
int FR, FC;
int total_paths = 0;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void dfs(int r, int c, const vector<vector<int>>& grid, vector<vector<bool>>& visited) {
    if (r == FR && c == FC) {
        total_paths++;
        return;
    }

    visited[r][c] = true;

    for (int i = 0; i < 4; ++i) {
        int next_r = r + dr[i];
        int next_c = c + dc[i];

        if (next_r >= 0 && next_r < R && next_c >= 0 && next_c < C) {
            if (grid[next_r][next_c] == 0 && !visited[next_r][next_c]) {
                dfs(next_r, next_c, grid, visited); 
            }
        }
    }

    visited[r][c] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> R >> C)) return 0;

    vector<vector<int>> grid(R, vector<int>(C));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> grid[i][j];
        }
    }

    int SR, SC;
    cin >> SR >> SC >> FR >> FC;

    vector<vector<bool>> visited(R, vector<bool>(C, false));

    dfs(SR, SC, grid, visited);

    cout << total_paths << "\n";

    return 0;
}