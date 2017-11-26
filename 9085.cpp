//
// Created by Choi on 2017. 10. 18..
//
#include <iostream>
using namespace std;


int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int N;
        scanf("%d", &N);
        long long sum = 0;
        long long temp;
        for(int i = 1; i <= N; i++) {
            scanf("%lld", &temp);
            sum += temp;
        }

        printf("%lld\n", sum);
    }

    return 0;
}

