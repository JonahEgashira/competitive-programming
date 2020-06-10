N = int(input())
List = []
for i in range(N):
  S,P = input().split()
  P = int(P)
  List.append([S,P,i+1])
List.sort(key = lambda x : (x[0], -x[1]))

for i in range(N):
  print(List[i][2])