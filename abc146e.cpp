#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  ll n,k;
  cin >> n >> k;

  vector<ll> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  vector<ll> prefix_sum(n + 1);
  for (int i = 1; i <= n; i++) {
    prefix_sum[i] = prefix_sum[i - 1] + a[i];
  }

  vector<int> mod(n + 1);
  for (int i = 1; i <= n; i++) {
    mod[i] = (prefix_sum[i] - i + k) % k;
  }

  ll answer = 0;
  map<int,int> mp;
  for (int i = 0; i <= n; i++) {
    if (i - k >= 0) mp[mod[i - k]]--;
    answer += mp[mod[i]];
    mp[mod[i]]++;
  }

  cout << answer << '\n';
  return 0;
}
