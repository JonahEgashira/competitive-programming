N, T = map(int,input().split())

cost_min = 1e9

for i in range(N):
  c, t = map(int,input().split())
  if t <= T:
    if c < cost_min:
      cost_min = c

if cost_min == 1e9:
  print("TLE")
else:
  print(cost_min)