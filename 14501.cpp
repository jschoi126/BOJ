//
// Created by Choi on 2017. 9. 29..
//
#include <iostream>
#include <cstring>
using namespace std;

int N;
int T[20], P[20], d[20];

int main () {
    cin >> N;

    memset(d, 0, sizeof(d));

    for(int i = 1; i <= N; i++) {
        cin >> T[i] >> P[i];
    }

    for(int i = 1; i <= N; i++) {
//        cout << "i = " << i << endl;
        d[i] = d[i - 1];
        int max = d[i];
        for(int j = 1; j <= i; j++) {
            if(j + T[j] - 1 == i && max < d[j - 1] + P[j]) {
//                cout << "j = " << j << endl;
//                cout << d[j - 1] <<", " <<P[j] << endl;
                max = d[j - 1] + P[j];
            }
        }
        d[i] = max;
    }

//    for(int i = 1; i <= N; i++)
//        cout << d[i] << " ";
//    cout << endl;

    cout << d[N] << endl;
}

