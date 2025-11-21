for _ in range(int(input())):
    n = int(input())
    a = [(10**9 + 1, 0, 0)]
    for i in range(n):
        l, r = map(int, input().split())
        a.append((l, r, i))
    a.sort()
    ans, comp, mx = [0]*n, [], -1
    for l, r, i in a:
        if l >= mx:
            for u in comp: ans[u] = len(comp)
            comp = []
        comp.append(i)
        mx = max(mx, r)
    print(*ans)