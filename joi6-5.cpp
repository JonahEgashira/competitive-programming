#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
#define int long long

const int INF = 1e18;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,m,k;
  cin >> n >> m >> k;

  vector<int> a(n + 1), dp(n + 1, INF);
  for (int i = 1; i <= n; i++) cin >> a[i];

  dp[0] = 0LL;
  // dp[i] := i番目までのオレンジを箱詰めした時の最小コスト　
  for (int i = 1; i <= n; i++) {
    // iの地点から、m個後ろのオレンジまで箱詰めする
    int maxv = a[i];
    int minv = a[i];
    for (int j = 0; j < m; j++) {
      if(i - j <= 0) break;
      chmax(maxv, a[i - j]);
      chmin(minv, a[i - j]);

      int cnt = j + 1;
      int cost = k + cnt * (maxv - minv);
      chmin(dp[i], dp[i - j - 1] + cost);
    }
  }

  cout << dp[n] << '\n';

}

