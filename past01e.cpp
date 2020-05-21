#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }

  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    int x = i;
    int cnt = 0;
    while(true) {
      x = a[x];
      cnt++;
      if(x == i) break;
    }
    ans[i] = cnt;
  }
  for (auto it : ans) cout << it << " ";
  cout << '\n';
  return 0;
}