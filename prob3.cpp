#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int r, c;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int R, C;
    if (!(cin >> R >> C)) return 0;

    vector<vector<int>> grid(R, vector<int>(C));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> grid[i][j];
        }
    }

    int SR, SC, FR, FC;
    cin >> SR >> SC >> FR >> FC;

    vector<vector<int>> dist(R, vector<int>(C, -1));

    queue<Point> q;

    q.push({SR, SC});
    dist[SR][SC] = 0; 

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty()) {
        Point curr = q.front();
        q.pop();

        if (curr.r == FR && curr.c == FC) {
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int next_r = curr.r + dr[i];
            int next_c = curr.c + dc[i];

            if (next_r >= 0 && next_r < R && next_c >= 0 && next_c < C) {
                if (grid[next_r][next_c] == 0 && dist[next_r][next_c] == -1) {
                    dist[next_r][next_c] = dist[curr.r][curr.c] + 1;
                    q.push({next_r, next_c});
                }
            }
        }
    }

    cout << dist[FR][FC] << "\n";

    return 0;
}