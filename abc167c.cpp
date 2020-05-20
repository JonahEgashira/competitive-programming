#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int ans = 1e9;
int n,m,x;
vector<int> c;
vector<vector<int>> a;
vector<int> f;

void dfs(int itr, int flag) {
  if(flag) f[itr] = 1;
  else f[itr] = 0;

  if(itr == n - 1) {
    int sum = 0;
    vector<int> tmp(m, 0);
    for (int i = 0; i < n; i++) { //本を選ぶかどうか
      if(f[i] == 0) continue;
      sum += c[i];
      for (int j = 0; j < m; j++) {
        tmp[j] += a[i][j];
      }
    }
    bool ok = true;
    for (int i = 0; i < m; i++) {
      if(tmp[i] < x) ok = false;
    }
    if(ok) ans = min(ans, sum);
    return;
  }
  dfs(itr + 1, 1);
  dfs(itr + 1, 0);

  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m >> x;
  f.resize(n);
  c.resize(n);
  a.resize(n, vector<int> (m));

  for (int i = 0; i < n; i++) {
    cin >> c[i];
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }

  dfs(0, 0);
  dfs(0, 1);

  if(ans == 1e9) ans = -1;
  cout << ans << endl;
}
