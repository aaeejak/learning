#include <iostream>
#include <algorithm>
using namespace std;

int n;
int grid[100][100];

bool in_grid(int cur_x, int cur_y) {
    return (cur_x >= 0 && cur_x < n) &&
        (cur_y >= 0 && cur_y < n);
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> grid[i][j];

    
    int mx{ 0 };
    int xdir[4] = { 1,0,-1,0 };
    int ydir[4] = { 0,1,0,-1 };

    //1 -> / 2-> \
    //각 면에서 출발
    for (int i{ 0 };i < 4 * n;i++) {
        int dir{ -1 };
        int cur_x{ -1 }, cur_y{ -1 };
        if (i / n == 0) { // 아래방향
            dir = 0;
            cur_x = 0;
            cur_y = i % n;
        }
        else if (i / n == 1) { //오른쪽
            dir = 1;
            cur_x = i % n;
            cur_y = 0;
        }
        else if (i / n == 2) { // 위
            dir = 2;
            cur_x = n-1;
            cur_y = i % n;
        }
        else if (i / n == 3) { // 왼쪽
            dir = 3;
            cur_x = i % n;
            cur_y = n-1;
        }
        
        int cnt{ 1 };
        while (in_grid(cur_x, cur_y)) {
            if (grid[cur_x][cur_y] == 1) {
                if (dir % 2 != 0) dir = (dir+1) % 4;
                else dir = (dir+3) % 4;
            }
            else if(grid[cur_x][cur_y] == 2) {
                if (dir % 2 != 0) dir = (dir + 3) % 4;
                else dir = (dir + 1) % 4;
            }
            cur_x += xdir[dir];
            cur_y += ydir[dir];
            

            cnt++;
        }
        mx = max(mx, cnt);
    }

    cout << mx;

    return 0;
}
