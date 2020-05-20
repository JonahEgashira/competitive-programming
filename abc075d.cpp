#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n,k;
  cin >> n >> k;
  
  vector<int> x(n), y(n), xary(n), yary(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    xary[i] = x[i], yary[i] = y[i];
  }

  sort(xary.begin(),xary.end());
  sort(yary.begin(),yary.end());

  ll ans = 1LL * (xary[n - 1] - xary[0]) * (yary[n - 1] - yary[0]);
  for (int xi = 0; xi < n; xi++) {
    for (int xj = xi + 1; xj < n; xj++) {
      for (int yi = 0; yi < n; yi++) {
        for (int yj = yi + 1; yj < n; yj++) {

          int cnt = 0;
          ll lx = xary[xi], rx = xary[xj];
          ll by = yary[yi], uy = yary[yj];

          for (int i = 0; i < n; i++) {
            if(x[i] >= lx && x[i] <= rx && y[i] >= by && y[i] <= uy) {
              cnt++;
            }
          }
          if(cnt >= k) {
            ans = min(ans, 1LL * (rx - lx) * (uy - by));
          }
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
