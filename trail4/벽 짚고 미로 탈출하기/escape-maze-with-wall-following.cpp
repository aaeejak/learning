#include <iostream>
using namespace std;

int N;
int x, y;
char grid[101][101];
bool visited[101][101][4];

bool inRange(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < N;
}

int main() {
    cin >> N;
    cin >> x >> y;

    x--;
    y--;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    
    int dx[4] = { 0, -1, 0, 1 };
    int dy[4] = { 1, 0, -1, 0 };

    int dir = 0;  
    int cnt = 0;

    while (true) {

        if (visited[x][y][dir]) {
            cout << -1;
            return 0;
        }

        visited[x][y][dir] = true;

        // 바라보는 방향의 앞쪽
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        // 앞이 막혀 있다면 반시계 방향으로 90도 회전
        if (inRange(nx, ny) && grid[nx][ny] == '#') {
            dir = (dir + 1) % 4;
            continue;
        }

        // 앞이 격자 밖이라면 바로 탈출
        if (!inRange(nx, ny)) {
            cnt++;
            break;
        }

        
        // 앞으로 이동한 위치에서 오른쪽 방향을 확인
        int right = (dir + 3) % 4;

        int rx = nx + dx[right];
        int ry = ny + dy[right];

        // 오른쪽에 벽이 존재
        if (!inRange(rx, ry) || grid[rx][ry] == '#') {
            x = nx;
            y = ny;
            cnt++;
        }
        else { // 벽이 없음
            x = nx;
            y = ny;
            cnt++;

            // 시계 방향으로 90도 회전
            dir = (dir + 3) % 4;

            // 한 칸 더 이동
            x += dx[dir];
            y += dy[dir];
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}