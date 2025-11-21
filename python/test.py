def minOperations(grid):
    m = len(grid)
    n = len(grid[0])
    dp = [[0 for _ in range(n)] for _ in range(m)]
  
    for i in range(m):
        dp[i][n-1] = m-i-1

    for i in range(m-2, -1, -1):
        for j in range(n-1, -1, -1):
            dp[i][j] = min(dp[i+1][j] + 1, min(grid[i][j] - grid[i+1] [j], grid[i][j] - grid[i][j+1]) + 2)
 
    return dp[0][0]
        
        
 #Example
grid = [[1, 2, 3, 4],
       [5, 6, 7, 8],
       [9, 10, 11, 12],
       [13, 14, 15, 16]]
       
print(minOperations(grid))