import heapq

T = int(input())
for t in range(T):
    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    C = sorted([(a, b) for a, b in zip(A, B)])
    ans = 10**18
    Q = []
    bsum = 0
    for i in range(N):
        a, b = C[i]
        if len(Q) == K - 1:
            ans = min(ans, a * (bsum + b))
        heapq.heappush(Q, -b)
        bsum += b
        if len(Q) > K - 1:
            bsum -= -heapq.heappop(Q)
    print(f"ans = {ans}")
