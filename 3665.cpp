#include <iostream>
#include <queue>
using namespace std;
int TC, N;

int swap(int *x, int *y) {
    int temp = *x;
	    *x = *y;
		    *y = temp;
			}

			int main() {
			    cin >> TC;
				    while(TC--) {
					        cin >> N;

							        int t[501], tmp;
									        for(int i = 1; i <= N; i++) {
											            cin >> tmp;
														            t[tmp] = i;
																	        }

																			        int m, tmp1, tmp2;
																					        bool valid = true;
																							        cin >> m;
																									        for(int i = 1; i <= m; i++) {
																											            cin >> tmp1 >> tmp2;
																														            if(t[tmp1] > t[tmp2]) {
																																	                valid = false;
																																					                break;
																																									            }
																																												        }

																																														        if(valid) {
																																																            for (int i = 1; i <= N; i++) {
																																																			                cout << t[i] << " ";
																																																							            }
																																																										        } else if() {
																																																												            cout << "?";
																																																															        } else {
																																																																	            cout << "IMPOSSIBLE";
																																																																				        }
																																																																						        cout << endl;

																																																																								    }
																																																																									    return 0;
																																																																										}
