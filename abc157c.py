N, M = map(int,input().split())

if M == 0:
  if N == 1:
    print(0)
  if N == 2:
    print(10)
  if N == 3:
    print(100)
  exit(0)

List = []
for i in range(M):
  s, c = input().split()
  s = int(s)
  s -= 1
  List.append([s, c])

ans = -1
for v in range(1000):
  t = str(v)
  ok = True
  for i in range(M):
    s = List[i][0]
    c = List[i][1]
    if s > len(t) or N != len(t):
      ok = False
      continue

    if t[s] != c:
      ok = False

  if ok and ans == -1:
    ans = v

print(ans)