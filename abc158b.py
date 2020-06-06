x = int(input())

ans = 0
money = 100
while money < x:
  money *= 1.01
  money = int(money)
  ans += 1
print(ans)
