N,M = map(int,input().split())
cnt = [0] * M

for i in range(N):
  A = list(map(int, input().split()))
  for j in range(1,A[0] + 1):
    cnt[A[j] - 1] += 1

ans = 0
for i in range(M):
  if(cnt[i] == N):
    ans += 1

print(ans)
