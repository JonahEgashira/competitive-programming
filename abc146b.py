n = int(input())
S = input()

ordA = ord('A')

ans = ''
for s in S:
  s = ord(s) - ordA
  ans += chr(ordA + (s + n) % 26)

print(ans)