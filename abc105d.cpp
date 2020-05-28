#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int long long

signed main() {
  int n,m;
  cin >> n >> m;

  vector<int> a(n + 1, 0), c(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; i++) {
    c[i] = c[i - 1] + a[i];
    c[i] %= m;
  }

  map<int,int> mp;
  for (int i = 0; i <= n; i++) {
    mp[c[i]]++;
  }

  int ans = 0;
  for (auto it : mp) {
    ans += (it.second) * (it.second - 1) / 2;
  }
  cout << ans << '\n';
  return 0;
}