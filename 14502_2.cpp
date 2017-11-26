//
// Created by Choi on 2017. 9. 27..
//
#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

int N, M;
int arr[10][10];
int arr2[10][10];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
vector<pair<int,int>> v_start, v_list, v_wall;

bool can_go(int x, int y) {
    if(x <= 0 || x > N || y <= 0 || y > M)
        return false;
    if(arr[x][y] == 1 || arr[x][y] == 2)
        return false;
    return true;
}

int bfs() {
    cout << "dfsdf";
    memset(arr2, 0, sizeof(arr2));

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            arr2[i][j] = arr[i][j];

    for(int i = 0; i < 3; i++) {
        arr2[v_wall[i].first][v_wall[i].second] = 1;
    }

    stack<pair<int,int>> s;
    for(int i = 0; i < v_start.size(); i++) {
        s.push(make_pair(v_start[i].first, v_start[i].second));
    }

    while(!s.empty()) {
        //cout << "current : " << current.first << ", " << current.second << endl;
        pair<int, int> current = s.top();
        s.pop();
        if(arr2[current.first][current.second] == 0)
            arr2[current.first][current.second] = 2;
        for(int i = 0; i < 4; i++) {
            if(can_go(current.first + dx[i], current.second + dy[i])) {
                s.push(make_pair(current.first + dx[i], current.second + dy[i]));
            }
        }
    }

    int safe_count = 0;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++) {
            if(arr2[i][j] == 0)
                safe_count++;
        }

    return safe_count;
}

int main() {
    cin >> N >> M;
    memset(arr, 0, sizeof(arr));

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0)
                v_list.push_back(make_pair(i,j));
            else if(arr[i][j] == 2)
                v_start.push_back(make_pair(i,j));
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int max = -1;

    int len = v_list.size();
    for(int i = 0; i < len - 1; i++) {
        for(int j = i + 1; j < len - 1; j++) {
            for(int k = j + 1; k < len - 1; k++) {
                cout << "d";
                v_wall.clear();
                v_wall.push_back(make_pair(v_list[i].first, v_list[i].second));
                v_wall.push_back(make_pair(v_list[j].first, v_list[j].second));
                v_wall.push_back(make_pair(v_list[k].first, v_list[k].second));
                int result = bfs();
                if(max < result)
                    max = result;
            }
        }
    }
    cout << max << endl;
}
