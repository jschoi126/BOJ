//
// Created by Choi on 2017. 10. 2..
//

#include <iostream>
#include <cstring>
#include <climits>
//#define MAX 88
#define MAX INT_MAX
using namespace std;

int dp[105][105];
int n, m;
//
//void print_dp() {
//    for(int i = 1; i <= n; i++) {
//        for(int j = 1; j <= n; j++) {
//            printf("%d ", dp[i][j]);
//        }
//        cout << endl;
//    }
//}


int main() {
    cin >> n;
    cin >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) {
                dp[i][j] = 0;
            }
            else {
                dp[i][j] = MAX;
            }
        }
    }

    int from, to, cost;
    for(int i = 1; i <= m; i++) {
        scanf("%d %d %d", &from, &to, &cost);
        if(dp[from][to] > cost)
            dp[from][to] = cost;
    }

//  print_dp();
    int temp;
    //floyd-warshall
    for(int k = 1; k <= n; k++) {
//        cout << "k = " << k << endl;
//        print_dp();
        for(int i = 1; i <= n; i++) {
            if(k == i)
                continue;
            for(int j = 1; j <= n; j++) {
                if(i == j || j == k)
                    continue;
                if(dp[i][k] == MAX || dp[k][j] == MAX)
                    continue;
                temp = dp[i][k] + dp[k][j];
                if(dp[i][j] > temp) {
                    dp[i][j] = temp;
                }
            }
        }
        //print_dp();
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(dp[i][j] == MAX)
                dp[i][j] = 0;
            printf("%d ", dp[i][j]);
        }
        cout << endl;
    }

    return 0;
}