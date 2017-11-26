#include <iostream>
#include <cstring>
using namespace std;

int arr[55][55];
//안갓으면 0, 벽은 1, 갓으면 2

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int M, N;

int rotate_left(int d) {
    return (4 + d - 1) % 4;
}

pair<int, int> get_left(int x, int y, int d) {
    return make_pair(x + dx[rotate_left(d)], y + dy[rotate_left(d)]);
};

int main() {

    memset(arr, 0, sizeof(arr));

    cin >> N >> M;
    //0 - north, 1 - east, 2 - south, 3 - west
    int cur_x, cur_y, cur_d;
    cin >> cur_x >> cur_y >> cur_d;

    cur_x += 1;
    cur_y += 1;

    for(int i = 1; i <= N; i++) {
        for(int j = 1 ; j <= M; j++) {
            cin >> arr[i][j];
        }
    }

    int clean_count = 0;
    int rotate_count = 0;

    while(true) {
        //cout << "current : " << cur_x << ", " << cur_y << endl;
        if(arr[cur_x][cur_y] == 0) {
            arr[cur_x][cur_y] = 2;
            clean_count++;
            rotate_count = 0;
        }

        two:
            pair<int, int> left = get_left(cur_x, cur_y, cur_d);
            //cout << "left : " << left.first << ", " << left.second << " : " << is_cleaned[left.first][left.second] << ", " << is_wall(left.first, left.second) << endl;
            if(arr[left.first][left.second] == 0) {
                //cout << "rotate and go" << endl;
                cur_d = rotate_left(cur_d);
                cur_x = left.first;
                cur_y = left.second;
            } else {
                cur_d = rotate_left(cur_d);
                rotate_count++;

                //cout << "rotate_count = " << rotate_count << endl;
                if(rotate_count == 4) {
                    int next_x = cur_x - dx[cur_d];
                    int next_y = cur_y - dy[cur_d];

                    if(arr[next_x][next_y] == 2){
                        //cout << "next_x" << next_x << ", next_y :" << next_y << "wall :  "<< is_wall(next_x, next_y) <<endl;
                        cur_x = next_x;
                        cur_y = next_y;
                        rotate_count = 0;
                    } else {
                        //cout << "out" << endl;
                        goto out;
                    }
                }
                goto two;
            }
    }
    out:
        cout << clean_count << endl;

    return 0;
}