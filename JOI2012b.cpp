#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int N = 5050;

int dp[N][N];

signed main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n), b(m);
  rep(i,n) cin >> a[i];
  rep(i,m) cin >> b[i];

  memset(dp, 0, sizeof(dp));

  rep(i,m) {
    rep(j,n){
      if(a[j] == b[i]) {
        if(i == 0 || j == 0) dp[i][j]++;
        else chmax(dp[i][j], dp[i - 1][j - 1] + 1);
      }

      if(j > 0) chmax(dp[i][j], dp[i][j - 1]);

    }
  }

  //rep(i,m) {
  //  rep(j,n) {
  //    cout << dp[i][j] << " ";
  //  }
  //  cout << endl;
  //}

  int ans = 0;
  rep(i,m) rep(j,n) chmax(ans, dp[i][j]);

  cout << ans << '\n';

}

