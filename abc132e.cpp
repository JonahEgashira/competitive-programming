#include <bits/stdc++.h>
using namespace std;

signed main() {
  int n,m;
  cin >> n >> m;

  vector<vector<int>> G(n);
  for (int i = 0; i < m; i++) {
    int u,v;
    cin >> u >> v;
    u--, v--;

    G[u].push_back(v);
  }
  int s,t;
  cin >> s >> t;
  s--, t--;

  vector<vector<int>> dist(n, vector<int> (3,-1));
  queue<pair<int,int>> que;
  que.emplace(s,0);
  dist[s][0] = 0;
  while(!que.empty()) {
    int cur = que.front().first;
    int mod = que.front().second;
    que.pop();

    for (auto nxt : G[cur]) {
      if(dist[nxt][(mod+1)%3] != -1) continue;

      que.emplace(nxt, (mod+1)%3);
      dist[nxt][(mod+1)%3] = dist[cur][mod] + 1;
    }
  }
  int ans = dist[t][0];
  if(ans != -1) ans /= 3;
  cout << ans << '\n';
  return 0;
}