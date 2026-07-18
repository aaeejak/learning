#include<iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector <vector <int>> coin(N,vector<int> (N,0));
    for (int i{ 0 }; i < N; i++) {
        for (int l{ 0 }; l < N; l++) {
            cin >> coin[i][l];
        }
    }

    int max{ 0 };


    for (int i{ 0 }; i < N - 2; i++) {
        for (int l{ 0 }; l < N-2; l++) {
            
            int tmp{ 0 };
            for (int k{ 0 }; k < 3; k++) {
                for (int m{ 0 }; m < 3; m++) {
                    if (coin[i + k][l + m] == 1) {
                        tmp++;
                    }
                }
            }

            if (tmp > max)max = tmp;
        }
    }

    cout << max;
}