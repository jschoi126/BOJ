#include <iostream>
#include <queue>
#define MAX 99999
using namespace std;

int T;

int main() {
	cin >> T;
	while(T--) {
		int cost[101][101], time[101][101], min_dist[101];
		for(int i = 0; i < 101; i++) {
			for(int j = 0; j < 101; j++)
				time[i][j] = MAX;
			min_dist[i] = MAX;	
		}

		int N, M, K;
		cin >> N >> M >> K;
		
		int u, v, c, d;
		for(int i = 0; i < K; i++) {
			cin >> u >> v >> cost[u][v] >> time[u][v];
		}

		priority_queue<pair<int,int> > pq;
		min_dist[1] = 0;
		pq.push(make_pair(0, 1));
		pair<int, int> current;
		bool valid = true;
		while(!pq.empty()) {
			current = pq.top();
			pq.pop();
			for(int i = 1; i < 101; i++) {
					if(cost[current.second][i] != 0) {
						if(min_dist[i] > (min_dist[current.second] + cost[current.second][i])) {
							min_dist[i] = min_dist[current.second] + cost[current.second][i];
							pq.push(make_pair(cost[current.second][i], i));
						}
					}
			}
		}

		if(valid)
			cout << min_dist[N] << endl;
		else
			cout << "Poor KCM" << endl;
	}
	return 0;
}
