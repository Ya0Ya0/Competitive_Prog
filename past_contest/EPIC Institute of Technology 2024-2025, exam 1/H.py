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
d = [1,1,1,1,1,1]
for i in range(n-1):
    for j in range(4,-1,-1):
        d[j] = d[j]+d[j+1]
sum = 0
for e in d:
    sum+=e
k = 6**n
c = gcd(sum,k)
 
sum = sum // c
k = k // c
 
    
d = modexp(k, mod - 2)
 
    
ans = ((sum % mod) * (d % mod)) % mod
print(ans)