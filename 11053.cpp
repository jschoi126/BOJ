#include <iostream>
using namespace std;

int main() {

    int N;
	    int arr[1001], dp[1001];
		    cin >> N;

			    for(int i = 1; i <= N; i++) {
				        dp[i] = 1;
						        cin >> arr[i];
								    }

									    //O(N^2)
										   int max = 1;
										        for(int i = 1; i <= N; i++) {
										                for(int j = i + 1; j <= N; j++) {
										                            if((arr[i] < arr[j]) && (dp[i] + 1 > dp[j])) {
										                                            dp[j] = dp[i] + 1;
										                                                            if(max < dp[j])
										                                                                                max = dp[j];
										                                                                                            }
										
										                                                                                                    }
										                                                                                                        }
									                                                                                                            cout << max << endl;
										                                                                                                                return 0;
										                                                                                                                }
