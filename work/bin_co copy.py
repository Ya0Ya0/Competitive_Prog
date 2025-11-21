from itertools import combinations

MOD = 1000000007

def mod_inverse(a, m=MOD):
    def extended_gcd(aa, bb):
        if aa == 0:
            return bb, 0, 1
        else:
            gcd, x, y = extended_gcd(bb % aa, aa)
            return gcd, y - (bb // aa) * x, x
    
    gcd, x, _ = extended_gcd(a, m)
    if gcd != 1:
        raise Exception('Modular inverse does not exist')
    else:
        return x % m

def mod_binomial(n, k):
    # Since we're not using n and k for actual factorial calculations here,
    # this function will be simplified for direct use in our context.
    # We directly return 1 for combinations where we need to count them, assuming
    # n and k come from our context of selecting from 'a'.
    if 0 <= k <= n:
        return 1  # We're just counting valid combinations, not calculating actual binomial coefficients
    return 0

def sum_binomial_coefficients(a, k):
    result = 0
    n = len(a)
    
    # Generate all combinations of length k from indices of 'a'
    for comb in combinations(range(n), k):
        # Count ones in this combination
        ones = sum(a[i] for i in comb)
        zeros = k - ones
        
        # Only consider combinations where ones > zeros
        if ones > zeros:
            result += mod_binomial(k, ones)  # Simplified to just count
            
    return result % MOD

# User Input
n = int(input("Enter n: "))
k = int(input("Enter k: "))
a = list(map(int, input("Enter the list of n numbers (0s and 1s): ").split()))

if len(a) != n:
    raise ValueError("The length of the list does not match n")

# Calculation
result = sum_binomial_coefficients(a, k)

print(f"The result modulo {MOD} is: {result}")