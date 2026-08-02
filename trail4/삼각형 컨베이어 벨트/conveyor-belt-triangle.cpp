#include <iostream>
using namespace std;

int main() {
    int N,T;
    cin >> N >> T;

    int* trail = new int[N*3];

    for(int i{0};i<N*3;i++){
        cin >> trail[i];
    }

    for(int i{0};i<T;i++){
        int tmp = trail[N*3-1];
        for(int j{N*3-1};j>0;j--){
            trail[j] = trail[j-1];
        }
        trail[0]=tmp;
    }
   

    for(int i{0};i<N;i++){
        cout << trail[i] << " ";
    }
    cout << endl;
    for(int i{0};i<N;i++){
        cout << trail[i+N] << " ";
    }
    cout << endl;
    for(int i{0};i<N;i++){
        cout << trail[i+N*2] << " ";
    }

    return 0;
}