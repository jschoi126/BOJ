//
// Created by Choi on 2017. 9. 27..
//
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int arr[10001];

int main() {
    int N;
    scanf("%d", &N);
    int temp;

    memset(arr, 0, sizeof(arr));

    for(int i = 0; i < N; i++) {
        scanf("%d", &temp);
        arr[temp]++;
    }

    for(int i = 1; i < 10001; i++) {
        if(arr[i] > 0) {
            while(arr[i] > 0) {
                printf("%d\n", i);
                arr[i]--;
            }
        }
    }

}

