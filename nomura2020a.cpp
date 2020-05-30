#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int long long

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int h1, m1, h2, m2, k;
  cin >> h1 >> m1 >> h2 >> m2 >> k;

  int ans = 0;
  if(m2 <= m1) {
    int h = (h2 - h1 - 1);
    int m = (60 - m1) + m2;
    ans += h * 60 + m;
  } else {
    int h = h2 - h1;
    int m = m2 - m1;
    ans += h * 60 + m;
  }
  ans = max(0LL, ans - k);
  cout << ans << '\n';
}