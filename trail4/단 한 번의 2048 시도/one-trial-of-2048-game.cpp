#include <iostream>
#include <list>
using namespace std;

int grid[4][4];
char dir;

int main() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> dir;

    if (dir == 'L') {
        for (int i{ 0 };i < 4;i++) {
            list <int> tmp;
            bool sum = false;
            for (int j{ 0 };j < 4;j++){
                if (grid[i][j] == 0) {
                    continue;
                }

                if (tmp.empty()) {
                    tmp.push_back(grid[i][j]);
                }
                else if (tmp.back() == grid[i][j] && !sum) {
                    tmp.pop_back();
                    sum = true;
                    tmp.push_back(grid[i][j] * 2);
                }
                else {
                    tmp.push_back(grid[i][j]);
                    sum = false;
                }
            }
            while (tmp.size() < 4) {
                tmp.push_back(0);
            }

            for (int j{ 0 };j < 4;j++) {
                grid[i][j] = tmp.front();
                tmp.pop_front();
            }

        }
    }
    else if (dir == 'R') {
        for (int i{ 0 };i < 4;i++) {
            list <int> tmp;
            bool sum = false;
            for (int j{ 3 };j >=0;j--) {
                if (grid[i][j] == 0) {
                    continue;
                }

                if (tmp.empty()) {
                    tmp.push_front(grid[i][j]);
                }
                else if (tmp.front() == grid[i][j] && !sum) {
                    tmp.pop_front();
                    sum = true;
                    tmp.push_front(grid[i][j] * 2);
                }
                else {
                    tmp.push_front(grid[i][j]);
                    sum = false;
                }
            }
            while (tmp.size() < 4) {
                tmp.push_front(0);
            }

            for (int j{ 0 };j < 4;j++) {
                grid[i][j] = tmp.front();
                tmp.pop_front();
            }

        }
    }
    else if (dir == 'U') {
        for (int j{ 0 };j < 4;j++) {
            list <int> tmp;
            bool sum = false;
            for (int i{ 0 };i < 4;i++) {
                if (grid[i][j] == 0) {
                    continue;
                }

                if (tmp.empty()) {
                    tmp.push_back(grid[i][j]);
                }
                else if (tmp.back() == grid[i][j] && !sum) {
                    tmp.pop_back();
                    sum = true;
                    tmp.push_back(grid[i][j] * 2);
                }
                else {
                    tmp.push_back(grid[i][j]);
                    sum = false;
                }
            }
            while (tmp.size() < 4) {
                tmp.push_back(0);
            }

            for (int i{ 0 };i < 4;i++) {
                grid[i][j] = tmp.front();
                tmp.pop_front();
            }
        }
    }
    else {
        for (int j{ 0 };j < 4;j++) {
            list <int> tmp;
            bool sum = false;
            for (int i{ 3 };i >= 0;i--) {
                if (grid[i][j] == 0) {
                    continue;
                }

                if (tmp.empty()) {
                    tmp.push_front(grid[i][j]);
                }
                else if (tmp.front() == grid[i][j] && !sum) {
                    tmp.pop_front();
                    sum = true;
                    tmp.push_front(grid[i][j] * 2);
                }
                else {
                    tmp.push_front(grid[i][j]);
                    sum = false;
                }
            }
            while (tmp.size() < 4) {
                tmp.push_front(0);
            }

            for (int i{ 0 };i < 4;i++) {
                grid[i][j] = tmp.front();
                tmp.pop_front();
            }

        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    
    
    return 0;
}
