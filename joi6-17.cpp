#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
#define int long long

signed main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];


  vector<int> b;
  rep(i,n + 1) {
    rep(j,n + 1) {
      int sum = a[i] + a[j];
      b.push_back(sum);
    }
  }
  sort(b.begin(),b.end());

  int ans = 0;
  n = (int)b.size();
  for (int i = 0; i < n; i++) {
    if(b[i] > m) break;
    int left = m - b[i];
    int idx = upper_bound(b.begin(),b.end(),left) - b.begin();
    if(idx == 0) continue;
    int maxv = b[idx - 1];
    ans = max(ans, b[i] + maxv);
  }
  cout << ans << '\n';
}