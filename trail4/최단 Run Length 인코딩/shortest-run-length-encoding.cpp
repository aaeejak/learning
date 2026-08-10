#include <iostream>
#include <string>
#include <stack>
using namespace std;

string A;
stack <char> RLE;

int main() {
    cin >> A;


    int ML{2000};
    //한번씩 쉬프트하면서 알아보기
    for (int l{ 0 };l<A.size();l++){
        //RLE한 길이 구하기
        int tmp{ 0 };
        for (int i{ 0 }; i < A.size(); i++) {

            if (RLE.empty()) {
                RLE.push(A[i]);
            }
            else if (RLE.top() == A[i]) {
                RLE.push(A[i]);
            }
            else {
                tmp++;
                unsigned long long q = RLE.size(), cnt{ 0 };
                while (q != 0) {
                    q /= 10;
                    cnt++;
                }

                tmp += cnt;
                while (!RLE.empty()) {
                    RLE.pop();
                }
                RLE.push(A[i]);
            }
        }
        if (!RLE.empty()) {
            tmp++;
            unsigned long long q = RLE.size() , cnt{ 0 };
            while (q != 0) {
                q /= 10;
                cnt++;
            }

            tmp += cnt;
            while (!RLE.empty()) {
                RLE.pop();
            }

        }
        
        ML = (ML > tmp) ? tmp : ML;
        char tmp2{ A[0] };
        for (int k{ 0 }; k < A.size()-1; k++) {
            A[k] = A[k + 1];
        }
        A[A.size() - 1] = tmp2;

    }

    cout << ML;

    return 0;
}
