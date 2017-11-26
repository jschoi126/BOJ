//
// Created by Choi on 2017. 9. 23..
//
#include <iostream>
using namespace std;

int main() {

    int alphabet['z' + 1] = {0,};
    string str;
    cin >> str;

    int len = str.length();
    for(int i = 0; i < len; i++)
        alphabet[str[i]]++;

    for(char c = 'a'; c <= 'z'; c++) {
        cout << alphabet[c] << " ";
    }
    cout << endl;
}