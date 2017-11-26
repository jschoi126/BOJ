//
// Created by Choi on 2017. 9. 27..
//
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int alpha['z' + 1];

bool is_pilsu(string str) {
    int len = str.length();
    for(int i = 0; i < len; i++) {
        alpha[str[i]]--;
        if(alpha[str[i]] <= 0)
            return true;
    }
    return false;
}

int main() {
    int N;
    cin >> N;

    memset(alpha, 0, sizeof(alpha));
    vector<string> v, v_must;

    string temp;
    for(int i = 0 ; i < N; i++) {
        cin >> temp;
        for(int i = 0; i < temp.length(); i++)
            alpha[temp[i]]++;
        v.push_back(temp);
    }


    int pilsu_count = 0;
    for(int i = 0; i < v.size(); i++) {
        if(is_pilsu(v[i])) {
            pilsu_count ++;
        }
    }

    int result = 1;
    for(int i = 0; i < v.size() - pilsu_count; i++) {
        result *= 2;
    }
    cout << result << endl;
    return 0;
}