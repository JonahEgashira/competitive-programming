#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

signed main() {
  int n;
  cin >> n;

  vector<int> a(n);
  int minv = 1e9;
  int maxv = -1e9;
  int itr_max = 0, itr_min = 0;
  rep(i,n) {
    cin >> a[i];
    if(a[i] < minv) {
      minv = a[i];
      itr_min = i;
    }
    if(a[i] > maxv) {
      maxv = a[i];
      itr_max = i;
    }
  }

  vector<pair<int,int>> ans;
  if(abs(maxv) >= abs(minv)) {
    for (int i = 0; i < n; i++) {
      ans.emplace_back(itr_max + 1, i + 1);
    }
    for (int i = 1; i < n; i++) {
      ans.emplace_back(i, i + 1);
    }
  } else {
    for (int i = 0; i < n; i++) {
      ans.emplace_back(itr_min + 1, i + 1);
    }
    for (int i = n - 2; i >= 0; i--) {
      ans.emplace_back(i + 2, i + 1);
    }
  }
  cout << (int)ans.size() << '\n';
  for (auto it : ans) {
    cout << it.first << " " << it.second << '\n';
  }
  return 0;
}