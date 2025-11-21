from math import comb
lst = [[0 for i in range(10)] for i in range (25)]
lst[0] = [1 for i in range(10)]
print( comb(10,3))
print( comb(13,3))
print(35*286)
for i in range(0,25):
    lst[i][0] = 1
for i in range(1,25):
    for j in range(1,10):
        lst[i][j] = lst[i-1][j] + lst[i][j-1]
print(lst[3][6])