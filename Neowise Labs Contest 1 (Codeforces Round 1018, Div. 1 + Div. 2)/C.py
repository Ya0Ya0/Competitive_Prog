import sys
import math

def main():
    print("feo")
    
    # inp = input().split()
    
    ptr = 0
    t = 1
    ptr += 1
    for _ in range(t):
        n = int(input())
        ptr += 1
        h = []
        for _ in range(n):
            row = list(map(int, input().split()))
            ptr += n
            h.append(row)
        a = list(map(int, input().split()))
        ptr += n
        b = list(map(int, input().split()))
        ptr += n
        
        # Process columns
        possible_col = True
        allowed_delta_col = []
        for j in range(n-1):
            allowed = {-1, 0, 1}
            for i in range(n):
                current_h_diff = h[i][j] - h[i][j+1]
                forbidden = -current_h_diff
                if forbidden in allowed:
                    allowed.discard(forbidden)
            allowed_delta_col.append(allowed)
            if not allowed:
                possible_col = False
        
        # Process rows
        possible_row = True
        allowed_delta_row = []
        for i in range(n-1):
            allowed = {-1, 0, 1}
            for j in range(n):
                current_h_diff = h[i][j] - h[i+1][j]
                forbidden = -current_h_diff
                if forbidden in allowed:
                    allowed.discard(forbidden)
            allowed_delta_row.append(allowed)
            if not allowed:
                possible_row = False
        
        if not possible_col or not possible_row:
            print(-1)
            continue
        
        # Compute minimal cost for columns
        INF = math.inf
        prev_col = [0, b[0]]
        for j in range(n-1):
            curr_col = [INF, INF]
            allowed = allowed_delta_col[j]
            for prev_state in [0, 1]:
                if prev_col[prev_state] == INF:
                    continue
                for curr_state in [0, 1]:
                    delta = prev_state - curr_state
                    if delta in allowed:
                        cost = prev_col[prev_state] + (b[j+1] if curr_state else 0)
                        if cost < curr_col[curr_state]:
                            curr_col[curr_state] = cost
            prev_col = curr_col
        min_col = min(prev_col)
        possible_col = possible_col and (min_col != INF)
        
        # Compute minimal cost for rows
        prev_row = [0, a[0]]
        for i in range(n-1):
            curr_row = [INF, INF]
            allowed = allowed_delta_row[i]
            for prev_state in [0, 1]:
                if prev_row[prev_state] == INF:
                    continue
                for curr_state in [0, 1]:
                    delta = prev_state - curr_state
                    if delta in allowed:
                        cost = prev_row[prev_state] + (a[i+1] if curr_state else 0)
                        if cost < curr_row[curr_state]:
                            curr_row[curr_state] = cost
            prev_row = curr_row
        min_row = min(prev_row)
        possible_row = possible_row and (min_row != INF)
        
        if possible_col and possible_row:
            print(min_col + min_row)
        else:
            print(-1)

if __name__ == '__main__':
    main()