#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
#define int long long

const int mod = 1e9 + 7;
const int N = 1000010;
int dp[N][2][2];

signed main() {
  int n;
  cin >> n;

  dp[0][0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        for (int l = 0; l <= 9; l++) {
          dp[i][j || (l == 0)][k || (l == 9)] += dp[i-1][j][k];
          dp[i][j || (l == 0)][k || (l == 9)] %= mod;
        }
      }
    }
  }

  cout << dp[n][1][1] << '\n';
}
