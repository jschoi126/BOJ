#include <iostream>
#include <queue>
#include <algorithm>
#define MAX_N 26
using namespace std;

int map[MAX_N][MAX_N] = {0};
int danji[MAX_N * MAX_N + 1] = {0};
bool visited[MAX_N][MAX_N] = {false};
int goto_x[4]={1, 0, -1 , 0};
int goto_y[4]={0, -1, 0 , 1};

bool is_valid(int x, int y, int N) {
    if((x < 0) || (x >= N) || (y < 0) || (y >= N))
        return false;
    if((map[x][y] == 0) || visited[x][y])
        return false;
    return true;
}

int main (){

    int N;
    cin >> N;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%1d", &map[i][j]);

    queue<pair<int,int>> Q;
    int danji_count = 0;

    for(int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(!visited[i][j] && (map[i][j] == 1)) {
                visited[i][j] = true;
                danji_count++;
                danji[danji_count] = 1;
                Q.push(make_pair(i,j));
                int current_x, current_y;
                while(!Q.empty()) {
                    current_x = Q.front().first;
                    current_y = Q.front().second;
                    Q.pop();
                    int new_x, new_y;
                    for(int k = 0; k < 4; k++) {
                        new_x = current_x + goto_x[k];
                        new_y = current_y + goto_y[k];
                        if(is_valid(new_x, new_y, N)) {
                            visited[new_x][new_y] = true;
                            danji[danji_count]++;
                            Q.push(make_pair(new_x, new_y));
                        }
                    }
                }
            }
        }
    }

    cout << danji_count << endl;

    sort(danji + 1, danji + danji_count + 1);

    for(int i = 1; i <= danji_count; i++)
        cout << danji[i] << endl;
    return 0;
}
