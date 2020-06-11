n = int(input())
a = list(map(int,input().split()))

ok = True
for i in range(n):
  x = a[i]
  if x % 2 == 0:
    if x % 3 == 0 or x % 5 == 0:
      continue
    else:
      ok = False

if ok:
  print("APPROVED")
else:
  print("DENIED")