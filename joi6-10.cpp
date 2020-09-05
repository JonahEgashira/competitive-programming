#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
#define int long long

const int N = 1010;
char flag[N][N];
char mark[2][2];

bool check(int i, int j) {
  if(flag[i][j] == mark[0][0] && flag[i + 1][j] == mark[1][0]
  && flag[i][j + 1] == mark[0][1] && flag[i + 1][j + 1] == mark[1][1]) return true;

  return false;
}

int h, w;
bool is_in(int i, int j) {
  if(0 <= i && i < h && 0 <= j && j < w) return true;
  return false;
}

signed main() {
  cin >> h >> w;

  rep(i,h) rep(j,w) cin >> flag[i][j];
  rep(i,2) rep(j,2) cin >> mark[i][j];

  int best = 0;
  for (int i = 0; i + 1 < h; i++) {
    for (int j = 0; j + 1 < w; j++) {
      if(check(i, j)) best++;
    }
  }

  int ans = best;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      for (int k = 0; k < 3; k++) {
        char c = 'J';
        char prev = flag[i][j];
        if(k == 1) c = 'O';
        if(k == 2) c = 'I';
        if(prev == c) continue;
        int tmp = best;

        if(is_in(i - 1, j - 1)) {
          if(check(i - 1, j - 1)) tmp--;
        }
        if(is_in(i - 1, j)) {
          if(check(i - 1, j)) tmp--;
        }
        if(is_in(i, j - 1)) {
          if(check(i, j - 1)) tmp--;
        }
        if(is_in(i, j)) {
          if(check(i, j)) tmp--;
        }

        flag[i][j] = c;

        if(is_in(i - 1, j - 1)) {
          if(check(i - 1, j - 1)) tmp++;
        }
        if(is_in(i - 1, j)) {
          if(check(i - 1, j)) tmp++;
        }
        if(is_in(i, j - 1)) {
          if(check(i, j - 1)) tmp++;
        }
        if(is_in(i, j)) {
          if(check(i, j)) tmp++;
        }

        flag[i][j] = prev;

        ans = max(ans, tmp);
      }
    }
  }

  cout << ans << '\n';
}