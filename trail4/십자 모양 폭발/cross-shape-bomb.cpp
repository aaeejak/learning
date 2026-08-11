#include <iostream>
#include <list>
using namespace std;

int n;
int grid[200][200];
int r, c;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> r >> c;

    int curx{ r - 1 }, cury{ c-1 };
    int range{ grid[curx][cury] };

    for (int i{ 0 }; i < range;i++) {
        if (curx + i < n)grid[curx + i][cury] = 0;
        if (cury + i < n)grid[curx][cury + i] = 0;
        if (curx - i >= 0)grid[curx - i][cury] = 0;
        if (cury - i >= 0)grid[curx][cury - i] = 0;

    }

    for (int i{ 0 };i < n;i++) {
        list <int> tmp;
        for (int j{ 0 };j < n;j++) {
            if (grid[j][i] != 0)tmp.push_back(grid[j][i]);
        }

        while (tmp.size() != n) {
            tmp.push_front(0);
        }

        for (int k{ 0 };k < n;k++) {
            grid[k][i] = tmp.front();
            tmp.pop_front();
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout <<  grid[i][j] << " ";
        }
        cout << endl;
    }



    return 0;
}
