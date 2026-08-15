#include <iostream>
#include <list>
using namespace std;

int n, m;
int grid[200][200];
int bomb_cols[15];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    int col;
    while (m--) {
        cin >> col;
        int bomb_col = col - 1;
        int cur_i = 0;
        int tmp = grid[cur_i][bomb_col];
        while (tmp == 0) {
            if (cur_i >= n)break;
            cur_i++;
            tmp = grid[cur_i][bomb_col];
        }

        for (int i{ 0 }; i < tmp; i++) { //터짐

            if (cur_i + i < n)grid[cur_i + i][bomb_col] = 0;

            if (cur_i - i >=0)grid[cur_i - i][bomb_col] = 0;

            if (bomb_col + i < n)grid[cur_i][bomb_col+i] = 0;

            if (bomb_col - i >= 0)grid[cur_i ][bomb_col - i] = 0;

        }

        //중력작용;
        for (int j{ 0 };j < n; j++) {
            list <int> tmps;

            for (int i{ 0 }; i < n; i++) {
                if (grid[i][j] == 0)continue;
                tmps.push_back(grid[i][j]);
            }

            while (tmps.size() < n) {
                tmps.push_front(0);
            }

            for (int i{ 0 }; i < n; i++) {
                grid[i][j] = tmps.front();
                tmps.pop_front();
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