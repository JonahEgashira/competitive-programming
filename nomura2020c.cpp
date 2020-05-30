#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int long long

signed main() {
  int n;
  cin >> n;

  vector<int> a(n + 1);
  rep(i, n + 1) cin >> a[i];

  if(n == 0) {
    if(a[0] == 1) cout << 1 << '\n';
    else cout << -1 << '\n';
    return 0;
  }

  vector<int> sum(n + 2);
  for (int i = n; i >= 0; i--) {
    sum[i] = sum[i + 1] + a[i];
  }

  int ans = 0;
  int start = 1;
  for (int i = 0; i <= n; i++) {
    ans += min(start, sum[i]);
    start -= a[i];
    if(start < 0) {
      cout << -1 << '\n';
      return 0;
    }
    start = min(start * 2, (long long)1e18);
  }
  cout << ans << '\n';

}