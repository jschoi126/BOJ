//
// Created by Choi on 2017. 9. 23..
//
#include <iostream>
#include <queue>
using namespace std;

int main() {

    priority_queue<pair<int, int>> pq;

    int N;
    scanf("%d", &N);

    int tmp1, tmp2;
    for(int i = 0; i < N; i++) {
        scanf("%d %d", &tmp1, &tmp2);
        pq.push(make_pair(-tmp1, -tmp2));
    }

    while(!pq.empty()) {
        printf("%d %d\n", -pq.top().first, -pq.top().second);
        pq.pop();
    }

    return 0;
}
