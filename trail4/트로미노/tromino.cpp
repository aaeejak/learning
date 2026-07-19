#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N,M;
    cin >> N>>M;
    vector <vector <int>> coin(N,vector<int> (M,0));
    for (int i{ 0 }; i < N; i++) {
        for (int l{ 0 }; l < M; l++) {
            cin >> coin[i][l];
        }
    }

    int result{ 0 };
    

    for (int i{ 0 }; i < N; i++) {
        for (int l{ 0 }; l < M; l++) {
            if (i < N - 2) {
                int tmp{ 0 };
                for (int k{ 0 }; k < 3; k++) {
                    tmp += coin[i+k][l];
                }
                result = max(result, tmp);
            }
            if (l < M - 2) {
                int tmp{ 0 };
                for (int k{ 0 }; k < 3; k++) {
                    tmp += coin[i][l+k];
                }
                result = max(result, tmp);
            }
            if (i < N - 1 && l < M - 1) {
                int tmp{ 0 };

                tmp += coin[i][l] + coin[i + 1][l] + coin[i][l + 1];
                result = max(result, tmp);
                tmp = 0;
                tmp += coin[i][l] + coin[i][l+1] + coin[i+1][l + 1];
                result = max(result, tmp);
                tmp = 0;
                tmp += coin[i][l] + coin[i + 1][l] + coin[i+1][l + 1];
                result = max(result, tmp);
                tmp = 0;
                tmp += coin[i+1][l+1] + coin[i + 1][l] + coin[i][l + 1];
                result = max(result, tmp);
            }
        }
    }

    cout << result;
}