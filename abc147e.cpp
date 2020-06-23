#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

const int D = 80 * 160 + 10;
const int D2 = D * 2;

typedef bitset<D2> bs;
bs dp[90][90];

int main() {
  int h,w;
  cin >> h >> w;

  vector<vector<int>> diff(h, vector<int> (w));
  rep(i, h) rep(j, w) cin >> diff[i][j];
  rep(i, h) rep(j, w) {
    int x;
    cin >> x;
    diff[i][j] -= x;
    diff[i][j] = abs(diff[i][j]);
  }

  dp[0][0][D + diff[0][0]] = 1;
  dp[0][0][D - diff[0][0]] = 1;

  rep(i,h) rep(j,w) {
    if(i > 0) {
      dp[i][j] |= dp[i - 1][j] << diff[i][j];
      dp[i][j] |= dp[i - 1][j] >> diff[i][j];
    }
    if(j > 0) {
      dp[i][j] |= dp[i][j - 1] << diff[i][j];
      dp[i][j] |= dp[i][j - 1] >> diff[i][j];
    }
  }

  int ans = D2;
  for (int i = 0; i < D2; i++) {
    if(dp[h - 1][w - 1][i]) {
      ans = min(ans, abs(D - i));
    }
  }
  cout << ans << '\n';
}
