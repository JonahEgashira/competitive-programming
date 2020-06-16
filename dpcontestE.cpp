#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

const int mod = 1e9 + 7;

// dp[i][1][j] : smaller
// dp[i][0][j] : exact
ll dp[10010][2][110];

int main() {
  int d;
  string s;
  cin >> d >> s;

  int n = (int)s.size();
  memset(dp,0,sizeof(dp));

  dp[0][0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < d; j++) {

      // smaller to smaller
     for (int k = 0; k <= 9; k++) {
       dp[i + 1][1][(j + k) % d] += dp[i][1][j];
       dp[i + 1][1][(j + k) % d] %= mod;
     }

     int ni = (s[i] - '0');

     // exact to smaller
     for (int k = 0; k < ni; k++) {
       dp[i + 1][1][(j + k) % d] += dp[i][0][j];
       dp[i + 1][1][(j + k) % d] %= mod;
     }

     // exact to exact
     dp[i + 1][0][(j + ni) % d] += dp[i][0][j];
     dp[i + 1][0][(j + ni) % d] %= mod;
    }
  }

  ll ans = dp[n][1][0] + dp[n][0][0] - 1;
  ans %= mod;

  cout << ans << '\n';
  return 0;
}
