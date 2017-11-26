#include <iostream>
#include <queue>
#define MAX_N 51
using namespace std;
//동, 동남, 남, 남서, 서, 북서, 북, 북동
int goto_x[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int goto_y[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int map[MAX_N][MAX_N] = {0};
bool visited[MAX_N][MAX_N] = {false};

bool is_valid(int x, int y, int W, int H) {
    if((x < 0) || (x >= H) || (y < 0) || ((y >= W)))
        return false;
    if((map[x][y] == 0) || visited[x][y])
        return false;
    return true;
}

void init() {
    for(int i = 0; i < MAX_N; i++)
        for(int j = 0; j < MAX_N; j++) {
            map[i][j] = 0;
            visited[i][j] = false;
        }
}

int main() {
    int W, H;
    while(true) {
        init();
        cin >> W >> H;
        if((W == 0) && (H == 0))
            return 0;

        for(int i = 0; i < H; i++)
            for(int j = 0; j < W; j++) {
                int temp;
                cin >> temp;
                map[i][j] = temp;
            }

        queue<pair<int,int>> Q;
        int island_count = 0;
        for(int i = 0; i < H; i++)
            for(int j = 0; j < W; j++) {
                if((map[i][j] == 1) && !visited[i][j]) {
                    visited[i][j] = true;
                    island_count++;
                    Q.push(make_pair(i,j));
                    int current_x, current_y;
                    while(!Q.empty()) {
                        current_x = Q.front().first;
                        current_y = Q.front().second;
                        Q.pop();
                        int new_x, new_y;
                        for(int k = 0; k < 8; k++) {
                            new_x = current_x + goto_x[k];
                            new_y = current_y + goto_y[k];
                            if(is_valid(new_x, new_y, W, H)) {
                                visited[new_x][new_y] = true;
                                Q.push(make_pair(new_x, new_y));
                            }
                        }
                    }
                }
            }
        cout << island_count << endl;
    }
}
