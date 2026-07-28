#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int grid[20][20];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int result{ 0 };

    for (int i{ 0 }; i < n; i++) { //모든점
        for (int j{ 0 }; j < n; j++) {

            for (int x{ 1 }; x < n; x++) { // 직사각형 한변의 길이
                for (int y{ 1 }; y < n; y++) {
                    int tmp{ 0 };
                    bool over = false;

                    int q{ i };
                    int w{ j };

                    for (int s{ 1 }; s <= x; s++) {
                        if (over)break;
                        if (q < 0 || q >= n || w < 0 || w >= n) {
                            over = true;
                            break;
                        }
                        tmp += grid[q][w];
                        q--;
                        w++;
                    }
                    for (int z{ 1 }; z <= y; z++) {
                        if (over)break;
                        if (q < 0 || q >= n || w < 0 || w >= n) {
                            over = true;
                            break;
                        }

                        tmp += grid[q][w];
                        q--;
                        w--;
                    }
                    for (int s{ 1 }; s <= x; s++) {
                        if (over)break;
                        if (q < 0 || q >= n || w < 0 || w >= n) {
                            over = true;
                            break;
                        }

                        tmp += grid[q][w];
                        q++;
                        w--;
                    }

                    
                    for (int z{ 1 }; z <= y; z++) {
                        if (over)break;   
                        if (q < 0 || q >= n || w < 0 || w >= n) {
                            over = true;
                            break;
                        }
                        tmp += grid[q][w];
                        q++;
                        w++;
                    }

                    if(!over)result = max(result, tmp);
                }
            }

        }
    }

    cout << result;

    return 0;
}
