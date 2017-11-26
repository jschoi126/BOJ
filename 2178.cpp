#include <iostream>
#include <cmath>
#include <queue>
#define MAX_N 101
using namespace std;

int map[MAX_N][MAX_N] = {0};
bool visited[MAX_N][MAX_N] = {false};

int move_x[4] = {1, 0, -1, 0};
int move_y[4] = {0, -1, 0, 1};

bool is_valid(int x, int y, int N, int M) {
    if ((x <= 0) || (x > N) || (y <= 0) || (y > M))
        return false;
    if (visited[x][y])
        return false;
    if (map[x][y] == 0)
        return false;
    return true;
}

int main() {

    int N, M;
    cin >> N >> M;
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M;j ++)
            scanf("%1d", &map[i][j]);
    }

    queue<pair<pair<int, int>,int>> q;
    int current_x = 1, current_y = 1, current_dist = 0;
    visited[current_x][current_y] = true;
    q.push(make_pair(make_pair(current_x,current_y), current_dist + 1));

    while(!q.empty()) {
        current_x = q.front().first.first;
        current_y = q.front().first.second;
        current_dist = q.front().second;
        q.pop();

        if((current_x == N) && (current_y == M)) {
            cout << current_dist << endl;
            return 0;
        }

        for(int i = 0; i  < 4; i++) {
            int new_x = current_x + move_x[i];
            int new_y = current_y + move_y[i];
            if(is_valid(new_x, new_y, N, M)) {
                visited[new_x][new_y] = true;
                q.push(make_pair(make_pair(new_x, new_y), current_dist + 1));
            }
        }
    }

    return 0;
}
