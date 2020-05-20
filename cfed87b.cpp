#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9;

void solve() {
  string s;
  cin >> s;

  int n = (int)s.size();
  vector<vector<int>> lst(3, vector<int>(n, INF));

  for (int i = 0; i < n; i++) {
    if(s[i] == '1') lst[0][i] = i;
    if(s[i] == '2') lst[1][i] = i;
    if(s[i] == '3') lst[2][i] = i;

    if(i != 0) {
      for (int j = 0; j < 3; j++) {
        if(lst[j][i - 1] != INF && lst[j][i] == INF) lst[j][i] = lst[j][i - 1];
      }
    }
  }

  int ans = n + 1;
  for (int i = 0; i < n; i++) {
    int minv = 1e9;
    int maxv = 0;
    for (int j = 0; j < 3; j++) {
      minv = min(minv, lst[j][i]);
      maxv = max(maxv, lst[j][i]);
    }
    int tmp = maxv - minv + 1;
    ans = min(ans, tmp);
  }
  if(ans == n + 1) cout << 0 << '\n';
  else cout << ans << '\n';
  return;
}

int main(){
  int tc;
  cin >> tc;

  while(tc--) {
    solve();
  }
  return 0;
}