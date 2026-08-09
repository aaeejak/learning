#include <iostream>
#include <algorithm>
using namespace std;

int n, m, q;
int a[100][100];
int b[100][100];

int x[4] = { -1,0,1,0 };
int y[4] = { 0,-1,0,1 };

int main() {
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int k = 0; k < q; k++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        //오른쪽으로 한칸씩 이동 c1 -> c2까지
        int tmp{ a[r1-1][c2-1] };
        for (int i{ c2-1 }; i > c1-1; i--) {
            a[r1-1][i] = a[r1-1][i-1];
        }

        //아래로 r1 -> r2
        int tmp2{ a[r2 - 1][c2 - 1] };
        for (int i{ r2 - 1 }; i > r1; i--) {
            a[i][c2 - 1] = a[i-1][c2 - 1];
        }
        a[r1][c2 - 1] = tmp;

        //왼쪽으로 c2 -> c1 / r2-1
        tmp = a[r2 - 1][c1 - 1];
        for (int i{ c1 - 1 }; i < c2 - 1; i++) {
            a[r2 - 1][i] = a[r2 - 1][i+1];
        }
        a[r2 - 1][c2 - 2] = tmp2;

        //위로 r2->r1 / c1-1
        for (int i{ r1 - 1 }; i < r2 - 1; i++) {
            a[i][c1-1] = a[i+1][c1-1];
        }
        a[r2 - 2][c1 - 1] = tmp;

        //복사
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                b[i][j] = a[i][j];
            }
        }

        //평균내기
        for (int i{ r1 - 1 }; i < r2; i++) {
            for (int j{ c1 - 1 }; j < c2; j++) {
                int avg{ 0 }, sum{ 0 }, cnt{ 1 };
                sum += b[i][j];
                for (int o{ 0 }; o < 4; o++) {
                    if (i + y[o] >= n || i + y[o] < 0
                        || j + x[o] >= m || j + x[o] < 0) continue;
                    sum += b[i + y[o]][j + x[o]];
                    cnt++;
                }
                avg = sum / cnt;
                a[i][j] = avg;
            }
        }

    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    

    return 0;
}