#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
#define int long long

signed main() {
  int n,m;
  cin >> n >> m;

  queue<int> a, b;
  rep(i,n) {
    int x; cin >> x;
    a.push(x);
  }
  rep(i,m) {
    int x; cin >> x;
    b.push(x);
  }

  vector<int> c;
  while(true) {
    if(a.empty() && b.empty()) break;

    if(a.empty()) {
      int x = b.front();
      b.pop();
      c.push_back(x);
    } else if(b.empty()) {
      int x = a.front();
      a.pop();
      c.push_back(x);
    } else {
      int xa = a.front();
      int xb = b.front();

      if(xa <= xb) {
        a.pop();
        c.push_back(xa);
      } else {
        b.pop();
        c.push_back(xb);
      }
    }
  }
  for (auto it : c) cout << it << '\n';
}

