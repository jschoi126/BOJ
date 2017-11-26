//
// Created by Choi on 2017. 10. 2..
//
#include <iostream>
using namespace std;

long long dp[1005][10];

int main () {
    int N;
    cin >> N;
    for(int i = 0; i < 1005; i++) {
        for(int j = 0; j < 10; j++) {
            dp[i][j] = 0;
        }
    }
    /*
     * 0,1,2,3,4,5,6,7,8,9
     * 11,12,13 --- 19
     * 22,23 --- 29
     */

    long long sum = 0;
    for(int i = 0; i <= 9; i++)
        dp[1][i] = 1;

    for(int i = 2; i <= N; i++) {
        for(int j = 0; j <= 9; j++) {
            for(int k = 0; k <= j; k++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % 10007;
            }
        }
    }

    for(int i = 0; i <= 9; i++)
        sum += dp[N][i];
    cout << sum % 10007 << endl;

    return 0;
}

