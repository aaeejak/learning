#include <iostream>

using namespace std;

int n, m, t;
int a[20][20];
int b[20][20];
int c[20][20];

bool in_a(int j, int k, int dx, int dy) {
    return (j + dx >= 0 && j + dx < n) &&
        (k + dy >= 0 && k + dy < n);
}

int main() {
    cin >> n >> m >> t;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        b[x-1][y-1] = 1;
    }

    int dx[4] = { -1,1,0,0 };
    int dy[4] = { 0,0,-1,1 };

    for (int i{ 0 };i < t;i++) {
        // 현재 공이 있는곳을 탐색
        for (int j{ 0 };j < n;j++) {
            for (int l{ 0 };l < n;l++) {
                if (b[j][l] == 0)continue;
                //공이 존재, 이동할 곳 찾기
                int max{ 0 };
                int max_k{ 0 };
                for (int k{ 0 };k < 4;k++) {
                    if (!in_a(j, l, dx[k], dy[k])) continue;

                    if (max < a[j+dx[k]][l+dy[k]]) {
                        max = a[j + dx[k]][l + dy[k]];
                        max_k = k;
                    }
                }
                
                c[j + dx[max_k]][l + dy[max_k]]++;
            }
        }

        //공 이동 후 초기화
        for (int j{ 0 };j < n;j++) {
            for (int l{ 0 };l < n;l++) {
                b[j][l] = 0;
            }
        }
        for (int j{ 0 };j < n;j++) {
            for (int l{ 0 };l < n;l++) {
                if (c[j][l] == 1)b[j][l] = 1;
                c[j][l] = 0;
            }
        }
    }

    int cnt{ 0 };
    for (int j{ 0 };j < n;j++) {
        for (int l{ 0 };l < n;l++) {
            if (b[j][l] == 1)cnt++;
        }
    }
    cout << cnt;

    return 0;
}
