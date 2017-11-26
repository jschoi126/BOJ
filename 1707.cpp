#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

    int K, V, E;

    cin >> K;
    while(K--) {
        cin >> V >> E;
        int tmp1, tmp2;
        vector<int> edge[20001];
        for(int i = 0; i < E; i++) {
            cin >> tmp1 >> tmp2;
            edge[tmp1 - 1].push_back(tmp2 - 1);
            edge[tmp2 - 1].push_back(tmp1 - 1);
        }

        //BFS를 통해 구현
        bool bipartitle = true;
        int color[20001] = {0};
        bool visited[20001] = {false};
        queue<pair<int, int>> q;
        for(int i = 0; i < V; i++) {
            if(!bipartitle)
                 break;
            if(!visited[i]) {
                visited[i] = true;
                color[i] = 1;
                q.push(make_pair(i, color[i]));
                while(!q.empty()) {
                    //cout << "current : " << q.front().first << endl;
                    //cout << "color : " << q.front().second << endl;

                    int current_vertex = q.front().first;
                    int current_color = q.front().second;
                    q.pop();
                    for(vector<int>::iterator iter = edge[current_vertex].begin(); iter != edge[current_vertex].end(); iter++) {
                        //cout << "link : " << *iter << "color : " << color[*iter] << endl;
                        // 연결된 정점들이 이미 서로 같은 색이면 이분그래프가 아니다
                        if(color[*iter] == current_color) {
                            //cout << "false!" << endl;
                            bipartitle = false;
                            break;
                        } else {
                            // 연결된 정점이 다른 색일 때...
                            //이미 방문한 정점이면 그냥 패스하고 방문 안한 정점이면 색칠하고 큐에 넣는다
                            //
                                if(!visited[*iter]) {
                                    visited[*iter] = true;
                                if(current_color == 1)
                                    color[*iter] = 2;
                                else
                                    color[*iter] = 1;
                                q.push(make_pair(*iter, color[*iter]));
                            }
                        }
                    }
                }
            }
        }

        if(bipartitle)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
