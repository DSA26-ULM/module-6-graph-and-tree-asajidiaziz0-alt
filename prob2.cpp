#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    if (!(cin >> N)) return 0;

    vector<char> vertices(N);
    for (int i = 0; i < N; ++i) {
        cin >> vertices[i];
    }

    vector<vector<int>> matrix(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << "Adjacency List:\n";
    for (int i = 0; i < N; ++i) {
        cout << vertices[i] << " ->";
        
        bool has_edge = false;
        
        for (int j = 0; j < N; ++j) {
            if (matrix[i][j] > 0) { 
                if (has_edge) {
                    cout << ","; 
                }
                cout << " (" << vertices[j] << "," << matrix[i][j] << ")";
                has_edge = true; 
            }
        }
        
        if (!has_edge) {
            cout << " -";
        }
        
        cout << "\n"; 
    }

    return 0;
}