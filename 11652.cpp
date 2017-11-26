//
// Created by Choi on 2017. 9. 27..
//
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    map<long long,int> m;

    long long temp;
    for(int i = 0; i < N; i++) {
        scanf("%lld", &temp);
        map<long long, int>::iterator iter = m.find(temp);
        if(iter == m.end()) {
            m.insert(make_pair(temp, 1));
        } else {
            iter->second += 1;
        }
    }

    int max_count = -1;
    long long result = 0;

    for(map<long long,int>::iterator iter = m.begin(); iter != m.end(); iter++) {
        //cout << "current : " << iter->first << "value : " << iter->second << endl;
        if(iter->second >= max_count) {
            if(iter->second == max_count) {
                if(result > iter->first) {
                    result = iter->first;
                }
            } else {
                max_count = iter->second;
                result = iter->first;
            }
        }
    }

    printf("%lld\n", result);

    return 0;
}