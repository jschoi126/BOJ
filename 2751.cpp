//
// Created by Choi on 2017. 9. 23..
//
#include <iostream>
#include <queue>
using namespace std;

int main() {

    priority_queue<int> pq;

    int N;
    scanf("%d", &N);

    int tmp;
    for(int i = 0; i < N; i++) {
        scanf("%d", &tmp);
        pq.push(-tmp);
    }

    while(!pq.empty()) {
        printf("%d\n", -pq.top());
        pq.pop();
    }

    return 0;
}
