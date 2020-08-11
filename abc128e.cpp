#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define int long long

using event = pair<int, pair<int,int>>;

signed main() {
  int n,q;
  cin >> n >> q;

  vector<event> queries;
  rep(i,n) {
    int s, t, x;
    cin >> s >> t >> x;

    event insert = {s - x, {1, x}};
    event erase = {t - x, {-1, x}};

    queries.push_back(insert);
    queries.push_back(erase);
  }

  sort(queries.begin(),queries.end());
  set<int> points;

  vector<int> d(q), answer(q);
  rep(i,q) cin >> d[i];

  int j = 0;
  for (int i = 0; i < q; i++) {
    while(j < queries.size() && queries[j].first <= d[i]) {
      event query = queries[j];
      if(query.second.first == 1) points.insert(query.second.second);
      else if(query.second.first == -1) points.erase(query.second.second);
      j++;
    }
    if(points.empty()) answer[i] = -1;
    else answer[i] = *points.begin();
  }

  for (auto it : answer) cout << it << '\n';
  return 0;
}