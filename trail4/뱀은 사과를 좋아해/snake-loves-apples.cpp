#include <iostream>
#include <list>
using namespace std;

int N, M, K;
int grid[101][101] = { 0 };
char d[1000];
int p[1000];

struct xy {
    int x;
    int y;
    xy(int x, int y):x{x},y{y}{}
};

int main() {
    cin >> N >> M >> K;

    //사과
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        grid[x][y] = 1;
    }
    //진행 방향
    for (int i = 0; i < K; i++) cin >> d[i] >> p[i];

    int cnt{ 0 };
    list <xy> snake;
    snake.push_front(xy(1, 1));
    for (int i{ 0 };i < K;i++) {
        char dir = d[i];
        int s = p[i];
        bool end = false;

        //1초마다
        for (int l{ 0 };l < s;l++) {
            cnt++;
            int x = snake.front().x;
            int y = snake.front().y;

            if (dir == 'U') {
                if (x - 1 <= 0) {
                    end = true;
                    break;
                }
                if (grid[x - 1][y] == 0) {
                    snake.pop_back();
                }
                else {
                    grid[x - 1][y] = 0;
                }
                for (xy as : snake) {
                    if (x-1 == as.x && y == as.y) {
                        end = true;
                        break;
                    }
                }

                snake.push_front(xy(x - 1, y));
            }
            else if (dir == 'D') {
                if (x + 1 > N) {
                    end = true;
                    break;
                }
                if (grid[x + 1][y] == 0) {
                    snake.pop_back();
                }
                else {
                    grid[x + 1][y] = 0;
                }
                for (xy as : snake) {
                    if (x+1 == as.x && y == as.y) {
                        end = true;
                        break;
                    }
                }

                snake.push_front(xy(x + 1, y));

            }
            else if (dir == 'L') {
                if (y - 1 <= 0) {
                    end = true;
                    break;
                }
                if (grid[x][y-1] == 0) {
                    snake.pop_back();
                }
                else {
                    grid[x][y-1] = 0;
                }
                for (xy as : snake) {
                    if (x == as.x && y-1 == as.y) {
                        end = true;
                        break;
                    }
                }

                snake.push_front(xy(x , y-1));

            }
            else if (dir == 'R') {
                if (y + 1 > N) {
                    end = true;
                    break;
                }
                if (grid[x][y+1] == 0) {
                    snake.pop_back();
                }
                else {
                    grid[x ][y+1] = 0;
                }
                for (xy as : snake) {
                    if (x == as.x && y+1 == as.y) {
                        end = true;
                        break;
                    }
                }
                snake.push_front(xy(x , y+1));

            }
            if (end)break;

        }
        if (end)break;

        
    }

    cout << cnt;

    return 0;
}
