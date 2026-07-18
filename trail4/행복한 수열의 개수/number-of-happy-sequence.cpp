#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int N,M;
    cin >> N>>M;
    vector <vector <int>> coin(N,vector<int> (N,0));
    for (int i{ 0 }; i < N; i++) {
        for (int l{ 0 }; l < N; l++) {
            cin >> coin[i][l];
        }
    }

    
    if (M == 1) {
        cout << N * 2;
    }
    else {
        int cnt{ 0 };
        for (int i{ 0 }; i < N; i++) {
            stack <int> happy;
            for (int l{ 0 }; l < N; l++) {
                if (happy.empty()) happy.push(coin[i][l]);
                else {
                    if (happy.top() == coin[i][l]) {
                        happy.push(coin[i][l]);
                        if (happy.size() >= M) {
                            cnt++;
                            break;
                        }
                    }
                    else {
                        while (!happy.empty()) {
                            happy.pop();
                        }
                        happy.push(coin[i][l]);
                    }
                }

            }
        }

        for (int i{ 0 }; i < N; i++) {
            stack <int> happy;
            for (int l{ 0 }; l < N; l++) {
                if (happy.empty()) happy.push(coin[l][i]);
                else {
                    if (happy.top() == coin[l][i]) {
                        happy.push(coin[l][i]);
                        if (happy.size() >= M) {
                            cnt++;
                            break;
                        }
                    }
                    else {
                        while (!happy.empty()) {
                            happy.pop();
                        }
                        happy.push(coin[l][i]);
                    }
                }

            }
        }
    cout << cnt;
    }

}