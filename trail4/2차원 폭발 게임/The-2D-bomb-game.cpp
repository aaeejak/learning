#include <iostream>
#include <stack>
#include <list>
using namespace std;

int N, M, K;
int numbers_2d[100][100];
int numbers_2d_tmp[100][100];

int main() {
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> numbers_2d[i][j];
        }
    }

    while (K--) {
        //연속 폭탄 처리
        for (int j{ 0 }; j < N; j++) {
            stack<int> bucket;

            list <int> tmp;
            bool bomb = false;
            do {
                bomb = false;
                for (int i{ 0 }; i < N; i++) {
                    if (numbers_2d[i][j] == 0) continue;

                    if (bucket.empty() || bucket.top() == numbers_2d[i][j]) {
                        bucket.push(numbers_2d[i][j]);
                    }
                    else if (bucket.top() != numbers_2d[i][j]) {
                        if (bucket.size() >= M) {
                            bomb = true;
                            while (!bucket.empty()) {
                                bucket.pop();
                            }
                        }
                        else {
                            while (!bucket.empty()) {
                                tmp.push_back(bucket.top());
                                bucket.pop();
                            }
                        }
                        bucket.push(numbers_2d[i][j]);
                    }
                }
                //마지막 폭탄처리
                if (bucket.size() >= M) {
                    while (!bucket.empty()) {
                        bucket.pop();
                    }
                }
                else {
                    while (!bucket.empty()) {
                        tmp.push_back(bucket.top());
                        bucket.pop();
                    }
                }
                //빈공간 채우기
                while (tmp.size() < N) {
                    tmp.push_front(0);
                }
                //중력작용한 폭탄 채우기
                for (int i{ 0 }; i < N; i++) {
                    numbers_2d[i][j] = tmp.front();
                    tmp.pop_front();
                }
            } while (bomb);
        }
        //시계방향 90 돌리기
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
               numbers_2d_tmp[i][j] = numbers_2d[i][j];
            }
        }

        for (int i{ N - 1 }; i >= 0; i--) {
            list <int>tmp;
            for (int j{ 0 }; j < N; j++) {
                if (numbers_2d_tmp[i][j] == 0)continue;

                tmp.push_back(numbers_2d_tmp[i][j]);
            }
            //빈공간 채우기
            while (tmp.size() < N) {
                tmp.push_front(0);
            }

            for (int j{ 0 }; j < N; j++) {
                numbers_2d[j][N - 1 - i] = tmp.front();
                tmp.pop_front();
            }
        }

    }

    for (int j{ 0 }; j < N; j++) {
        stack<int> bucket;

        list <int> tmp;
        
        bool bomb = false;
        do{
            bomb = false;
            for (int i{ 0 }; i < N; i++) {
                if (numbers_2d[i][j] == 0) continue;

                if (bucket.empty() || bucket.top() == numbers_2d[i][j]) {
                    bucket.push(numbers_2d[i][j]);
                }
                else if (bucket.top() != numbers_2d[i][j]) {
                    if (bucket.size() >= M) {
                        bomb = true;
                        while (!bucket.empty()) {
                            bucket.pop();
                        }
                    }
                    else {
                        while (!bucket.empty()) {
                            tmp.push_back(bucket.top());
                            bucket.pop();
                        }
                    }
                    bucket.push(numbers_2d[i][j]);
                }
            }
            //마지막 폭탄처리
            if (bucket.size() >= M) {
                while (!bucket.empty()) {
                    bucket.pop();
                }
            }
            else {
                while (!bucket.empty()) {
                    tmp.push_back(bucket.top());
                    bucket.pop();
                }
            }
            //빈공간 채우기
            while (tmp.size() < N) {
                tmp.push_front(0);
            }
            //중력작용한 폭탄 채우기
            for (int i{ 0 }; i < N; i++) {
                numbers_2d[i][j] = tmp.front();
                tmp.pop_front();
            }
        } while (bomb);
    }

    //갯수 세기
    int cnt{ 0 };
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (numbers_2d[i][j] != 0)cnt++;
        }
    }
    cout << cnt;


    return 0;
}
