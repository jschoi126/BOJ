//
// Created by Choi on 2017. 9. 27..
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N, K;

    scanf("%d %d", &N, &K);

    vector<long long> v;

    long long temp;
    for(int i = 0; i < N; i++) {
        scanf("%lld", &temp);
        v.push_back(temp);
        //pq.push(temp);
    }

    sort(v.begin(), v.end());

    cout << v[K-1] << endl;

    return 0;
}