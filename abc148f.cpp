#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int n, u, v;
  cin >> n >> u >> v;
  u--, v--;

  vector<vector<int>> G(n);
  rep(i,n - 1) {
    int a,b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  vector<int> dist_u(n, -1), dist_v(n, -1);
  queue<int> que_u;
  que_u.push(u);
  dist_u[u] = 0;

  while(!que_u.empty()) {
    int cur = que_u.front();
    que_u.pop();

    for (auto nxt: G[cur]) {
      if(dist_u[nxt] == -1) {
        dist_u[nxt] = dist_u[cur] + 1;
        que_u.push(nxt);
      }
    }
  }
  queue<int> que_v;
  que_v.push(v);
  dist_v[v] = 0;

  while(!que_v.empty()) {
    int cur = que_v.front();
    que_v.pop();

    for (auto nxt: G[cur]) {
      if(dist_v[nxt] == -1) {
        dist_v[nxt] = dist_v[cur] + 1;
        que_v.push(nxt);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if(dist_u[i] >= dist_v[i]) {
      continue;
    }
    ans = max(ans, dist_v[i] - 1);
  }

  cout << ans << '\n';
  return 0;
}