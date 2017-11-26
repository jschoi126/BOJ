//
// Created by Choi on 2017. 10. 18..
//
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    string val;
    cin >> val;

    long long sum = 0;
    for(int i = 0; i < N; i++) {
        sum += val[i] - '0';
    }

    cout << sum << endl;

    return 0;
}