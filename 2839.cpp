//
// Created by Choi on 2017. 9. 27..
//
#include <iostream>
using namespace std;

int main() {
    int N;
    int result = 0;
    cin >> N;

    //3x + 5y = N;
    //x + y 의 최대값은?

    int min_3, min_5;
    // 0 <= max_3 < 1999
    // 0 <= max_5 < 1000

    int min = 99999;
    for(int a = 0; a <= 1666; a++) {
        for(int b = 0; b <= 1000; b++) {
            if(3 * a + 5 * b == N) {
                if(a+b < min) {
                    min = a+b;
                    min_3 = a;
                    min_5 = b;
                }
            }
        }
    }

    //cout << min_3 << endl;
    //cout << min_5 << endl;
    if(min != 99999)
        cout << min << endl;
    else
        cout << -1 << endl;
}