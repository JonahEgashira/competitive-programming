n = int(input())
t, a = map(int,input().split())
a *= 1000
t *= 1000
h = list(map(int,input().split()))

diff = 1e9
ans = 0
for i in range(n):
  h[i] = t - h[i] * 6
  if abs(a - h[i]) < diff:
    diff = abs(a - h[i])
    ans = i + 1
  
print(ans)
