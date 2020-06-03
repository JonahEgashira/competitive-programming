#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

signed main() {
  int n,t;
  cin >> n >> t;

  vector<pair<int,int>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
  }

  sort(a.begin(),a.end());

  int ans = 0;
  vector<vector<int>> dp(n + 1, vector<int> (t + 1));
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < t; j++) {
      if(j - a[i].first >= 0) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i].first] + a[i].second);
      }
      dp[i][j] = max(dp[i][j], dp[i - 1][j]);
      if(j == t - 1) ans = max(ans, dp[i][j] + a[i+1].second);
    }
  }
  cout << ans << '\n';
}