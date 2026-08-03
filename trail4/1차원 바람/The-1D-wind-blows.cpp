#include <iostream>
#include <algorithm>
using namespace std;

int n, m, q;
int a[100][100];

int main() {
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < q; i++) {
        int r;
        char d;
        cin >> r >> d;

        int r1{ r - 1 }, r2{ r - 1 };
        char d1{ d == 'L' ? 'R' : 'L' }, d2{ d == 'L' ? 'R' : 'L' };

        // 첫 바람
        if (d == 'R') {
            int tmp{ a[r - 1][0] };
            for (int j{ 0 }; j < m - 1; j++) {
                a[r - 1][j] = a[r - 1][j + 1];
            }
            a[r - 1][m - 1] = tmp;
        }
        else {
            int tmp{ a[r - 1][m - 1] };
            for (int j{ m - 1 }; j > 0; j--) {
                a[r - 1][j] = a[r - 1][j - 1];
            }
            a[r - 1][0] = tmp;
        }

        // 위로 전이
        while (r1 > 0) {
            r1--;
            bool equal = false;
            for (int j{ 0 }; j < m; j++) {
                if (a[r1][j] == a[r1 + 1][j]) {
                    equal = true;
                    break;
                }
            }
            if (!equal) {
                break;
            }
            
            if (d1 == 'R') {
                int tmp{ a[r1][0] };
                for (int j{ 0 }; j < m - 1; j++) {
                    a[r1][j] = a[r1][j + 1];
                }
                a[r1][m - 1] = tmp;
            }
            else {
                int tmp{ a[r1][m - 1] };
                for (int j{ m - 1 }; j > 0; j--) {
                    a[r1][j] = a[r1][j - 1];
                }
                a[r1][0] = tmp;
            }
            d1 = d1 == 'L' ? 'R' : 'L';
        }

        // 아래로 전이
        while (r2 < n - 1) {
            r2++;
            bool equal = false;
            for (int j{ 0 }; j < m; j++) {
                if (a[r2][j] == a[r2 - 1][j]) {
                    equal = true;
                    break;
                }
            }
            if (!equal) {
                break;
            }
            
            if (d2 == 'R') {
                int tmp{ a[r2][0] };
                for (int j{ 0 }; j < m - 1; j++) {
                    a[r2][j] = a[r2][j + 1];
                }
                a[r2][m - 1] = tmp;
            }
            else {
                int tmp{ a[r2][m - 1] };
                for (int j{ m - 1 }; j > 0; j--) {
                    a[r2][j] = a[r2][j - 1];
                }
                a[r2][0] = tmp;
            }
            d2 = d2 == 'L' ? 'R' : 'L';
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