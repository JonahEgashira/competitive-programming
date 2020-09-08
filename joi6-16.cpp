#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
using namespace std;
#define int long long

const int mod = 1234567;

signed main() {
  int n,k;
  cin >> n >> k;

  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] += a[i - 1];
  }

  vector<int> dp(n + 1), dp_sum(n + 1);
  dp[0] = 1;
  dp_sum[0] = 1;
  for (int i = 1; i <= n; i++) {
    int from = a[i] - k;
    int idx = lower_bound(a.begin(), a.end(), from) - a.begin();

    if(idx == i - 1) {
      dp[i] = dp[i - 1];
    } else {
      int sub = (idx == 0 ? 0 : dp_sum[idx - 1]);
      dp[i] = dp_sum[i - 1] - sub;
      if(dp[i] < 0) dp[i] += mod;
    }

    dp_sum[i] = dp_sum[i - 1] + dp[i];
    dp_sum[i] %= mod;
    dp[i] %= mod;
  }
  cout << dp[n] << '\n';
}
