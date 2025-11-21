import heapq
def minFallingPathSum(grid):
    n = len(grid)
    dp = [[0] * n for _ in range(n)]

    # Base case
    for j in range(n):
        dp[0][j] = grid[0][j]

    # DP with priority queue
    for i in range(1, n):
        pq = [(dp[i - 1][j], j) for j in range(n)]  # Initialize priority queue
        heapq.heapify(pq)

        for j in range(n):
            cost, col = heapq.heappop(pq)
            while col == j:  # Ensure non-zero shift 
                cost, col = heapq.heappop(pq)
            dp[i][j] = grid[i][j] + cost
            heapq.heappush(pq, (dp[i-1][j], j)) 

    return min(dp[n - 1]) 


# Example usage ...
grid = [[1, 2, 3],
       [4,5,6],
       [7,8,9],
       ]
print ("Imput")
print(grid)  
print("Output")     
print(minFallingPathSum(grid))