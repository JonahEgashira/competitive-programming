#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int long long

const int N = 100010;
int x[N], v[N];
int r[N], l[N];

signed main() {
  int n,c;
  cin >> n >> c;

  memset(x, 0, sizeof(x));
  memset(v, 0, sizeof(v));
  memset(r, 0, sizeof(r));
  memset(l, 0, sizeof(l));

  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> v[i];
  }

  for (int i = 1; i <= n; i++) {
    r[i] = r[i - 1] + v[i];
  }

  for (int i = n; i >= 1; i--) {
    l[i] = l[i + 1] + v[i];
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    r[i] = max(r[i] - x[i], r[i - 1]);
    ans = max(ans, r[i]);
  }

  for (int i = n; i >= 1; i--) {
    l[i] = max(l[i] - (c - x[i]), l[i + 1]);
    ans = max(ans, l[i]);
  }

  // r to l
  for (int i = 0; i <= n - 1; i++) {
    int tmp = l[i + 1] + r[i] - x[i];
    ans = max(ans, tmp);
  }

  // l to r
  for (int i = n; i >= 1; i--) {
    int tmp = r[i - 1] + l[i] - (c - x[i]);
    ans = max(ans, tmp);
  }

  cout << ans << '\n';
  return 0;
}