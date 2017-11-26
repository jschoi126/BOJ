//
// Created by Choi on 2017. 10. 2..
//
#include <iostream>
#include <cstring>
using namespace std;

long long int dp[91][1];

int main () {
    memset(dp, 0, sizeof(dp));

    int N;
    cin >> N;

    /* 1, 10, 100, 101, 1000, 1001, 1010
     * XX00
     * XX10
     * XX01
     * XX11 -> X
     * dp[N][0] = dp[N-1]
     */
    dp[1][0] = 0;
    dp[1][1] = 1;

    for(int i = 2; i <= N; i++) {
        dp[i][1] = dp[i - 1][0];
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
    }

    cout << dp[N][0] + dp[N][1] << endl;
    return 0;
}

