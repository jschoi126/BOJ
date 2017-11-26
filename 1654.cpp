#include <iostream>
using namespace std;

int K, N;
int arr[10001];

int cut(long long len) {
    int cut_count = 0;
    for(int i = 0; i < K;i ++) {
        cut_count += arr[i] / len;
    }
    return cut_count;
}

int main() {
    scanf("%d %d", &K, &N);

    long long max = 0;

    for(int i = 0; i < K; i++) {
        scanf("%d", &arr[i]);
        if(arr[i] > max)
            max = arr[i];
    }

    long long start = 0;
    long long end = max;
    long long mid;
    long long max_len = 0;

    while(start <= end) {
        mid = (start + end) / 2;
        cout << mid << endl;
        if(cut(max_len) >= N) {
            start = mid + 1;
            if(mid > max_len)
                max_len = mid;
        } else {
            end = mid - 1;
        }
    }

    cout << max_len << endl;

    return 0;
}