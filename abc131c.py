import math
a, b, c, d = map(int, input().split())
ans = b - a + 1

def lcm(x, y):
  return (x * y) // math.gcd(x, y)

a -= 1
ans = ans - (b//c) - (b//d) + (b//(lcm(c,d)))
ans = ans + (a//c) + (a//d) - (a//(lcm(c,d)))
print(ans)