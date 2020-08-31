#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int INF = 1e9;

signed main() {
  int m, n;
  cin >> m >> n;

  vector<int> p(m + 1);
  vector<pair<int,int>> c(n + 1);
  vector<int> dp(m + 1, INF);

  for (int i = 1; i <= m; i++) cin >> p[i];
  for (int i = 1; i <= n; i++) cin >> c[i].second >> c[i].first;

  p[0] = INF;
  sort(p.rbegin(), p.rend());
  p[0] = 0;

  for (int i = 1; i <= m; i++) {
    p[i] += p[i - 1];
  }

  dp[0] = 0;
  sort(c.begin(),c.end());

  for (int i = 1; i <= n; i++) {
    int capacity = c[i].second;
    int cost = c[i].first;
    for (int j = m; j >= 0; j--) {
      chmin(dp[j], dp[max(j - capacity, 0)] + cost);
    }
  }

  int ans = 0;
  for (int i = 1; i <= min(m, (int)dp.size()); i++) {
    int profit = p[i] - dp[i];
    chmax(ans, profit);
  }

  cout << ans << '\n';
}