#include <iostream>
#include<vector>
using namespace std;

int N, m, t, k;
int r[2500], c[2500];
char d[2500];
int v[2500];


void find_min(vector<int>& board) {
    int min{ 1000 };
    int i, b;
    for (int a{ 0 }; a < board.size(); a++) {
        if (v[board[a]] < min) {
            min = v[board[a]];
            i = board[a];
            b = a;
        }
    }
    board.erase(board.begin() + b);
    r[i] = -1;
    c[i] = -1;

}

int main() {
    cin >> N >> m >> t >> k;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b >> d[i] >> v[i];
        r[i] = a - 1;
        c[i] = b - 1;
    }

    while (t--) {
        vector <int> board[50][50];
        for (int i{ 0 }; i < m; i++) { //이동시키기

            if (r[i] == -1 || c[i] == -1) continue;

            for (int l{ 0 };l<v[i];l++){
                if (d[i] == 'U') {
                    if (r[i] > 0) {
                        r[i]--;
                    }
                    else {
                        r[i]++;
                        d[i] = 'D';
                    }
                }
                else if (d[i] == 'L') {
                    if (c[i] > 0) {
                        c[i]--;
                    }
                    else {
                        c[i]++;
                        d[i] = 'R';
                    }
                }
                else if (d[i] == 'D') {
                    if (r[i] < N - 1) {
                        r[i]++;
                    }
                    else {
                        r[i]--;
                        d[i] = 'U';
                    }
                }
                else if (d[i] == 'R') {
                    if (c[i] < N - 1) {
                        c[i]++;
                    }
                    else {
                        c[i]--;
                        d[i] = 'L';
                    }
                }
            }

            board[r[i]][c[i]].push_back(i);
        }
        //board 에는 i 값이 들어가 있음.
        for (int i{ 0 }; i < N; i++) {
            for (int l{ 0 }; l < N; l++) {
                if (board[i][l].empty())continue;
                if (board[i][l].size() <= k)continue;
                else {
                    while (board[i][l].size() > k) {
                        find_min(board[i][l]);

                    }
                }

            }
        }

    }

    int cnt{ 0 };
    for (int i{ 0 }; i < m; i++) {
        if (r[i] != -1 || c[i] != -1) cnt++;
    }
    cout << cnt << "\n";

    return 0;
}
