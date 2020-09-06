#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
#define int long long

const int N = 3030;
const int T = 3030;
int dp[N][T];
int a[N], b[N];

signed main() {
  int n, t, s;
  cin >> n >> t >> s;

  for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= t; j++) {
      chmax(dp[i][j], dp[i - 1][j]);
      if(j - b[i] < s && s < j || j - b[i] < 0) continue;
      chmax(dp[i][j], dp[i - 1][j - b[i]] + a[i]);
    }
  }

  int ans = 0;
  for (int i = 0; i <= t; i++) chmax(ans, dp[n][i]);

  cout << ans << '\n';

}
