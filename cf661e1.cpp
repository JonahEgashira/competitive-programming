#include <bits/stdc++.h>
using namespace std;
#define int long long
using P = pair<int,int>;

int n,s;
int sum = 0;
vector<vector<int>> G;
map<P, int> weight;
map<P, int> cnt;
priority_queue<pair<int,P>> que;

int dfs(int cur, int from = -1) {
  int tmp = 0;
  bool flag = false;
  for (auto next : G[cur]) {
    if(from == next) continue;
    tmp += dfs(next, cur);
    flag = true;
  }
  if(from == -1) return 0;
  if(cur > from) swap(cur, from);
  P p = {cur, from};
  if(!flag) {
    cnt[p] = 1;
    return 1;
  }
  cnt[p] = tmp;
  return tmp;
}

void solve(){
  cin >> n >> s;
  G.resize(n);
  vector<int> V(n - 1), U(n - 1);
  for (int i = 0; i < n - 1; i++) {
    int v, u, w; cin >> v >> u >> w;
    --v, --u;
    if(v > u) swap(v,u);
    V[i] = v, U[i] = u;
    P p = {v,u};
    G[v].push_back(u);
    G[u].push_back(v);
    weight[p] = w;
  }

  dfs(0);

  for (int i = 0; i < n - 1; i++) {
    P p = {V[i], U[i]};
    sum += weight[p] * cnt[p];
  }

  for (int i = 0; i < n - 1; i++) {
    P p = {V[i], U[i]};
    int cur = weight[p] * cnt[p];
    weight[p] /= 2;
    int half = weight[p] * cnt[p];
    int tmp = cur - half;
    que.emplace(tmp,p);
  }

  int answer = 0;
  while(sum > s) {
    pair<int,P> p = que.top();
    que.pop();
    int diff = p.first;
//  cout << diff << endl;
    P id = p.second;

    sum -= diff;
    int cur = weight[id] * cnt[id];
    weight[id] = weight[id]/2;
    int half = weight[id] * cnt[id];
    int tmp = cur - half;
    que.emplace(tmp, id);

    answer++;
  }

  cout << answer << '\n';
}

void init() {
  sum = 0;
  G = vector<vector<int>>();
  weight = map<P,int>();
  cnt = map<P,int>();
  que = priority_queue<pair<int,P>>();
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;

  while(tc--){
    solve();
    init();
  }
  return 0;
}