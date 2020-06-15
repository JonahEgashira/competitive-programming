#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  sort(a.begin(),a.end());

  int ans = 0;
  vector<int> used(1100000,0);
  vector<int> check(n, 0);
  map<int,int> mp;

  for (int i = 0; i < n; i++) {
    int x = a[i];
    mp[x]++;

    if(used[x]) continue;

    ans++;

    check[i] = 1;
    int add = x;
    while(x < 1010000) {
      used[x] = 1;
      x += add;
    }
  }

  for (int i = 0; i < n; i++) {
    if(check[i] && mp[a[i]] > 1) ans--;
  }

  cout << ans << '\n';
}
