#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;

        int arr[1001];
        bool visited[1001] = {false};
        vector<pair<int,int>> adj;
        queue<int> Q;

        for(int i = 1; i <= N; i++) {
            cin >> arr[i];
            adj.push_back(make_pair(i,arr[i]));
        }

        int cycle_num = 0, current;
        for(int i = 1; i <= N; i++) {
            if(!visited[i]) {
                visited[i] = true;
                cycle_num++;
                Q.push(i);
                while(!Q.empty()) {
                    current = Q.front();
                    Q.pop();
                    if(!visited[arr[current]]) {
                        visited[arr[current]] = true;
                        Q.push(arr[current]);
                    }
                }
            }
        }
        cout << cycle_num << endl;
    }
}
