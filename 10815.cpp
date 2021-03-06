//
// Created by Choi on 2017. 9. 27..
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<long long> v;

bool binary_search(long long n, int start, int end) {
    int index = (start + end) / 2;

    if(v[index] == n)
        return true;
    if(start >= end)
        return false;
    if(v[index] > n) {
        return binary_search(n, start, index - 1);
    } else {
        return binary_search(n, index + 1, end);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    long long temp;
    for(int i = 0 ; i < N; i++) {
        scanf("%lld", &temp);
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    int len = v.size();

    int M;
    scanf("%d", &M);

    for(int i = 0 ; i < M; i++) {
        scanf("%lld", &temp);
        if(binary_search(temp, 0, len - 1))
            printf("1 ");
        else
            printf("0 ");
    }
    printf("\n");

    return 0;
}
