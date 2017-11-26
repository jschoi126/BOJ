//
// Created by Choi on 2017. 10. 2..
//
#include <iostream>
#include <climits>
using namespace std;
#define MAX INT_MAX

int dp[401][401];

int main () {
    int V, E;
    scanf("%d %d", &V, &E);

    for(int i = 1; i <= V; i++) {
        for(int j = 1; j <= V; j++) {
                dp[i][j] = MAX;
        }
    }

    int from, to, cost;
    for(int i = 1; i <= E; i++) {
        scanf("%d %d %d", &from, &to, &cost);
        if (dp[from][to] > cost)
            dp[from][to] = cost;
    }

    //Floyd-Warshall
    for(int k = 1; k <= V; k++)
        for(int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++) {
                if (dp[i][k] == MAX || dp[k][j] == MAX)
                    continue;
                if (dp[i][j] > dp[i][k] + dp[k][j])
                    dp[i][j] = dp[i][k] + dp[k][j];
            }
        }

    int min = MAX;
    for(int i = 1; i <= V; i++) {
        if(dp[i][i] < min)
            min = dp[i][i];
    }

    if(min == MAX)
        cout << -1 << endl;
    else
        cout << min << endl;
    return 0;
}
