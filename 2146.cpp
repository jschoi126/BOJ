#include <iostream>
#include <queue>
#define MAX_N 101
#define INT_MAX 99999
using namespace std;

int map[MAX_N][MAX_N]= {0};
bool visited[MAX_N][MAX_N] = {false};
bool same_land[MAX_N][MAX_N] = {false};

int goto_x[4] = {1, 0, -1, 0};
int goto_y[4] = {0, -1, 0, 1};

bool valid(int x, int y, int N) {
    if((x < 0) || (x >= N) || (y < 0) || (y >= N))
        return false;
    if(visited[x][y])
        return false;
    return true;
}

//다음 갈 땅이 유효한가
bool is_valid(int x, int y, int N) {
    if((x < 0) || (x >= N) || (y < 0) || (y >= N))
        return false;
    //같은 섬인데 방문한 적이 있으면 못감
    if(same_land[x][y])
        return false;
    //바다인데 간적이 있으면 못감
    if((map[x][y] == 0 && visited[x][y]))
        return false;
    return true;
}

void init(int N) {
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) {
            if(map[i][j] == 0)
                visited[i][j] = false;
            same_land[i][j] = false;
        }
}

int main() {
    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++)
            cin >> map[i][j];
    }

    int min_length = INT_MAX;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if((map[i][j] == 1) && !visited[i][j]) {
                //cout << i << ", " << j << endl;
                init(N);
                visited[i][j] = true;
                same_land[i][j] = true;
                queue<pair<int, int>> Q;
                //경계에 있는 버텍스를 여기 큐에 넣는다.
                queue<pair<pair<int, int>, int>> second_Q;
                Q.push(make_pair(i,j));
                int current_x, current_y;
                int new_x, new_y;
                while(!Q.empty()) {
                    current_x = Q.front().first;
                    current_y = Q.front().second;
                    //cout << current_x << ", " << current_y << endl;
                    Q.pop();
                    //일단 내 땅을 먼저 색칠해놓는다
                    for(int k = 0; k < 4; k++) {
                        new_x = current_x + goto_x[k];
                        new_y = current_y + goto_y[k];
                        //isvalid 조금 달라야함
                        if(valid(new_x, new_y, N)) {
                            if(map[new_x][new_y] == 1) {
                                visited[new_x][new_y] = true;
                                same_land[new_x][new_y] = true;
                                Q.push(make_pair(new_x, new_y));
                            } else {
                                if(second_Q.empty()) {
                                    //cout << "sQ push : " << current_x << ", " << current_y << endl;
                                    second_Q.push(make_pair(make_pair(current_x, current_y), 0));
                                } else if (!second_Q.empty() && !((second_Q.back().first.first == current_x) &&
                                        (second_Q.back().first.second) == current_y)) {
                                    //cout << "sQ push : " << current_x << ", " << current_y << endl;
                                    second_Q.push(make_pair(make_pair(current_x, current_y), 0));
                                }
                            }
                        }
                    }
                }

                int current_length;
                //내 땅이 색칠되어 있는 상태에서 외곽에 있는 버텍스 부터 시작
                while(!second_Q.empty()) {
                    current_x = second_Q.front().first.first;
                    current_y = second_Q.front().first.second;
                    current_length = second_Q.front().second;
                    second_Q.pop();
                    for(int k = 0; k < 4; k++) {
                        new_x = current_x + goto_x[k];
                        new_y = current_y + goto_y[k];
                        if(is_valid(new_x, new_y, N)) {
                            if((map[current_x][current_y] == 1) && (map[new_x][new_y] == 0)) {
                                //현재 땅이 육지이고 다음 땅이 바다라면
                                visited[new_x][new_y] = true;
                                second_Q.push(make_pair(make_pair(new_x, new_y), current_length + 1));

                            } else if((map[current_x][current_y] == 1) && (map[new_x][new_y] == 1)) {
                                //현재 땅이 육지이고 다음 땅도 육지라면
                            } else if((map[current_x][current_y] == 0) && (map[new_x][new_y] == 0)) {
                                //현재 땅이 바다이고 다음 땅도 바다라면
                                visited[new_x][new_y] = true;
                                second_Q.push(make_pair(make_pair(new_x, new_y), current_length + 1));
                            } else {
                                //현재 땅이 바다이고 다음 땅이 육지라면
                                if(current_length < min_length) {
                                    min_length = current_length;
                                    //cout << "min = " << min_length << endl;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << min_length << endl;

    return 0;
}
