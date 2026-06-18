#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int N;
    if (!(cin >> N)) return 0;

    vector<char> vertices(N);
    unordered_map<char, int> labelToIndex;

    for (int i = 0; i < N; ++i) {
        cin >> vertices[i];
        labelToIndex[vertices[i]] = i;
    }

    int M;
    cin >> M;

    vector<vector<int>> matrix(N, vector<int>(N, 0));

    for (int i = 0; i < M; ++i) {
        char u, v;
        int w;
        cin >> u >> v >> w;

        int u_idx = labelToIndex[u];
        int v_idx = labelToIndex[v];

        matrix[u_idx][v_idx] = w;
    }

    cout << "Adjacency Matrix:\n";

    for (int i = 0; i < N; ++i) {
        cout << vertices[i] << (i == N - 1 ? "" : " ");
    }
    cout << "\n";

    for (int i = 0; i < N; ++i) {
        cout << vertices[i]; 
        for (int j = 0; j < N; ++j) {
            cout << " " << matrix[i][j];
        }
        cout << "\n";
    }

    return 0;
}