//
// Created by Choi on 2017. 10. 2..
//
#include <iostream>
using namespace std;

int N;
int max_block = -1;

void print_arr(int **arr) {
    for(int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

void set_max(int **arr) {
    for(int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if(arr[i][j] > max_block) {
                max_block = arr[i][j];
            }
        }
    }
}

void move_pos(int **arr, bool **is_merged, int x, int y, int direction) {
    switch(direction) {
        case 0:
            if(y + 1 > N)
                return;
            if(arr[x][y + 1] == 0) {
                arr[x][y + 1] = arr[x][y];
                arr[x][y] = 0;
                move_pos(arr, is_merged, x, y + 1, direction);
            } else if(arr[x][y + 1] == arr[x][y] && !is_merged[x][y+1]) {
                arr[x][y + 1] = 2 * arr[x][y];
                is_merged[x][y+1] = true;
                arr[x][y] = 0;
            } else if(arr[x][y +1] != arr[x][y])
                return;
            break;
        case 1:
            if(x + 1 > N)
                return;
            if(arr[x + 1][y] == 0) {
                arr[x + 1][y] = arr[x][y];
                arr[x][y] = 0;
                move_pos(arr, is_merged, x + 1, y, direction);
            } else if(arr[x + 1][y] == arr[x][y]  && !is_merged[x + 1][y]) {
                arr[x + 1][y] = 2 * arr[x][y];
                is_merged[x + 1][y] = true;
                arr[x][y] = 0;
            }
            break;
        case 2:
            if(y - 1 <= 0)
                return;
            if(arr[x][y - 1] == 0) {
                arr[x][y - 1] = arr[x][y];
                arr[x][y] = 0;
                move_pos(arr, is_merged, x, y - 1, direction);
            } else if(arr[x][y - 1] == arr[x][y] && !is_merged[x][y-1]) {
                arr[x][y - 1] = 2 * arr[x][y];
                is_merged[x][y-1] = true;
                arr[x][y] = 0;
            }
            break;
        case 3:
            if(x - 1 <= 0)
                return;
            if(arr[x - 1][y] == 0) {
                arr[x - 1][y] = arr[x][y];
                arr[x][y] = 0;
                move_pos(arr, is_merged, x - 1, y, direction);
            } else if(arr[x - 1][y] == arr[x][y] && !is_merged[x - 1][y]) {
                arr[x - 1][y] = 2 * arr[x][y];
                is_merged[x-1][y] = true;
                arr[x][y] = 0;
            }
            break;
    }
}

void move_arr(int **arr, bool **is_merged, int direction) {
    //2048배열을 상하좌우로 움직이기
    //direction : right, down, left, top
    switch(direction) {
        //right
        case 0:
            for(int i = 1; i <= N; i++) {
                for(int j = N; j >= 1 ; j--) {
                    if(arr[i][j] != 0)
                        move_pos(arr, is_merged, i, j, direction);
                }
            }
            break;
        //down
        case 1:
            for(int j = 1; j <= N; j++) {
                for(int i = N; i >= 1 ; i--) {
                    if(arr[i][j] != 0)
                        move_pos(arr, is_merged, i, j, direction);
                }
            }
            break;
        //left
        case 2:
            for(int i = 1; i <= N; i++) {
                for(int j = 1; j <= N; j++) {
                    if(arr[i][j] != 0)
                        move_pos(arr, is_merged, i, j, direction);
                }
            }
            break;
        //top
        case 3:
            for(int j = 1; j <= N; j++) {
                for(int i = 1; i <= N ; i++) {
                    if(arr[i][j] != 0)
                        move_pos(arr, is_merged, i, j, direction);
                }
            }
            break;
    }
}

/*
 * 1
8 0 0 0
8 0 0 0
16 0 0 0
32 64 0 0
2
0 0 0 0
 16 0 0 0
 16 0 0 0
 32 64 0 0
 3
0 0 0 0
 0 0 0 0
 32 0 0 0
 32 64 0 0
 4

 0 0 0 0
 0 0 0 0
 0 0 0 0
 64 64 0 0
 * */

void solve(int **arr, int depth) {
    if(depth == 6)
        return;
//    cout << "===" << depth << "===" << endl;
    int **cur_arr = new int *[N + 1];
    for(int i = 1; i <= N; i++)
        cur_arr[i] = new int [N + 1];

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            cur_arr[i][j] = arr[i][j];
    //현재 상태에서 최대값을 구한다
//    print_arr(cur_arr);
//    set_max(cur_arr);

    for(int dir = 0; dir <= 3; dir++) {
        //cur_arr 값이 변함.
        int **new_arr = new int *[N + 1];
        bool **is_merged = new bool *[N + 1];
        for(int i = 1; i <= N; i++) {
            new_arr[i] = new int[N + 1];
            is_merged[i] = new bool[N + 1];
        }
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++) {
                new_arr[i][j] = cur_arr[i][j];
                is_merged[i][j] = false;
            }
//        cout << "depth : " << depth << ", move-arr, d = " << dir << endl;
        move_arr(new_arr, is_merged,  dir);
//        print_arr(new_arr);
        set_max(new_arr);
        solve(new_arr, depth + 1);

        //delete heap for new_arr and is_merged
        for(int i = 1; i <= N; i++) {
            delete new_arr[i];
            delete is_merged[i];
        }
        delete [] new_arr;
        delete [] is_merged;
    }

    for(int i = 1; i <= N; i++) {
        delete cur_arr[i];
    }
    delete [] cur_arr;

}

int main() {

    scanf("%d", &N);

    int **arr = new int* [N + 1];
    for(int i = 1; i <= N; i++) {
        arr[i] = new int [N + 1];
    }

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            scanf("%d", &arr[i][j]);

    solve(arr, 0);

    cout << max_block << endl;

    for(int i = 1; i <= N; i++)
        delete arr[i];
    delete [] arr;

    return 0;
}
