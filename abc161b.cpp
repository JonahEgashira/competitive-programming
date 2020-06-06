n, m = map(int, input().split())
a = list(map(int, input().split()))


S = sum(a)
cnt = 0
for i in range(n):
  if 4 * m * a[i] >= S:
    cnt += 1

if cnt >= m:
  print("Yes")
else:
  print("No")
  