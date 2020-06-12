#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> table(n, vector<int> (n));
  for (int i = 0; i < m; i++) {
    int x,y;
    cin >> x >> y;
    x--, y--;
    table[x][y] = 1;
    table[y][x] = 1;
  }
  int ans = 1;
  for (int bit = 0; bit < (1 << n); bit++) {
    vector<int> people;
    for (int i = 0; i < n; i++) {
      if((bit >> i) & 1) people.push_back(i);
    }

    if(people.size() <= 1) continue;
    int sz = (int)people.size();

    bool ok = true;
    for (int i = 0; i < sz; i++) {
      for (int j = i + 1; j < sz; j++) {
        int x = people[i], y = people[j];
        if(!table[x][y]) ok = false;
      }
    }

    if(ok) ans = max(ans, sz);
  }
  cout << ans << '\n';
}