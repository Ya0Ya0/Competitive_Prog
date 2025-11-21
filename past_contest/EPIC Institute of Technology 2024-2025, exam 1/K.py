import math
import sys
from decimal import Decimal
mod = 1000000007
def gcd(a, b):
 
    if (a == 0):
        return b
    return gcd(b % a, a)
def modexp(x, n):
 
    if (n == 0) :
        return 1
     
    elif (n % 2 == 0) :
        return modexp((x * x) % mod, n // 2)
     
    else :
        return (x * modexp((x * x) % mod, 
                           (n - 1) / 2) % mod)
n = int(input())
sum = 0
# if(n > 1000):
#     print(f"{0:.15f}")
#     sys.exit(0)
    
for i in range(n+1):
    up = 0
    if i == 0:
        up = 1
    else:
        up = (-1)**i
    bot = i**3 + 9 * i**2 + 26 * i + 24
    cur = Decimal(up/ bot )* Decimal(math.comb(n, i))
    sum+=cur
    c = gcd(sum,k)
    
    sum = sum // c
    k = k // c
    
        
    d = modexp(k, mod - 2)
    
        
    ans += ((sum % mod) * (d % mod)) % mod
print(ans)

     
    

    
    

