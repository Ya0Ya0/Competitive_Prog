from math import sqrt
import heapq
import tkinter
def dijkstra(start, end,board, n=8):
    DIRECTIONS = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    DIRECTION_NAMES = ["r", "d", "l", "u"]
    # Create a grid where each cell is initialized with 'inf' (infinite distance)
    grid = [[float('inf')] * n for _ in range(n)]
    grid[start[0]][start[1]] = 0
    
    # Min-heap priority queue to explore the least costly nodes first
    pq = [(board[0][0], start, [])]  # (cost, (x, y), path)
    
    while pq:
        current_cost, (x, y), path = heapq.heappop(pq)
        
        # If we reached the target node, return the cost and the path
        # The cost is multiplied by two because of the return trip and substracted board[0][0] and board[n-1][n-1] because those are only visited once
        if (x, y) == end:
            return current_cost*2 - board[0][0] - board[n-1][n-1], path
        
        # Check every direction
        for i, (dx, dy) in enumerate(DIRECTIONS):
            nx, ny = x + dx, y + dy
            
            # Check bounds
            if 0 <= nx < n and 0 <= ny < n:
                new_cost = current_cost + board[nx][ny]
                
                
                if new_cost < grid[nx][ny]:
                    grid[nx][ny] = new_cost
                    heapq.heappush(pq, (new_cost, (nx, ny), path + [DIRECTION_NAMES[i]]))
    
    return float('inf'), []  # If no path is found (shouldn't happen on a grid like this)

def update (board,path):
    x,y = (0,0)
    
    # Build a map to update the path easily 
    DIRECTIONS_MAP = {"r" : (0, 1),
                      "d": (1, 0),
                      "l":(0, -1),
                      "u" : (-1, 0)
    }       
    
    # Update the first cell
    board[x][y]+=1
    for move in path:
        nx,ny = DIRECTIONS_MAP[move]
        x += nx
        y += ny
        board[x][y]+=1

def solve_game():
    with open("Game_Seed_Qual_Round_29.txt", 'r') as file:
        
        # Read the whole file content and get the sizes
        content = file.read()  
        chara = content.split(', ')    
        z = int(sqrt(len(chara)))
        board = []
        
        # Fill the board
        for a in range(z) :
            board.append([])        
            for b in range(z):
                board[a].append(int(chara[a*z+b]))
                
        result = ""
        min_ans = 0
        # Repeat 5 times because we are the first player in the game (latest players have the advantage )
        for i in range(5):
            
            start = (0,0)
            end = (z-1,z-1)
            
            total,path = dijkstra(start,end,board,z)                        
            update(board,path)
            
            result = ', '.join(path)
            min_ans = total
            
        return min_ans,result
    
    
print(solve_game())
    