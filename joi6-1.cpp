#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

signed main() {
  int n;
  cin >> n;

  vector<pair<int,int>> a(n + 1);
  vector<int> b(n);

  rep(i,n + 1) {
    cin >> a[i].first;
    a[i].second = i;
  }
  rep(i, n) cin >> b[i];

  sort(a.rbegin(),a.rend());
  sort(b.rbegin(),b.rend());

  vector<int> c1(n + 1), c2(n + 1);
  for (int i = 0; i < n; i++) {
    c1[i] = max(a[i].first - b[i], 0);
    c2[i] = max(a[i + 1].first - b[i], 0);
  }

  for (int i = 1; i < n + 1; i++) c1[i] = max(c1[i], c1[i - 1]);
  for (int i = n - 1; i >= 0; i--) c2[i] = max(c2[i], c2[i + 1]);

  vector<int> ans(n + 1);
  for (int i = 0; i < n + 1; i++) {
    int val = 0;
    if(i == 0) {
      val = c2[i];
    } else {
      val = max(c1[i - 1], c2[i]);
    }
    ans[a[i].second] = val;
  }

  for (auto it : ans) {
    cout << it << " ";
  }
  cout << '\n';

}

