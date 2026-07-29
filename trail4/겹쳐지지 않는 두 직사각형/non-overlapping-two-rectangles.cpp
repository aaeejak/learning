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

    // 첫 인덱스를 잡고 -> 두번째 인덱스를 잡아서 두 인덱스에서 직사각형 만들기
    // 그 후 최댓값 구하기
    // 첫 인덱스에 접근

    int result{ -2001 };
    for (int i{ 0 }; i < n; i++) {
        for (int l{ 0 }; l < m; l++) {
            
            //두번째 인덱스 접근 -> 첫 인덱스와 겹치면 안됨
            for (int s{ 0 }; s < n; s++) {
                for (int r{ 0 }; r < m; r++) {

                    if (s == i && r == l)continue; //인덱스 같으면 스킵

                    //첫 인덱스 직사각형 크기
                    for (int q{ 1 }; q <= n - i; q++) {
                        for (int w{ 1 }; w <= m - l; w++) {
                            //만약 두번째와 겹치면 끝
                            if (i + q -1 >= s && l + w -1 >= r)break;
                            int tmp{ 0 }; // 직사각형의 합
                            //첫 인덱스 직사각형 합
                            for (int o{ 0 }; o < q; o++) {
                                for (int p{ 0 }; p < w; p++) {
                                    tmp += grid[i + o][l + p];
                                }
                            }
                            //두번째 인덱스 직사각형 크기
                            for (int d{ 1 }; d <= n - s; d++) {
                                for (int f{ 1 }; f <= m - r; f++) {
                                    int tmp2{ tmp };
                                    //두번째 인덱스 직사각형 합
                                    for (int g{ 0 }; g < d; g++) {
                                        for (int h{ 0 }; h < f; h++) {
                                            tmp2 += grid[s + g][r + h];
                                        }
                                    }

                                    
                                    result = max(result, tmp2);
                                }
                            }


                        }
                    }


                }
            }

        }
    }

    cout << result;

    return 0;
}
