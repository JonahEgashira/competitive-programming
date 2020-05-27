#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int long long

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a(n);
  int maxv = 0;
  rep(i, n) {
    cin >> a[i];
  }

  vector<int> pref(n + 1);
  for (int i = 0; i < n; i++) {
    pref[i + 1] = gcd(pref[i], a[i]);
  }

  vector<int> suf(n + 1);
  for (int i = n - 1; i >= 0; i--) {
    suf[i] = gcd(suf[i + 1], a[i]);
  }

  int ans = 1;
  for (int i = 0; i < n; i++) {
    int x = gcd(pref[i], suf[i + 1]);
    ans = lcm(ans, x);
  }

  cout << ans << '\n';
}