#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int long long

signed main() {
  int k;
  cin >> k;

  vector<int> ans(50,49);
  for (int i = 0; i < 50; i++) {
    ans[i] += (k/50);
  }

  k%=50;
  for (int i = 0; i < k; i++) {
    ans[i] += 50 + 1;
    for (int j = 0; j < 50; j++) ans[j]--;
  }

  cout << 50 << '\n';
  for (auto it : ans) cout << it << " ";
  cout << '\n';

  return 0;
}