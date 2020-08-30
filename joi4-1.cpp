#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int N = 505;
char poster[N][N][4];
char answer[N][N];

signed main() {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> poster[i][j][0];
      poster[j][n - i + 1][1] = poster[i][j][0];
      poster[n - j + 1][i][2] = poster[i][j][0];
      poster[n - i + 1][n - j + 1][3] = poster[i][j][0];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> answer[i][j];
    }
  }

  int best = INT_MAX;
  for (int tc = 0; tc < 4; tc++) {
    int tmp = 0;
    if(tc == 1 || tc == 2) tmp = 1;
    else if(tc == 3) tmp = 2;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (poster[i][j][tc] != answer[i][j]) tmp++;
      }
    }
    best = min(best, tmp);
  }

  cout << best << '\n';
}
