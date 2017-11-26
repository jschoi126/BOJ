//
// Created by Choi on 2017. 9. 26..
//
#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

int N, M;
//동 남 서 북
int arr[10][10], arr2[10][10];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

vector<pair<int, int>> virus_start, v_blank, v_wall;

bool can_go(int x, int y) {
//    cout << "n, m" << N << M << endl;
//    cout << "can_go " << x << ", " << y << endl;
//    cout << "arr = " << arr2[x][y] << endl;
    if(x <= 0 || x > N || y <= 0 || y > M) {
        return false;
    }
    if(arr2[x][y] == 1 || arr2[x][y] == 2)
        return false;
    return true;
}

int bfs() {

    memset(arr2, 0, sizeof(arr2));

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            arr2[i][j] = arr[i][j];
        }
    }

    //cout << "---- bfs ----" << endl;

    for(int i = 0; i < 3; i++) {
        //cout << "wall : " << v_wall[i].first << ",  " << v_wall[i].second << endl;
        arr2[v_wall[i].first][v_wall[i].second] = 1;
    }

    stack<pair<int, int>> s;
    for(vector<pair<int,int>>::iterator iter = virus_start.begin(); iter != virus_start.end(); iter++) {
        s.push(*iter);
    }
    while(!s.empty()) {
        pair<int, int> current = s.top();
        //cout << "current : " << current.first << ", " << current.second << endl;
        s.pop();
        arr2[current.first][current.second] = 2;
        for(int i = 0; i < 4; i ++) {
            if(can_go(current.first + dx[i], current.second + dy[i])) {
                //arr2[current.first + dx[i]][current.second + dy[i]] = 2;
                s.push(make_pair(current.first + dx[i], current.second + dy[i]));
            }
        }
    }

    int safe_count = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cout << arr2[i][j] << " ";
            if(arr2[i][j] == 0)
                safe_count++;
        }
        cout << endl;
    }

    cout << "count : " <<  safe_count << endl;

    return safe_count;
}

int main() {
    memset(arr, 0 , sizeof(arr));
    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 2)
                virus_start.push_back(make_pair(i, j));
            else if(arr[i][j] == 0)
                v_blank.push_back(make_pair(i, j));
        }
    }

    int max = -1;

    //벽 3개를 선택
    int len = v_blank.size();
    for(int i = 0; i < len; i++) {
        for(int j = i + 1; j < len; j++) {
            for(int k = j + 1; k < len; k++){
                v_wall.clear();
                v_wall.push_back(v_blank[i]);
                v_wall.push_back(v_blank[j]);
                v_wall.push_back(v_blank[k]);
                //bfs를 통한 계산
                int result = bfs();
                if(max < result) {
                    max = result;
                }
            }
        }
    }

    cout << max << endl;

    return 0;
}