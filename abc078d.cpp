#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n, x, y;
  cin >> n >> x >> y;

  vector<int> a(n);
  rep(i,n) cin >> a[i];

  if(n == 1) {
    cout << abs(a[0] - y) << '\n';
    return 0;
  }

  int ans = max(abs(a.back() - y), abs(a[n - 1] - a[n - 2]));
  cout << ans << '\n';

  return 0;
}