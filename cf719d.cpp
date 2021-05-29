#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <bitset>
#include <math.h>
#include <random>
#include <chrono>
#include <assert.h>
#include <climits>

using namespace std;
#define int long long

void solve(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &it : a) cin >> it;
  map<int,int> mp;
  for (int i = 0; i < n; i++) {
    mp[a[i]-i]++;
  }
  int res = 0;
  for (auto [val, cnt] : mp) {
    res += cnt * (cnt - 1) / 2;
  }
  cout << res << '\n';
}

signed main() {
  int tc;
  cin >> tc;

  while(tc--){
    solve();
  }
}
