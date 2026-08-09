#include <iostream>

using namespace std;

int n;
int grid[100][100];
int r, c, m1, m2, m3, m4, dir;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    cin >> r >> c >> m1 >> m2 >> m3 >> m4 >> dir;

    int curx{ r - 1 }, cury{ c - 1 };
    if (dir == 0) { //반시계방향
        int tmp{ grid[curx - m1][cury + m1] };
        for (int i{ m1 }; i > 0; i--) {
            grid[curx - i][cury + i] = grid[curx - i + 1][cury + i - 1];
        }
        curx -= m1;
        cury += m1;

        int tmp2{ grid[curx - m2][cury - m2] };
        for (int i{ m2 }; i > 0; i--) {
            grid[curx - i][cury - i] = grid[curx - i + 1][cury - i + 1];
        }
        grid[curx - 1][cury - 1] = tmp;

        curx -= m2;
        cury -= m2;

        tmp = grid[curx + m3][cury - m3];
        for (int i{ m3 }; i > 0; i--) {
            grid[curx + i][cury - i] = grid[curx + i - 1][cury - i + 1];
        }
        grid[curx + 1][cury - 1] = tmp2;

        curx += m3;
        cury -= m3;

        for (int i{ m4 }; i > 0; i--) {
            grid[curx + i][cury + i] = grid[curx + i - 1][cury + i - 1];
        }
        grid[curx + 1][cury + 1] = tmp;
    }
    else {//시계
        int tmp{ grid[curx - m2][cury - m2] };
        for (int i{ m2 }; i > 0; i--) {
            grid[curx - i][cury - i] = grid[curx - i + 1][cury - i + 1];
        }

        curx -= m2;
        cury -= m2;

        int tmp2{ grid[curx - m1][cury + m1] };
        for (int i{ m1 }; i > 0; i--) {
            grid[curx - i][cury + i] = grid[curx - i + 1][cury + i - 1];
        }
        grid[curx - 1][cury + 1] = tmp;

        curx -= m1;
        cury += m1;

        tmp = grid[curx + m4][cury + m4];
        for (int i{ m4 }; i > 0; i--) {
            grid[curx + i][cury + i] = grid[curx + i - 1][cury + i - 1];
        }
        grid[curx + 1][cury + 1] = tmp2;

        curx += m4;
        cury += m4;

        tmp2 = grid[curx + m3][cury - m3];
        for (int i{ m3 }; i > 0; i--) {
            grid[curx + i][cury - i] = grid[curx + i - 1][cury - i + 1];
        }
        grid[curx + 1][cury - 1] = tmp;
    }
    

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;

    }

    return 0;
}
