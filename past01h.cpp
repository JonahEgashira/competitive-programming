#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

const int INF = 1e9;

int main() {
  int n,m;
  cin >> n >> m;


  vector<vector<char>> board(n, vector<char> (m));
  vector<vector<int>> dp(n, vector<int> (m, INF));
  int gx = 0, gy = 0;
  rep(i,n) rep(j,m) {
    cin >> board[i][j];
    if(board[i][j] == 'S') board[i][j] = '0', dp[i][j] = 0;
    if(board[i][j] == 'G') gx = i, gy = j;
  }

  for (int k = 1; k <= 10; k++) {
    char p = (k - 1) + '0';
    char c = k + '0';
    if(k == 10) c = 'G';

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (int ni = 0; ni < n; ni++) {
          for (int nj = 0; nj < m; nj++) {
            if (i == ni && j == nj) continue;

            if(board[i][j] == p && board[ni][nj] == c) {
              dp[ni][nj] = min(dp[ni][nj], dp[i][j] + abs(ni - i) + abs(nj - j));
            }
          }
        }
      }
    }
  }
  int res = dp[gx][gy];
  if(res == INF) res = -1;
  cout << res << '\n';
  return 0;
}