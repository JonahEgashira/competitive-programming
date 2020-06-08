n = int(input())
a = list(map(int, input().split()))

def swap(list, pos1, pos2) :
  list[pos1], list[pos2] = list[pos2], list[pos1]
  return list

ok = 0
for i in range(n):
  for j in range(i, n):
    b = a.copy()
    swap(b, i, j)
    flag = 1
    for k in range(1, n):
      if b[k - 1] > b[k]:
        flag = 0

    if flag == 1:
      ok = 1

if ok == 1:
  print("YES")
else:
  print("NO")