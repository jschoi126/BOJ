//
// Created by Choi on 2017. 9. 23..
//
#include <iostream>
#include <queue>
using namespace std;

int main() {

    priority_queue<pair<int, pair<int, string>>> pq;
    int N;
    scanf("%d", &N);
    int tmp;
    int serial = 0;
    char tmp_string[101];

    for(int i = 0; i < N; i++) {
        scanf("%d", &tmp);
        scanf("%s", tmp_string);
        string str(tmp_string);
        pq.push(make_pair(-tmp, make_pair(-serial, str)));
        serial++;
    }

    while(!pq.empty()) {
        printf("%d %s\n", -pq.top().first, pq.top().second.second.c_str());
        pq.pop();
    }

    return 0;
}
