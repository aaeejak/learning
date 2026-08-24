#include <iostream>
#include <cmath>
using namespace std;

int n, m, r, c;
int a[101][101] = { 0 };
int tmp[101][101] = { 0 };

int main() {
    cin >> n >> m >> r >> c;

    a[r-1][c-1] = 1;
    tmp[r - 1][c - 1] = 1;
    //m 시간
    for (int i{ 1 };i <= m;i++) {
        //모든인덱스에 대해
        for (int j{ 0 };j < n;j++) {
            for (int l{ 0 };l < n;l++) {
                if (a[j][l] == 0)continue;
                long long int range = pow(2, i-1);
                //tmp에 폭탄 위치
                if (j + range < n)tmp[j + range][l] = 1;
                if (j - range >= 0)tmp[j - range][l] = 1;

                if (l + range < n)tmp[j][l + range] = 1;
                if (l - range >= 0)tmp[j][l - range] = 1;
            }
        }

        //a에 복사
        for (int j{ 0 };j < n;j++) {
            for (int l{ 0 };l < n;l++) {
                a[j][l] = tmp[j][l];
            }
        }
    }

    int sum{ 0 };
    for (int j{ 0 };j < n;j++) {
        for (int l{ 0 };l < n;l++) {
            sum += a[j][l];
        }
    }
    cout << sum;

    return 0;
}
