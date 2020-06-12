n = int(input())
a = list(map(int,input().split()))

ans = [0] * n
a.reverse()
for i in range(n):
  if i % 2 == 0:
    ans[i//2] = a[i]
  else:
    ans[(n - 1) - (i//2)] = a[i]

print(*ans)
  