#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int n, m;
int grid[20][20];
int move_nums[100];
int dx[8] = { -1,-1,-1,0,1,1, 1, 0 };
int dy[8] = { -1, 0, 1,1,1,0,-1,-1 };

list <int>::iterator find_num(list <int>& grid, int num) {
    if (grid.empty())return grid.end();
    list<int>::iterator it = grid.begin();
    for (int i{ 0 };i < grid.size();i++) {
        if (*it == num)return it;
        it++;
    }
    return grid.end();
}

int find_max(list <int>& grid) {
    if (grid.empty())return 0;
    int tmp{ 0 };
    for (int x : grid) {
        tmp = max(tmp, x);
    }
    return tmp;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> move_nums[i];
    }

    list <int> grid2[20][20];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid2[i][j].push_back(grid[i][j]);
        }
    }
    //리스트 앞이 아래 뒤가 위
    for (int o{ 0 };o < m;o++) {
        bool find = false;
        int move_num = move_nums[o];
        for (int i = 0; i < n; i++) {
            if (find)break;
            for (int j = 0; j < n; j++) {
                if (find)break;
                if (grid2[i][j].empty())continue;
                list <int>::iterator it = find_num(grid2[i][j], move_num);
                if (it != grid2[i][j].end()) { //움직일 숫자 찾음
                    find = true;
                    list <int> tmp;
                    if (grid2[i][j].size() == 1) {
                        tmp.push_back(grid2[i][j].front());
                        grid2[i][j].pop_front();
                    }
                    else {
                        while (it != grid2[i][j].end()) {
                            tmp.push_back(*it);
                            grid2[i][j].erase(it++);
                        }
                    }
                    //움직일 곳 찾기
                    int x, y;
                    int mx{0};
                    for (int p{ 0 };p < 8;p++) {
                        if (i + dx[p] >= 0 && i + dx[p] < n &&
                            j + dy[p] >= 0 && j + dy[p] < n) {
                            int tmp2 = find_max(grid2[i + dx[p]][j + dy[p]]);
                            if (tmp2 > mx) {
                                mx = tmp2;
                                x = dx[p];
                                y = dy[p];
                            }
                        }
                    }
                    if (mx != 0) { //가장 큰 숫자가 있는 곳으로 이동
                        while(!tmp.empty()){
                            grid2[i + x][j + y].push_back(tmp.front());
                            tmp.pop_front();
                        }
                    }
                    else {
                        while (!tmp.empty()) {
                            grid2[i][j].push_back(tmp.front());
                            tmp.pop_front();
                        }
                    }

                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid2[i][j].empty()) {
                cout << "None" << endl;
            }
            else {
                while (!grid2[i][j].empty()) {
                    cout << grid2[i][j].back() << " ";
                    grid2[i][j].pop_back();
                }
                cout << endl;
            }
        }
    }

    return 0;
}
