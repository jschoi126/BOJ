import sys
import math
t = input()
for i in range(0,t):
    n = input()
    result = 0
    for j in range(1, n + 1):
        result += math.log10(j)
        
    print int(result) + 1
