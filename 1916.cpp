//
// Created by Choi on 2017. 10. 2..
//
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

vector<vector<pair<int,int>>> e;
int d[10001];

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    memset(d, 99, sizeof(d));

    for(int i = 0; i <= 1001; i++) {
        vector<pair<int, int>> v;
        e.push_back(v);
    }

    int from, to, cost;
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &from, &to, &cost);
        e[from].push_back(make_pair(to, cost));
        //e[to].push_back(make_pair(from, cost));
    }

    scanf("%d %d", &from, &to);

    priority_queue<pair<int, int>> pq;
    d[from] = 0;
    pq.push(make_pair(0, from));

    pair<int, int> current;
    while(!pq.empty()){
        current = pq.top();
        int current_from = current.second;
        int current_cost = -current.first;

        pq.pop();

        for(int i = 0; i < e[current_from].size(); i++) {
            if(d[e[current_from][i].first] > e[current_from][i].second + current_cost) {
                d[e[current_from][i].first] = e[current_from][i].second + current_cost;
                pq.push(make_pair(-d[e[current_from][i].first], e[current_from][i].first));
            }
        }
    }

    cout << d[to] << endl;

    return 0;
}