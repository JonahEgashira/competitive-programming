#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  int q;
  cin >> q;

  deque<pair<int,char>> que;
  while(q--) {
    int t;
    cin >> t;

    if(t == 1) {
      char c;
      int x;
      cin >> c >> x;

      pair<int,char> P = {x, c};
      que.push_back(P);
    }

    if(t == 2) {
      int d;
      cin >> d;

      map<char,int> mp;
      while(!que.empty()) {
        int v = que.front().first;
        char ch = que.front().second;
        que.pop_front();
        if(v >= d) {
          pair<int,char> P = {v - d, ch};
          que.push_front(P);
          mp[ch] += d;
          break;
        } else {
          d -= v;
          mp[ch] += v;
        }
      }

      int res = 0;
      for (auto it : mp) {
        res += (it.second) * (it.second);
      }
      cout << res << '\n';
    }
  }
  return 0;
}