#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> G;
vector<int> ans;

void bfs() {
  queue<pair<int,int>> que;
  que.emplace(0, 0);
  while(!que.empty()) {
    int from = que.front().first;
    int cur = que.front().second;
    que.pop();

    for (auto to : G[cur]) {
      if(ans[to] == -1) {
        ans[to] = cur;
        que.emplace(cur, to);
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,m;
  cin >> n >> m;

  G.resize(n);
  ans.resize(n, -1);
  for (int i = 0; i < m; i++) {
    int a,b;
    cin >> a >> b;
    a--, b--;

    G[a].push_back(b);
    G[b].push_back(a);
  }

  bfs();
  cout << "Yes" << '\n';
  for (int i = 1; i < n; i++) {
    cout << ans[i] + 1 << '\n';
  }
  return 0;
}
