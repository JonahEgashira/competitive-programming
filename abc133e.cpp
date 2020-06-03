#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

const int mod = 1e9 + 7;

int n, k;
ll ans = 1;
vector<vector<int>> G;

void dfs(int cur, int pre, int num) {
  ans = ans * num % mod;

  num = k - 1;
  if(pre != -1) num--;
  for (auto nxt : G[cur]) {
    if(nxt == pre) continue;
    dfs(nxt, cur, num);
    num--;
  }
}

int main() {
  cin >> n >> k;

  G.resize(n);
  for (int i = 0; i < n - 1; i++) {
    int a,b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  dfs(0, -1, k);
  cout << ans << '\n';
}