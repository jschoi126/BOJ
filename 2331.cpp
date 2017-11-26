#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;

int pow(int x, int P) {
    int res = 1;
    for(int i = 0 ; i < P; i++){
        res *= x;
    }
    return res;
}

int next(int num, int P) {
    int sum = 0;
    while(num > 0) {
        sum += pow(num % 10, P);
        num /= 10;
    }
    return sum;
}

int find(int current) {

    int result = 1;
    for(vector<int>::iterator iter = arr.begin(); iter != arr.end() - 1; iter++) {
        if(*iter == current) {
            //cout << *iter << endl;
            return result - 1;
        }
        result++;
    }
    return -1;
}

int main() {
    int A, P;
    cin >> A >> P;

    int result;
    int current = A;
    arr.push_back(current);

    do {
        arr.push_back(current = next(current, P));
    } while((result = find(current)) < 0);

    cout << result << endl;

    return 0;
}
