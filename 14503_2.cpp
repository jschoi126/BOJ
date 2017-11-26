#include <iostream>
#include <cstring>
using namespace std;

int N, M;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int arr[55][55];

int ans = 0;

int rotate_d(int d) {
    return (d + 3) % 4;
}

void solve(int x, int y, int d) {
    int rotate = 0;
    while(true) {
        rotate = 0;
        //cout << "current : " << x << ", " << y << endl;
        if (arr[x][y] == 0) {
            arr[x][y] = 2;
            ans++;
        }

        loop:
            int new_x = x + dx[rotate_d(d)];
            int new_y = y + dy[rotate_d(d)];
            d = rotate_d(d);
            rotate++;
            if (arr[new_x][new_y] == 0) {
                // case 2-1
                x = new_x;
                y = new_y;
            } else {
                if (rotate == 4) {
                    new_x = x - dx[d];
                    new_y = y - dy[d];
                    if(arr[new_x][new_y] == 2) {
                        x = new_x;
                        y = new_y;
                        //cout << "dfd" << endl;
                        continue;
                    } else {
                        goto end;
                    }
                } else {
                    goto loop;
                }
            }
    }
    end :
        cout << ans << endl;
}

int main() {
    cin >> N >> M;
    int cur_x, cur_y, cur_d;
    cin >> cur_x >> cur_y >> cur_d;
    cur_x += 1;
    cur_y += 1;
    memset(arr, 1, sizeof(arr));

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }

    //d 0 - north, 1 - east, 2 - south, 3 - west
    solve(cur_x, cur_y, cur_d);
}
