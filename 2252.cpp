#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[32001];
int ind[32001] = {0};
bool visited[32001] = {false};

bool finished(int N) {
    for(int i = 1; i <= N; i++) {
        if(!visited[i])
            return false;
    }
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;

    int tmp1, tmp2;
    //나에게 들어오는 방향 간선의 리스트

    for(int i = 0; i < M; i++) {
        cin >> tmp1 >> tmp2;
        adj[tmp1].push_back(tmp2);
        ind[tmp2]++;
    }

    queue<int> Q;
    int print_count = 0;
    while(!finished(N)) {
        for (int i = 1; i <= N; i++) {
            if (!visited[i] && (ind[i] == 0)) {
                visited[i] = true;
                Q.push(i);
            }
        }
        while(!Q.empty()) {
            int current = Q.front();
            Q.pop();
            for (vector<int>::iterator iter = adj[current].begin(); iter != adj[current].end(); iter++) {
                ind[*iter]--;
            }
            print_count++;
            if (print_count == N) {
                cout << " " << current << endl;
            } else if (print_count == 1) {
                cout << current;
            } else {
                cout << " " << current;
            }
        }
    }

    return 0;
}
