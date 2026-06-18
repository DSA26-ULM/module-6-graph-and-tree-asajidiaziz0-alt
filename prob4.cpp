#include <iostream>
#include <vector>

using namespace std;

int R, C;
int FR, FC;
int total_paths = 0;
vector<vector<int>> grid;
vector<vector<bool>> visited;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void dfs(int r, int c) {
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
                dfs(next_r, next_c);
            }
        }
    }

    visited[r][c] = false;
}

int main() {
    cin >> R >> C;

    grid.assign(R, vector<int>(C));
    visited.assign(R, vector<bool>(C, false));

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> grid[i][j];
        }
    }

    int SR, SC;
    cin >> SR >> SC >> FR >> FC;

    dfs(SR, SC);

    cout << total_paths << "\n";

    return 0;
}