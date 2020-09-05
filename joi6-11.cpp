#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
#define int long long

const int mod = 10007;
const int N = 1010;
const int M = 8;
int dp[N][M];

int n;
string s;

bool check(int x, int i) {
  if((x >> 0) & 1 && s[i] == 'J') return true;
  if((x >> 1) & 1 && s[i] == 'O') return true;
  if((x >> 2) & 1 && s[i] == 'I') return true;

  return false;
}

bool same(int x, int y) {
  for (int i = 0; i < 3; i++) {
    if(((x >> i) & 1) && ((y >> i) & 1)) return true;
  }

  return false;
}

signed main() {
  cin >> n >> s;

  n++;
  s = '?' + s;

  dp[0][1] = 1;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < M; j++) {
      if(!check(j, i)) continue;
      for (int k = 1; k < M; k++) {
        if(same(k, j)) {
          dp[i][j] += dp[i - 1][k];
          dp[i][j] %= mod;
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < 8; i++) {
    ans += dp[n - 1][i];
    ans %= mod;
  }

  cout << ans << '\n';

}