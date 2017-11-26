#include <iostream>
#include <vector>
using namespace std;

bool found_solution = false;
bool visited[2001] = {false};
vector<int> edge[2001];

void dfs(int current, int count) {
    if(count == 5) {
        found_solution = true;
        return;
    }

    for(vector<int>::iterator iter = edge[current].begin(); iter != edge[current].end(); iter++) {
        if(!visited[*iter]) {
            visited[*iter] = true;
            dfs(*iter, count + 1);
            visited[*iter] = false;
        }
    }
}

int main() {

    int N, M;
    cin >> N >> M;

    int tmp1, tmp2;
    for (int i = 0; i < M; i++) {
        cin >> tmp1 >> tmp2;
        edge[tmp1].push_back(tmp2);
        edge[tmp2].push_back(tmp1);
    }

    for(int i = 0; i < N; i++) {
        visited[i] = true;
        dfs(i, 1);
        visited[i] = false;
        if(found_solution)
            break;
    }


    if(found_solution)
        cout << 1 << endl;
    else
        cout << 0 << endl;

    return 0;
}
