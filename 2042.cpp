//
// Created by Choi on 2017. 10. 11..
//
#include <iostream>
#include <cstring>
using namespace std;

long long arr[1000001];
long long fenwick[1000001];

long long sum(int i) {
    long long ret = 0;
    while(i > 0) {
        ret += fenwick[i];
        i -= i & -i;
    }
    return ret;
}

void update(int i, int n, long long val) {
    while(i <= n) {
        fenwick[i] += val;
        i += i & -i;
    }
}

int main() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);

    memset(arr, 0, sizeof(arr));
    memset(fenwick, 0, sizeof(fenwick));

    for(int i = 1; i <= N; i++) {
        scanf("%lld", &arr[i]);
        update(i, N, arr[i]);
    }
//    for(int i = 1; i <= N; i++)
//        printf("%lld ", fenwick[i]);
//    printf("\n");

    int a;
    for(int i = 1; i <= M + K; i++) {
        scanf("%d", &a);
        if(a == 1) {
            int b;
            long long c;
            scanf("%d %lld", &b, &c);
            long long diff = c - arr[b];
            arr[b] = c;
            update(b, N, diff);
        } else if (a == 2) {
            int b, c;
            scanf("%d %d", &b, &c);
            printf("%lld\n", sum(c) - sum(b - 1));
        }
    }
    return 0;
}