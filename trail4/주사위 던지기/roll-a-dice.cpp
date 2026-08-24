#include <iostream>

using namespace std;

int n, m;
int r, c;
char directions[10000];

int a[101][101] = {0};

bool In_Range(int x, int y, int dirx,int diry) {
    return !(x + dirx >= 0 && x + dirx < n
        && y + diry >= 0 && y + diry < n);
}

int main() {
    cin >> n >> m >> r >> c;

    for (int i = 0; i < m; i++) {
        cin >> directions[i];
    }

    // 주사위의 방향을 저장, 맨위 숫자 저장
    // 주사위 평면도를 저장?
    //   5          5
    // 4 1 3 6    6 4 1 3 
    //   2          2
    int dice[3][4] = 
     { {-1,5,-1,-1},
        {4,1,3,6},
        {-1,2,-1,-1} };

    int curx{ r - 1 }, cury{ c - 1 };
    //L->R->U->D
    int direction_x[4] = { 0,0,-1,1 };
    int direction_y[4] = { -1,1,0,0 };
    
    a[curx][cury] = 7 - dice[1][1];
    for (int i{ 0 };i < m;i++) {
        char dir = directions[i];
        int tmp;
        if (dir == 'L') {
            if (In_Range(curx, cury, direction_x[0], direction_y[0]))continue;

            curx += direction_x[0];
            cury += direction_y[0];

            tmp = dice[1][0];
            for (int j{ 0 };j < 3;j++) {
                dice[1][j] = dice[1][j + 1];
            }
            dice[1][3] = tmp;

            a[curx][cury] = 7 - dice[1][1];
        }
        else if (dir == 'R') {
            if (In_Range(curx, cury, direction_x[1], direction_y[1]))continue;

            curx += direction_x[1];
            cury += direction_y[1];

            tmp = dice[1][3];
            for (int j{ 2 };j >= 0;j--) {
                dice[1][j + 1] = dice[1][j];
            }
            dice[1][0] = tmp;

            a[curx][cury] = 7 - dice[1][1];
        }
        else if (dir == 'U') {
            if (In_Range(curx, cury, direction_x[2], direction_y[2]))continue;

            curx += direction_x[2];
            cury += direction_y[2];

            tmp = dice[1][3];
            dice[1][3] = dice[0][1];
            for (int j{ 0 };j < 2;j++) {
                dice[j][1] = dice[j + 1][1];
            }
            dice[2][1] = tmp;
            a[curx][cury] = 7 - dice[1][1];
        }
        else if (dir == 'D') {
            if (In_Range(curx, cury, direction_x[3], direction_y[3]))continue;

            curx += direction_x[3];
            cury += direction_y[3];

            tmp = dice[1][3];
            dice[1][3] = dice[2][1];
            for (int j{ 1 };j >= 0;j--) {
                dice[j + 1][1] = dice[j][1];
            }
            dice[0][1] = tmp;
            a[curx][cury] = 7 - dice[1][1];
        }
       
    }

    int sum{0};
    for (int i{ 0 };i < n;i++) {
        for (int j{ 0 };j < n;j++) {
            sum += a[i][j];
        }
    }
    cout << sum;

    return 0;
}
