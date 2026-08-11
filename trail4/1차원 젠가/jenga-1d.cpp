#include <iostream>
#include <vector>
using namespace std;

int n;
int s1, e1;
int s2, e2;

int main() {
    cin >> n;
    vector<int> blocks;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        blocks.push_back(k);
    }
    cin >> s1 >> e1;
    cin >> s2 >> e2;

    vector<int> tmp;
    for (int i{ 0 };i < n;i++) {
        if (i >= s1 - 1 && i <= e1 - 1) continue;
        tmp.push_back(blocks[i]);
    }

    vector<int> tmp2;
    for (int i{ 0 };i < tmp.size();i++) {
        if (i >= s2 - 1 && i <= e2 - 1) continue;
        tmp2.push_back(tmp[i]);
    }

    if (tmp2.empty()) {
        cout << 0;
    }
    else {
        cout << tmp2.size() << endl;
        for (int x : tmp2) {
            cout << x << endl;
        }
    }

    return 0;
}
