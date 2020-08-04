#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;

vector<vector<int>> G;
vector<int> color;

bool dfs(int v, int cur = 0) {
  color[v] = cur;
  for (auto next : G[v]) {
    if(color[next] != -1) {
      if(color[next] == cur) return false;
      continue;;
    }
    if(!dfs(next, !cur)) return false;
  }
  return true;
}

const int INF = 1e9;

signed main() {
  int n;
  cin >> n;

  G.resize(n);
  color.resize(n, -1);
  vector<vector<char>> s(n, vector<char>(n));
  vector<vector<int>> dist(n, vector<int> (n, INF));
  rep(i,n) rep(j,n) {
    cin >> s[i][j];
    if(s[i][j] == '1') {
      dist[i][j] = 1;
      dist[j][i] = 1;
      G[i].push_back(j);
      G[j].push_back(i);
    }
  }

  if(!dfs(0)) {
    cout << -1 << '\n';
    return 0;
  }

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if(i == j) continue;
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  int answer = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if(INF <= dist[i][j]) continue;
      answer = max(answer, dist[i][j]);
    }
  }

  cout << answer + 1 << endl;

}

