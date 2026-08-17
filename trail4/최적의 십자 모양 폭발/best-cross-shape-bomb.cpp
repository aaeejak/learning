#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int n;
int grid[50][50];
int grid_tmp[50][50];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int result = 0;

    // 모든 위치를 폭발시켜 보기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            // grid_tmp 초기화
            for (int q = 0; q < n; q++) {
                for (int w = 0; w < n; w++) {
                    grid_tmp[q][w] = grid[q][w];
                }
            }

            // 폭탄 터뜨리기
            int bomb_size = grid[i][j];

            for (int q = 0; q < bomb_size; q++) {
                if (i + q < n)
                    grid_tmp[i + q][j] = 0;

                if (i - q >= 0)
                    grid_tmp[i - q][j] = 0;

                if (j + q < n)
                    grid_tmp[i][j + q] = 0;

                if (j - q >= 0)
                    grid_tmp[i][j - q] = 0;
            }

            // 중력 작용
            for (int q = 0; q < n; q++) {
                list<int> tmp;

                for (int w = 0; w < n; w++) {
                    if (grid_tmp[w][q] == 0)
                        tmp.push_front(0);
                    else
                        tmp.push_back(grid_tmp[w][q]);
                }

                for (int w = 0; w < n; w++) {
                    grid_tmp[w][q] = tmp.front();
                    tmp.pop_front();
                }
            }

            // 쌍의 개수 세기
            int tmp = 0;

            // 가로
            for (int q = 0; q < n; q++) {
                for (int w = 0; w < n - 1; w++) {
                    if (grid_tmp[q][w] != 0 &&
                        grid_tmp[q][w] == grid_tmp[q][w + 1]) {
                        tmp++;
                    }
                }
            }

            // 세로
            for (int q = 0; q < n - 1; q++) {
                for (int w = 0; w < n; w++) {
                    if (grid_tmp[q][w] != 0 &&
                        grid_tmp[q][w] == grid_tmp[q + 1][w]) {
                        tmp++;
                    }
                }
            }

            result = max(result, tmp);
        }
    }

    cout << result;

    return 0;
}