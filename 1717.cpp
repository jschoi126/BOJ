//
// Created by Choi on 2017. 10. 16..
//
#include <iostream>
using namespace std;

int parent[1000001];

int find(int x) {
    if(x == parent[x])
        return x;
    else {
        int y =  find(parent[x]);
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
    cin >> n >> m;

    for(int i = 0; i <= n; i++)
        parent[i] = i;

    int what, x, y;
    for(int i = 1; i <= m; i++) {
        cin >> what >> x >> y;
        if(what == 1) {
            if(find(x) == find(y)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else if (what == 0) {
            make_union(x, y);
        }
    }

//    for(int i = 1; i <= n; i++)
//        cout << parent[i] << " ";
//    cout << endl;

    return 0;
}
