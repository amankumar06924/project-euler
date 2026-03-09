# Total moves jo aapko lene padenge (0,0) to (m,n) = down + right = m+n
# In total moves mein se aapko choose karna hai ki kitne baar Right mudna hai.
# Isliye choose m over m+n
#  ans = (m+n)Cn
# why i use pyhton for this problem because of preBuilt function of nCr

import math
for i in range(int(input())):
    n, m=map(int, input().split())
    print(math.comb(n+m, m) %(10**9+7))