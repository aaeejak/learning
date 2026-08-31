#include <iostream>

using namespace std;

int n, m;
int grid[20][20];

void swap(int i, int j, int l, int k) {
    int tmp = grid[i][j];
    grid[i][j] = grid[l][k];
    grid[l][k] = tmp;
}

bool in_grid(int i, int j, int dx, int dy) {
    return (i + dx >= 0 && i + dx < n) &&
        (j + dy >= 0 && j + dy < n);
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int dx[8] = {-1,-1,0,1,1,1,0,-1};
    int dy[8] = {0,1,1,1,0,-1,-1,-1};

    while(m--){
        for (int a{ 1 };a <= n * n;a++) {
            bool find = false;

            for (int i{ 0 };i < n;i++) {
                for (int j{ 0 };j < n; j++) {
                    if (grid[i][j] != a)continue;

                    int max{ 0 };
                    int max_k{ 0 };
                    for (int k{ 0 };k < 8;k++) {
                        if (!in_grid(i, j, dx[k], dy[k]))continue;

                        if (max < grid[i + dx[k]][j + dy[k]]) {
                            max = grid[i + dx[k]][j + dy[k]];
                            max_k = k;
                        }
                    }

                    swap(i, j, i + dx[max_k], j + dy[max_k]);
                    find = true;
                    break;
                }
                if (find)break;
            }

        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
