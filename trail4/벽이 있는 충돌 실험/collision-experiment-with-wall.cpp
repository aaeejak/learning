#include <iostream>

using namespace std;

int T;
int N, M;
int x[2500];
int y[2500];
char d[2500];
int board[50][50];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> N >> M;
        for (int i = 0; i < M; i++) {
            int r, c;
            cin >> r >> c >> d[i];
            x[i] = r - 1;
            y[i] = c - 1;
        }

        for (int l{ 0 }; l < 2 * N; l++) {
            for (int r = 0; r < N; r++) {
                for (int c = 0; c < N; c++) {
                    board[r][c] = 0;
                }
            }

            for (int i{ 0 }; i < M; i++) {
                if (x[i] == -1 || y[i] == -1) continue;

                if (d[i] == 'U') {
                    if (x[i] > 0) {
                        x[i]--;
                    }
                    else {
                        d[i] = 'D';
                    }
                }
                else if (d[i] == 'L') {
                    if (y[i] > 0) {
                        y[i]--;
                    }
                    else {
                        d[i] = 'R';
                    }
                }
                else if (d[i] == 'D') {
                    if (x[i] < N - 1) {
                        x[i]++;
                    }
                    else {
                        d[i] = 'U';
                    }
                }
                else if (d[i] == 'R') {
                    if (y[i] < N - 1) {
                        y[i]++;
                    }
                    else {
                        d[i] = 'L';
                    }
                }

                board[x[i]][y[i]]++;
            }

            for (int i{ 0 }; i < M; i++) {
                if (x[i] == -1 || y[i] == -1) continue;

                if (board[x[i]][y[i]] > 1) {
                    x[i] = -1;
                    y[i] = -1;
                }
            }
        }

        int cnt{ 0 };
        for (int i{ 0 }; i < M; i++) {
            if (x[i] != -1 || y[i] != -1) cnt++;
        }
        cout << cnt << "\n";
    }

    return 0;
}