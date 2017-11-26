//
// Created by Choi on 2017. 10. 2..
//
#include <iostream>
#include <climits>
using namespace std;
#define MAX INT_MAX

int N, M;
int dp[105][105];

int main () {
    scanf("%d %d", &N, &M);

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++){
            if(i==j)
                dp[i][j] = 0;
            else
                dp[i][j] = MAX;
        }
    }

    int from, to;
    for(int i = 1; i <= M; i++) {
        scanf("%d %d", &from, &to);
        dp[from][to] = 1;
        dp[to][from] = 1;
    }

    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(dp[i][k] == MAX || dp[k][j] == MAX)
                    continue;
                if(dp[i][j] > dp[i][k] + dp[k][j])
                    dp[i][j] = dp[i][k] + dp[k][j];
            }
        }
    }

    int min = MAX;
    int who = -1;

    for(int i = 1; i <= N; i++) {
        int sum = 0;
        for(int j = 1; j <= N; j++) {
            if(dp[i][j] == MAX)
                continue;
            sum += dp[i][j];
        }
        if(sum < min) {
            min = sum;
            who = i;
        }
    }

    cout << who << endl;
    return 0;
}