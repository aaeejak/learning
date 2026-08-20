#include <iostream>

using namespace std;

int n;
int r, c;
int a[101][101];

int main() {
    cin >> n >> r >> c;

    for (int i{ 0 }; i < n; i++) {
        for (int j{ 0 }; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int curx{ r-1 }, cury{ c-1 };
    int dx[4] = { -1,1,0,0 };
    int dy[4] = { 0,0,-1,1 };

    bool exist = true;
    while (exist) {
        cout << a[curx][cury] << " ";
        exist = false;
        int nxtx, nxty;
        int mx{ a[curx][cury]};
        for (int i{ 0 };i < 4;i++) {
            if (dx[i] + curx < n && curx + dx[i] >= 0 &&
                cury + dy[i] < n && cury + dy[i] >= 0) {
                if (a[curx + dx[i]][cury + dy[i]] > mx) {
                    mx = a[curx + dx[i]][cury + dy[i]];
                    nxtx = curx + dx[i];
                    nxty = cury + dy[i];
                    exist = true;
                    break;
                }
            }
        }
        if (exist) {

        curx = nxtx;
        cury = nxty;
        }
    }

    return 0;
}