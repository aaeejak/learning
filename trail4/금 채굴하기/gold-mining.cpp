#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector <int>> field(N, vector<int>(N, 0));

    for (int i{ 0 }; i < N; i++) {
        for (int l{ 0 }; l < N; l++) {
            cin >> field[i][l];
        }
    }

    int result{ 0 };
    for (int k = 0; k <= N + 1; k++) {
        int cost = k * k + (k + 1) * (k + 1);
        
        for (int i{ 0 }; i < N; i++) {
            for (int l {0}; l < N; l++) {
                int tmp = 0;
                
                for (int r{ 0 }; r < N; r++) {
                    for (int c{ 0 }; c < N; c++) {
                        if (abs(r - i) + abs(c - l) <= k) {
                            tmp += field[r][c];
                        }
                    }
                }
                
                if (tmp * M >= cost) {
                    result = max(result, tmp);
                }
            }
        }
    }

    cout << result;
}