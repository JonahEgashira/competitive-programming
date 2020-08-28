#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
#define int long long

signed main() {
  int n, t, q;
  cin >> n >> t >> q;

  vector<int> a(n), d(n);
  rep(i,n) cin >> a[i] >> d[i];

  vector<int> stop;
  int cur = 0;
  for (int i = 0; i < n; i++) {
    if(d[i] == 1) {
      cur = a[i];
    } else if(d[i] == 2) {
      if(cur != 0) {
        int mid = (cur + a[i]) / 2;
        stop.push_back(mid);
      }
      cur = 0;
    }
  }

  int m = (int)stop.size();
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    if(d[i] == 1) {
      if(stop.empty()) {
        ans[i] = a[i] + t;
      } else {
        int itr = lower_bound(stop.begin(), stop.end(), a[i]) - stop.begin();
        if(itr == m) {
          ans[i] = a[i] + t;
        } else {
          ans[i] = min(a[i] + t, stop[itr]);
        }
      }
    } else {
      if(stop.empty()) {
        ans[i] = a[i] - t;
      } else {
        int itr = lower_bound(stop.begin(), stop.end(), a[i]) - stop.begin();
        itr--;
        if(itr == -1) {
          ans[i] = a[i] - t;
        } else {
          ans[i] = max(a[i] - t, stop[itr]);
        }
      }
    }
  }

  while(q--) {
    int x; cin >> x;
    cout << ans[x - 1] << '\n';
  }

}

