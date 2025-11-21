def mod_inverse(a, p=1000000007):
    def extended_euclidean(a, b):
        if a == 0:
            return b, 0, 1
        else:
            gcd, x, y = extended_euclidean(b % a, a)
            return gcd, y - (b // a) * x, x
    
    gcd, x, _ = extended_euclidean(a, p)
    if gcd != 1:
        raise Exception('Modular inverse does not exist')
    else:
        return x % p

def mod_binomial(n, k, p=1000000007):
    if k > n or k < 0:
        return 0
    # Calculate binomial coefficient modulo p
    numerator = 1
    for i in range(1, k+1):
        numerator = (numerator * (n - i + 1)) % p
    denominator = 1
    for i in range(1, k+1):
        denominator = (denominator * i) % p
    
    # Modular inverse for division
    inv_denominator = mod_inverse(denominator, p)
    return (numerator * inv_denominator) % p

def sum_specific_binomial_coefficients(a, k, p=1000000007):
    n = len(a)
    result = 0
    
    # Generate all combinations of length k from the list a
    from itertools import combinations
    for comb in combinations(a, k):
        ones = comb.count(1)
        zeros = comb.count(0)
        if ones > zeros:
            result = (result + mod_binomial(k, ones, p)) % p
    
    return result

# User Input
n = int(input("Enter n: "))
k = int(input("Enter k: "))
a = list(map(int, input("Enter the list of binary digits: ").split()))

if len(a) != n:
    raise ValueError("The length of the list does not match n")

# Calculating and printing the result
result = sum_specific_binomial_coefficients(a, k)
print(f"The result modulo 1000000007 is: {result}")