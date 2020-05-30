#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int long long

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  int n = s.size();
  for (int i = 0; i < n; i++) {
    if(s[i] == '?') s[i] = 'D';
  }

  for (auto it : s) {
    cout << it;
  }
  cout << '\n';
}