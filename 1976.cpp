//
// Created by Choi on 2017. 10. 18..
//
#include <iostream>
#include <vector>
using namespace std;

int parent[201];

int find(int x) {
    if(parent[x] == x)
        return x;
    else {
        int y = find(parent[x]);
        parent[x] = y;
        return y;
    }
}

void make_union(int a, int b) {
    a = find(a);
    b = find(b);
    parent[b] = a;
}

int main() {
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);

    for(int i = 0; i <= 200; i++) {
        parent[i] = i;
    }

    int temp;
    for(int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &temp);
            if(temp == 1) {
                make_union(i,j);
            }
        }
    }

    vector<int> v;
    for(int i = 1; i <= M; i++) {
        scanf("%d", &temp);
        v.push_back(temp);
    }

    for(int i = 1; i <= N; i++) {
        find(i);
    }

    bool can_go = true;
    int p = parent[v[0]];
    for(int i = 0; i < v.size(); i++) {
        if(p != parent[v[i]]) {
            can_go = false;
            break;
        }
    }

    if(can_go)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}

