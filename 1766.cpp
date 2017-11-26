#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;

vector<int> adj[32001];
int ref_count[32001] = {0};

int main() {
    cin >> N >> M;
    int tmp1, tmp2;
    for(int i = 0; i < M; i++) {
        cin >> tmp1 >> tmp2;
        adj[tmp1].push_back(tmp2);
        ref_count[tmp2]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 1; i <= N; i++) {
        if(ref_count[i] == 0) {
            pq.push(i);
        }
    }

    int current;
    while(!pq.empty()) {
        current = pq.top();
        pq.pop();
        priority_queue<int, vector<int>, greater<int>> Q;
        Q.push(current);
        while(!Q.empty()){
            current = Q.top();
            Q.pop();
            cout << current << " ";
            for(vector<int>::iterator iter = adj[current].begin(); iter != adj[current].end(); iter++) {
                ref_count[*iter]--;
                if(ref_count[*iter] == 0) {
                    Q.push(*iter);
                }
            }
        }
    }
    cout << endl;
}
