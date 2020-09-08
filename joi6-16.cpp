#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
using namespace std;
#define int long long

// start : 17:44
const int T = 11;
const int N = 2020;
int dp[T][N];

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  vector<vector<int>> a(T);
  rep(i,n) {
    int cost, genre;
    cin >> cost >> genre;
    a[genre].push_back(cost);
  }

  rep(i,T) {
    if(a[i].empty()) continue;
    sort(a[i].rbegin(),a[i].rend());
  }

  rep(i,T) {
    if(a[i].size() < 2) continue;
    for (int j = 1; j < (int)a[i].size(); j++) {
      a[i][j] += a[i][j - 1];
    }
  }

  memset(dp, -1, sizeof(dp));
  rep(i,T) dp[i][0] = 0;
  for (int i = 1; i < T; i++) {
    int sz = a[i].size();
    // iでcur冊売って、合計でtot冊売るときの最大
    for (int cur = 1; cur <= sz; cur++) {
      int bonus = (cur - 1) * cur;
      for (int tot = 0; tot <= k; tot++) {
        chmax(dp[i][tot], dp[i - 1][tot]);
        if(tot - cur < 0) continue;
        if(dp[i - 1][tot - cur] == -1) break;
        chmax(dp[i][tot], dp[i - 1][tot - cur] + a[i][cur - 1] + bonus);
      }
    }
  }

  int ans = 0;
  rep(i,T) rep(j,N) chmax(ans, dp[i][j]);

  cout << ans << '\n';
}
