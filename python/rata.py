import sys

def solve():
    n, k, pb, ps = map(int, input().split())
    p = [0] + list(map(int, input().split()))
    a = [0] + list(map(int, input().split()))

    bodya_score = 0
    sasha_score = 0

    visited = set()

    while k > 0 and pb not in visited:
        visited.add(pb)
        bodya_score += a[pb]
        pb = p[pb]
        k -= 1

    if k > 0:
        cycle_sum = 0
        cycle_len = 0
        start = pb
        while True:
            cycle_sum += a[pb]
            cycle_len += 1
            pb = p[pb]
            if pb == start:
                break
        bodya_score += (k // cycle_len) * cycle_sum
        k %= cycle_len
        while k > 0:
            bodya_score += a[pb]
            pb = p[pb]
            k -= 1

    visited = set()
    k = n - 1

    while k > 0 and ps not in visited:
        visited.add(ps)
        sasha_score += a[ps]
        ps = p[ps]
        k -= 1

    if k > 0:
        cycle_sum = 0
        cycle_len = 0
        start = ps
        while True:
            cycle_sum += a[ps]
            cycle_len += 1
            ps = p[ps]
            if ps == start:
                break
        sasha_score += (k // cycle_len) * cycle_sum
        k %= cycle_len
        while k > 0:
            sasha_score += a[ps]
            ps = p[ps]
            k -= 1

    if bodya_score > sasha_score:
        print("Bodya")
    elif bodya_score < sasha_score:
        print("Sasha")
    else:
        print("Draw")

t = int(input())
for _ in range(t):
    solve()