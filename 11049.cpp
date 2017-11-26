//
// Created by Choi on 2017. 10. 1..
//
#include <iostream>
#include <cstring>
using namespace std;

int N;
int r[505];
int dp[505][505];

int main() {
    scanf("%d", &N);

    memset(r, 0, sizeof(r));
    memset(dp, 0, sizeof(dp));

    for(int i = 1; i <= N; i++) {
        scanf("%d %d", &r[i], &r[i + 1]);
    }
    if(N == 1) {
        cout << r[1] * r[2] << endl;
        return 0;
    }

    // dp[i][j] = min(dp[i][k] + dp[k + 1][j] + r[i] * r[k + 1] *r[j + 1])
    int temp;
    for(int diag = 1; diag < N; diag++) {
        for (int i = 1; i + diag <= N; i++) {
            int min = 987654321;
            for(int k = i; k + 1 <= i+ diag; k++) {
                temp = dp[i][k] + dp[k + 1][i + diag] + r[i] * r[k + 1] * r[i + diag + 1];
                if(temp < min) {
                    min = temp;
                }
            }
            dp[i][i + diag] = min;
        }
    }

    cout << dp[1][N] << endl;

    return 0;
}
