#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
#define int long long

int n,w,h;
int calc_dist(int x1, int y1, int x2, int y2) {
  return ((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}
bool is_in(int x1, int y1, int x2, int y2) {
  double d = double(calc_dist(x1, y1, x2, y2));
  d = sqrt(d);
  if(double(x1 - d) < 0.0 || double(x1 + d) > w) return false;
  if(double(y1 - d) < 0.0 || double(y1 + d) > h) return false;
  return true;
}

signed main() {
  cin >> n >> w >> h;

  vector<int> x(n), y(n);
  rep(i,n) cin >> x[i] >> y[i];

  int ans = 0;
  rep(i,n) {
    rep(j,n) {
      if (j == i) continue;
      rep(k,n) {
        if (k == j || k == i) continue;
        rep(l, n) {
          if(l == k || l == j || l == i) continue;
          int cx1 = x[i];
          int cy1 = y[i];
          int ox1 = x[j];
          int oy1 = y[j];
          int cx2 = x[k];
          int cy2 = y[k];
          int ox2 = x[l];
          int oy2 = y[l];

          if(!is_in(cx1, cy1, ox1, oy1)) continue;
          if(!is_in(cx2, cy2, ox2, oy2)) continue;

          int radius1 = calc_dist(cx1, cy1, ox1, oy1);
          int radius2 = calc_dist(cx2, cy2, ox2, oy2);
          int dist_center = calc_dist(cx1, cy1, cx2, cy2);
          int right = radius1 - radius2 - dist_center;
          if(right < 0) continue;

          if(4 * radius2 * dist_center < right * right) ans++;

        }
      }
    }
  }

  cout << ans << '\n';

}
