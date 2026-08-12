#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector <int> result;
    queue <int> tmp;
    queue <int> S;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        if (S.empty() || S.front() == k) {
            S.push(k);
        }
        else if (S.front()!=k){
            if (S.size() >= m) {
                while (!S.empty()) {
                    S.pop();
                }
                S.push(k);
            }
            else {
                while (!S.empty()) {
                    tmp.push(S.front());
                    S.pop();
                }
                S.push(k);
            }
        }
    }

    if (S.size() >= m) {
        while (!S.empty()) {
            S.pop();
        }
    }
    else {
        while (!S.empty()) {
            tmp.push(S.front());
            S.pop();
        }
    }
    
    while(true){
        bool boom = false;
        queue <int> pre;
        while (!tmp.empty()) {
            int k{ tmp.front() };
            if (S.empty() || S.front() == k) {
                S.push(k);
            }
            else if (S.front() != k) {
                if (S.size() >= m) {
                    boom = true;
                    while (!S.empty()) {
                        S.pop();
                    }
                    S.push(k);
                }
                else {
                    while (!S.empty()) {
                        pre.push(S.front());
                        S.pop();
                    }
                    S.push(k);
                }
            }
            tmp.pop();
        }

        if (S.size() >= m) {
            boom = true;
            while (!S.empty()) {
                S.pop();
            }
        }
        else {
            while (!S.empty()) {
                pre.push(S.front());
                S.pop();
            }
        }

        tmp = pre;
        if (!boom) break;

    }

    while (!tmp.empty()) {
        result.push_back(tmp.front());
        tmp.pop();
    }

    cout << result.size() << endl;
    for (int x : result) {
        cout << x << endl;
    }
    
    

    return 0;
}
