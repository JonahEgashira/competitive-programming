#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<ll> a(n), b(n);
  rep(i,n) {
    cin >> a[i] >> b[i];
  }

  ll res = 1e18;
  for (int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      int s = a[i], g = b[j];

      ll tmp = 0;
      for (int k = 0; k < n; k++) {
        ll route1 = abs(a[k] - s) + abs(b[k] - a[k]) + abs(g - b[k]);
        ll route2 = abs(b[k] - s) + abs(a[k] - b[k]) + abs(g - a[k]);
        tmp += min(route1, route2);
      }

      res = min(res, tmp);
    }
  }
  cout << res << '\n';
}