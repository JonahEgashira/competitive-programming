#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

void solve(){
  string s;
  int n;
  cin >> s >> n;

  vector<int> b(n);
  rep(i,n) cin >> b[i];

  vector<vector<int>> groups;

  while(true) {
    vector<int> pos;
    rep(i,n) {
      if(b[i] == 0) {
        pos.push_back(i);
      }
    }
    if(pos.empty()) break;
    groups.push_back(pos);
    rep(i,n) {
      if(b[i] == 0) b[i] = INT_MAX;
      else {
        for (int pp : pos) {
          b[i] -= abs(i - pp);
        }
      }
    }
  }

  vector<int> alphabet(26);
  for (int i = 0; i < (int)s.size(); i++) {
    alphabet[(s[i] - 'a')]++;
  }

  vector<char> res(n, '?');
  int j = 25;
  for (int i = 0; i < (int)groups.size(); i++) {
    while(j >= 0 && alphabet[j] < (int)groups[i].size())
      j--;

    for (auto zero : groups[i]) {
      res[zero] = ('a' + j);
    }
    j--;
  }
  for (auto it : res) {
    cout << it;
  }
  cout << '\n';
  return;
}

signed main() {
  int tc;
  cin >> tc;

  while(tc--){
    solve();
  }
  return 0;
}