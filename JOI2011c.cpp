#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int MAX_COST = 101010;
const int N = 110;

int dp[N][MAX_COST];

signed main() {
  int n, a, b, c;
  cin >> n >> a >> b >> c;

  vector<int> d(n + 1);
  for (int i = 1; i <= n; i++) cin >> d[i];

  for (int i = 0; i <= n; i++) {
     for (int j = 0; j <= MAX_COST; j++) {
       if(i == 0) {
         if(j - a >= 0) dp[i][j] = c;
         continue;
       }

       if(j - b >= a) chmax(dp[i][j], dp[i - 1][j - b] + d[i]);
       chmax(dp[i][j], dp[i - 1][j]);
     }
  }

  int ans = 0;
  for (int i = 1; i <= MAX_COST; i++) {
    int calorie_per_cost = dp[n][i] / i;
    chmax(ans, calorie_per_cost);
  }

  cout << ans << '\n';

  return 0;
}

