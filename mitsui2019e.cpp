#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int long long
#define endl '\n'

const int mod = 1000000007;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a(n);
  rep(i,n) cin >> a[i];

  int ans = 1;
  int r = 0, g = 0, b = 0;
  for(int i = 0; i < n; i++){
    int cnt = 0;
    if(r == a[i]){
      cnt++;
      r++;
    }
    if(g == a[i]){
      if(cnt != 0) cnt++;
      else {
        cnt++;
        g++;
      }
    }
    if(b == a[i]){
      if(cnt != 0) cnt++;
      else {
        cnt++;
        b++;
      }
    }
    ans *= cnt;
    ans %= mod;
  }
  cout << ans << endl;
}