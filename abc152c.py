n = int(input())
a = list(map(int,input().split()))

p = [0] * n
minv = 1e9
for i in range(n):
  minv = min(minv, a[i])
  p[i] = minv

ans = 0
for i in range(n):
  if a[i] <= p[i]:
    ans += 1

print(ans)