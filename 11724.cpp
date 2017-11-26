#include <iostream>
#include <vector>
using namespace std;

int connected_count = 0;
bool visited[1001] = {false};
vector<int> edge[1001];

void dfs(int current) {
    for(vector<int>::iterator iter = edge[current].begin(); iter != edge[current].end(); iter++) {
        if(!visited[*iter]) {
            visited[*iter] = true;
            dfs(*iter);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    int tmp1, tmp2;
    for(int i = 0; i < M; i++) {
        cin >> tmp1 >> tmp2;
        edge[tmp1 - 1].push_back(tmp2 - 1);
        edge[tmp2 - 1].push_back(tmp1 - 1);
    }

    for(int i = 0; i < N; i++) {
        if(!visited[i]) {
            visited[i] = true;
            connected_count++;
            dfs(i);
        }
    }

    cout << connected_count << endl;

    return 0;
}
