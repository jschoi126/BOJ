//
// Created by Choi on 2017. 10. 18..
//
#include <iostream>
#include <vector>
#include <queue>
#define MIN 9999999
using namespace std;

int capacity['z' + 1]['z' + 1];
int flow['z' + 1]['z' + 1];
queue<vector<char>> path;

void print_path(vector<char> &v_node) {
    for(int i = 0 ; i < v_node.size() - 1; i++) {
        cout << v_node[i] << "->";
    }
    cout << v_node[v_node.size() -1]  << endl;
}

void find_path(char x, vector<char> &v_node) {
//    cout << "current = " << x << endl;
    vector<char> new_v_node(v_node.size());
    for(int i = 0 ; i < v_node.size(); i++) {
        new_v_node[i] = v_node[i];
    }

    new_v_node.push_back(x);

    if (x == 'Z') {
        path.push(new_v_node);
//        cout << "made path" << endl;
        return;
    }
    for(char c = 'A'; c <= 'z'; c++) {
        if(capacity[x][c] != 0) {
//            cout << "next : " << c << endl;
            find_path(c, new_v_node);
        }
    }
}

void calc_flow(vector<char> &v_path) {
    int min = MIN;
    for(int i = 1 ; i < v_path.size(); i++) {
        if(capacity[v_path[i - 1]][v_path[i]] < min)
            min = capacity[v_path[i - 1]][v_path[i]];
    }
    for(int i = 1 ; i < v_path.size(); i++) {
        capacity[v_path[i - 1]][v_path[i]] -= min;
        flow[v_path[i]][v_path[i - 1]] += min;
    }
}


void ford_fulkerson() {
    //A에서 Z까지의 모든 경로를 탐색
    vector<char> v;
    find_path('A', v);
//    while(!path.empty()) {
//        print_path(path.front());
//        path.pop();
//    }

    while(!path.empty()) {
        //print_path(path.front());
        //각 argument path에 대한 capacity, flow 계산
        calc_flow(path.front());
        path.pop();
        //새로운 경로가 생성되었는지 탐색
//        find_path('A', v);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    //배열 초기화, capacity[i] == 0 연결이 안되어잇다
    for(char c1 = 'A'; c1 <= 'z'; c1++) {
        for(char c2 = 'A'; c2 <= 'z'; c2++) {
            capacity[c1][c2] = 0;
            flow[c1][c2] = 0;
        }
    }

    char ch, from, to;
    int f;
    for(int i = 1; i <= N; i++) {
        getchar();
        scanf("%c", &from);
        getchar();
        scanf("%c", &to);
        getchar();
        scanf("%d", &f);
        //cout << from << ", " << to << ", " << f << endl;
        if (capacity[from][to] != 0)
            capacity[from][to] += f;
        else
            capacity[from][to] = f;
    }

    ford_fulkerson();

    int result = 0;
    for(char c = 'A'; c <= 'z'; c++) {
        if(flow['Z'][c] != 0)
            result += flow['Z'][c];
    }

    printf("%d\n", result);

    return 0;
}