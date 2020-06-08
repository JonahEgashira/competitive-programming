#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

void solve(){
  int n;
  cin >> n;

  vector<int> a(n), b(n);
  vector<pair<int,int>> c(n);
  rep(i,n) cin >> a[i], a[i]--;
  rep(i,n) cin >> b[i], b[i]--;

  rep(i,n) {
    c[a[i]].first = i;
    c[b[i]].second = i;
  }

  vector<int> itr(n);
  rep(i,n) {
    itr[i] = c[i].second - c[i].first;
    if(itr[i] < 0) itr[i] += n;
  }

  map<int,int> mp;
  for (int i = 0; i < n; i++) {
    mp[itr[i]]++;
  }

  int ans = 1;
  for(auto it : mp) {
    ans = max(ans,it.second);
  }
  cout << ans << '\n';
}

int main() {

  solve();

  return 0;
}