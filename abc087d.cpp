#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int long long

const int INF = 1e9;

signed main() {
  int n,m;
  cin >> n >> m;

  vector<vector<pair<int,int>>> G(n);
  vector<int> l(m), r(m), d(m);
  for (int i = 0; i < m; i++) {
    cin >> l[i] >> r[i] >> d[i];
    l[i]--, r[i]--;
    G[l[i]].emplace_back(r[i],d[i]);
    G[r[i]].emplace_back(l[i], -d[i]);
  }

  vector<int> dist(n, INF);

  for (int i = 0; i < n; i++) {
    if(dist[i] != INF) continue;
    if(G[i].empty()) continue;

    dist[i] = 0;
    queue<int> que;
    que.push(i);

    while(!que.empty()) {
      int cur = que.front();
      que.pop();
      for (auto nxt : G[cur]) {
        if(dist[nxt.first] == INF) {
          dist[nxt.first] = dist[cur] + nxt.second;
          que.push(nxt.first);
        }
      }
    }
  }

  bool flag = true;
  for (int i = 0; i < m; i++) {
    if(dist[l[i]] + d[i] != dist[r[i]]) {
      flag = false;
      break;
    }
  }
  if(flag) cout << "Yes" << '\n';
  else cout << "No" << '\n';

  return 0;
}