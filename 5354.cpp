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

        if(N == 1)
            printf("#\n");
        else {
            for (int i = 1; i <= N; i++) {
                printf("#");
            }
            printf("\n");

            for (int i = 1; i <= N - 2; i++) {
                printf("#");
                for (int i = 1; i <= N - 2; i++) {
                    printf("J");
                }
                printf("#\n");
            }

            for (int i = 1; i <= N; i++) {
                printf("#");
            }
            printf("\n");
        }
        if(T == 0) {

        } else
            printf("\n");
    }

    return 0;
}

