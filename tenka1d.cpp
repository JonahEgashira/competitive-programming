#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int long long

signed main() {
  int n;
  cin >> n;

  int k = 0;
  for (int i = 1; i * (i - 1) <= 2 * n; i++) {
    if(i * (i - 1) == 2 * n) {
      k = i;
      break;
    }
  }
  if(k == 0) {
    cout << "No" << '\n';
    return 0;
  }
  vector<vector<int>> answer (k);

  int base = 0;
  int limit = k - 1;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    answer[base].push_back(i);
    answer[base + cnt + 1].push_back(i);
    cnt++;
    if(cnt == limit) {
      cnt = 0;
      limit--;
      base++;
    }
  }

  cout << "Yes" << '\n';
  cout << k << '\n';
  for (int i = 0; i < k; i++) {
    cout << (k - 1) << " ";
    for (auto it : answer[i]) {
      cout << it << " ";
    }
    cout << '\n';
  }
  return 0;
}
