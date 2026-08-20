#include <iostream>

using namespace std;

int n, m, k;
int grid[100][100];

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int cury{ k-1 };
    int curx{ 0 };
    bool end = false;
    for (int i{ 0 };i < n;i++) {
        for (int j{ 0 };j < m;j++) {
            if (grid[i][cury + j] == 1) {
                end = true;
                break;
            }
        }
        if (end)break;
        curx = i;
    }
    for (int j{ 0 };j < m;j++) {
        grid[curx][cury + j] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
