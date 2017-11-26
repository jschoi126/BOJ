//
// Created by Choi on 2017. 10. 1..
//
#include <iostream>
#include <cstring>
using namespace std;

int N, K;

//dp[N][K] N을 0-N 까지의 정수 K개 더해서 만들 수 있는 경우의 수
int dp[201][210];

int main() {
    cin >> N >> K;

    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;
//    for(int i = 0; i <= N; i++) {
//        dp[0][i] = 1;
//    }

    for(int i = 0 ; i <= N; i++) {
        for(int j = 1; j <= K;j ++) {
            for(int k = 0; k <= i; k++) {
                dp[i][j] = (dp[i][j] + dp[i - k][j - 1]) % 1000000000;
            }
            //cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
        }
    }

    cout << dp[N][K] << endl;

    return 0;
}

