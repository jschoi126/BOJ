//
// Created by Choi on 2017. 9. 29..
//
#include <iostream>
#include <vector>
using namespace std;

int N, M;
int arr[505][505];

//테트로미노 선언
vector<pair<int,int>> block1[2];
vector<pair<int,int>> block2[1];
vector<pair<int,int>> block3[8];
vector<pair<int,int>> block4[4];
vector<pair<int,int>> block5[4];

void init_tetro() {
    //작대기
    block1[0].push_back(make_pair(0,0));
    block1[0].push_back(make_pair(0,1));
    block1[0].push_back(make_pair(0,2));
    block1[0].push_back(make_pair(0,3));
    block1[1].push_back(make_pair(0,0));
    block1[1].push_back(make_pair(1,0));
    block1[1].push_back(make_pair(2,0));
    block1[1].push_back(make_pair(3,0));
    //네모
    block2[0].push_back(make_pair(0,0));
    block2[0].push_back(make_pair(0,1));
    block2[0].push_back(make_pair(1,0));
    block2[0].push_back(make_pair(1,1));
    //니은
    block3[0].push_back(make_pair(0,0));
    block3[0].push_back(make_pair(0,1));
    block3[0].push_back(make_pair(-1,0));
    block3[0].push_back(make_pair(-2,0));
    block3[1].push_back(make_pair(0,0));
    block3[1].push_back(make_pair(0,-1));
    block3[1].push_back(make_pair(-1,0));
    block3[1].push_back(make_pair(-2,0));
    block3[2].push_back(make_pair(0,0));
    block3[2].push_back(make_pair(1,0));
    block3[2].push_back(make_pair(0,1));
    block3[2].push_back(make_pair(0,2));
    block3[3].push_back(make_pair(0,0));
    block3[3].push_back(make_pair(1,0));
    block3[3].push_back(make_pair(0,-1));
    block3[3].push_back(make_pair(0,-2));
    block3[4].push_back(make_pair(0,0));
    block3[4].push_back(make_pair(-1,0));
    block3[4].push_back(make_pair(0,1));
    block3[4].push_back(make_pair(0,2));
    block3[5].push_back(make_pair(0,0));
    block3[5].push_back(make_pair(-1,0));
    block3[5].push_back(make_pair(0,-1));
    block3[5].push_back(make_pair(0,-2));
    block3[6].push_back(make_pair(0,0));
    block3[6].push_back(make_pair(0,1));
    block3[6].push_back(make_pair(1,0));
    block3[6].push_back(make_pair(2,0));
    block3[7].push_back(make_pair(0,0));
    block3[7].push_back(make_pair(0,-1));
    block3[7].push_back(make_pair(1,0));
    block3[7].push_back(make_pair(2,0));
    //리을
    block4[0].push_back(make_pair(0,0));
    block4[0].push_back(make_pair(-1,0));
    block4[0].push_back(make_pair(0,1));
    block4[0].push_back(make_pair(1,1));
    block4[1].push_back(make_pair(0,0));
    block4[1].push_back(make_pair(-1,0));
    block4[1].push_back(make_pair(0,-1));
    block4[1].push_back(make_pair(-1,1));
    block4[2].push_back(make_pair(0,0));
    block4[2].push_back(make_pair(0,1));
    block4[2].push_back(make_pair(1,0));
    block4[2].push_back(make_pair(1,-1));
    block4[3].push_back(make_pair(0,0));
    block4[3].push_back(make_pair(0,-1));
    block4[3].push_back(make_pair(1,0));
    block4[3].push_back(make_pair(1,1));
    //ㅗ
    block5[0].push_back(make_pair(0,0));
    block5[0].push_back(make_pair(0,-1));
    block5[0].push_back(make_pair(0,1));
    block5[0].push_back(make_pair(1,0));
    block5[1].push_back(make_pair(0,0));
    block5[1].push_back(make_pair(-1,0));
    block5[1].push_back(make_pair(0,-1));
    block5[1].push_back(make_pair(1,0));
    block5[2].push_back(make_pair(0,0));
    block5[2].push_back(make_pair(-1,0));
    block5[2].push_back(make_pair(0,1));
    block5[2].push_back(make_pair(1,0));
    block5[3].push_back(make_pair(0,0));
    block5[3].push_back(make_pair(-1,0));
    block5[3].push_back(make_pair(0,-1));
    block5[3].push_back(make_pair(1,0));
}

bool can_place(int x, int y) {
    if(x <= 0 || x > N || y <= 0 || y > M)
        return false;
    return true;
}

int calc_max_sum(int max, int x, int y) {

    int sum = 0;
    for(int i = 0; i < 2; i++) {
        sum = 0;
        for(int j = 0; j < 4; j++) {
            int current_x = x + block1[i][j].first;
            int current_y = y + block1[i][j].second;

            if(can_place(current_x, current_y)) {
                sum += arr[current_x][current_y];
                //cout << sum << endl;
            }
            else {
                //cout << "else" << endl;
                break;
            }
            if(j == 3 && max < sum) {
                max = sum;
                //cout << "new max1 = " << max << endl;
            }
        }
    }

    for(int i = 0; i < 1; i++) {
        sum = 0;
        for(int j = 0; j < 4; j++) {
            int current_x = x + block2[i][j].first;
            int current_y = y + block2[i][j].second;

            //cout << current_x <<", " << current_y << endl;

            if(can_place(current_x, current_y)) {
                sum += arr[current_x][current_y];
            }
            else
                break;
            if(j == 3 && max < sum) {
                max = sum;
                //cout << "new max2 = " << max << endl;
            }
        }
    }

    for(int i = 0; i < 8; i++) {
        sum = 0;
        for(int j = 0; j < 4; j++) {
            int current_x = x + block3[i][j].first;
            int current_y = y + block3[i][j].second;

            if(can_place(current_x, current_y)) {
                sum += arr[current_x][current_y];
            }
            else {
                //cout << "x = " << x << ", " << y << endl;
                //cout << "cannot place : " << current_x << ", " << current_y << endl;
                break;
            }
            if(j == 3 && max < sum) {
//                cout << i << endl;
                max = sum;
                //cout << "new max3 = " << max << endl;
            }
        }
    }

    for(int i = 0; i < 4; i++) {
        sum = 0;
        for(int j = 0; j < 4; j++) {
            int current_x = x + block4[i][j].first;
            int current_y = y + block4[i][j].second;

            if(can_place(current_x, current_y)) {
                sum += arr[current_x][current_y];
            }
            else
                break;
            if(j == 3 && max < sum) {
                //cout << i << ", " << j << endl;
                max = sum;
                //cout << "new max4 = " << max << endl;
            }
        }
    }

    for(int i = 0; i < 4; i++) {
        sum = 0;
        for(int j = 0; j < 4; j++) {
            int current_x = x + block5[i][j].first;
            int current_y = y + block5[i][j].second;

            if(can_place(current_x, current_y)) {
                sum += arr[current_x][current_y];
            }
            else
                break;
            if(j == 3 && max < sum) {
                max = sum;
//                cout << "new max5 = " << max << endl;
            }
        }
    }

    return max;
}


int main() {

    cin >> N >> M;

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            cin >> arr[i][j];

    init_tetro();

    int max = -99999;
    int temp;
    for(int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            temp = calc_max_sum(max, i, j);
            if(temp > max)  {
//                cout << "=====" << endl;
//                cout << i << "," << j << endl;
                max = temp;
            }
        }
    }
    cout << max << endl;

    return 0;
}