#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int a[3];

  cin >> a[0] >> a[1] >> a[2];
  sort(a, a + 3);

  int cnt = 0;
  int tmp = a[2] - a[1];
  cnt += tmp;
  a[0] += tmp;

  tmp = a[2] - a[0];
  if(tmp % 2 == 0) cnt += tmp/2;
  else cnt += tmp/2 + 2;
  cout << cnt << '\n';
  return 0;
}