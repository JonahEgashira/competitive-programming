#include <bits/stdc++.h>using namespace std;using ll = long long;int main() {  ios::sync_with_stdio(false);  cin.tie(nullptr);  int a,b,c,k;  cin >> a >> b >> c >> k;  ll ans = 0;  ll cnt = min(a,k);  ans += cnt;  k -= cnt;  cnt = min(b,k);  k -= cnt;  cnt = min(c,k);  ans -= cnt;  cout << ans << endl;}