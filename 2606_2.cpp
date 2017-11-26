//
// Created by Choi on 2017. 10. 16..
//
#include <iostream>
using namespace std;

int parent[101];

int find(int x) {
    if(x == parent[x])
        return x;
    else {
        int y = find(parent[x]);
        parent[x] = y;
        return y;
    }
}

void make_union(int x, int y) {
    x = find(x);
    y = find(y);
    parent[y] = x;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i <= n; i++)
        parent[i] = i;

    int a, b;
    for(int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        make_union(a, b);
    }

    int k = find(1);
    int count = 0;
    for(int i = 2; i <= n; i++) {
        if(k == parent[i])
            count++;
    }

    for(int i = 1; i <= n; i++)
        cout << parent[i] << " ";
    cout << endl;

    cout << count << endl;

    return 0;
}