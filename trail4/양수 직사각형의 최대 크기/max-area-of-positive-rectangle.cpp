#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int grid[20][20];

int main() {

    cin >> n >> m;

    for (int i{ 0 }; i < n; i++) {
        for (int l{ 0 }; l < m; l++) {
            cin >> grid[i][l];
        }
    }
    

    //인덱스 접근
    int result{ -1 };
    for (int i{ 0 }; i < n; i++) {
        for (int l{ 0 }; l < m; l++) {
                    //인덱스 직사각형 크기
                    for (int q{ 1 }; q <= n - i; q++) {
                        for (int w{ 1 }; w <= m - l; w++) {
                            int tmp{ 0 }; // 직사각형의 크기
                            //인덱스 직사각형 합
                            for (int o{ 0 }; o < q; o++) {
                                for (int p{ 0 }; p < w; p++) {
                                    if (grid[i + o][l + p] <= 0) {
                                        tmp = -1;
                                        break;
                                    }
                                    tmp++;
                                }
                            }
                            result = max(result, tmp);
                        }
                    }
        }
    }

    cout << result;

    return 0;
}

