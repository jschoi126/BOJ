//
// Created by Choi on 2017. 10. 11..
//
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

void add(vector<int> &v, int i) {
    int n = v.size();
    while(i < n) {
        i -= i & -i;
    }
}
void update(vector<int> &v, int i) {
    int n = v.size();
    while(i > 0) {
        i += i & -i;
    }
}

int main() {
    int TC;
    cin >> TC;

    while(TC--) {
        int n, m;
        cin >> n >> m;
        vector<int> arr(n + 1);
        vector<int> fenwick(n + 1);

        int temp;
        for(int i = 1; i <= m; i++) {
            cin >> temp;
            arr.push_back(temp);
            update(fenwick, temp);
        }

        int what;
        for(int i = 1; i <= n; i++) {
            cin >> what;
            arr[] = i;
        }
    }

    return 0;
}

