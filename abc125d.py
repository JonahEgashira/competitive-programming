n = int(input())
a = list(map(int,input().split()))

minus_cnt = 0
for i in range(n):
  if a[i] < 0:
    minus_cnt += 1
    a[i] *= -1
  
s = sum(a)
a.sort()
if(minus_cnt % 2 == 1):
  s -= a[0] * 2

print(s)