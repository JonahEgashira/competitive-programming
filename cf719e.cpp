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
  string s;
  cin >> s;

  vector<int> pref_sum(n), count_sum(n);
  for (int i = 0; i < n; i++) {
    if (s[i] == '.') pref_sum[i]++;
    else count_sum[i]++;
  }
  for (int i = 1; i < n; i++) {
    pref_sum[i] += pref_sum[i-1];
    count_sum[i] += count_sum[i-1];
  }
  vector<int> sheep_sum(n);
  for (int i = 0; i < n; i++) {
    if (s[i] == '*') sheep_sum[i] = pref_sum[i];
  }
  for (int i = 1; i < n; i++) {
    sheep_sum[i] += sheep_sum[i-1];
  }

  int res = LLONG_MAX;
  for (int i = 0; i < n; i++) {
    if (s[i] == '*') {
      int tmp = 0;
      int cur_sum = pref_sum[i];
      if (i != 0) {
        int lcnt = count_sum[i-1];
        int lsum = sheep_sum[i-1];
        tmp += (cur_sum * lcnt - lsum);
      }
      if (i != n - 1) {
        int rcnt = count_sum.back() - count_sum[i+1];
        int rsum = sheep_sum.back() - sheep_sum[i+1];
        tmp += (rsum - cur_sum * rcnt);
      }
      res = min(res, tmp);
    }
  }
  if (res == LLONG_MAX) res = 0;
  cout << res << '\n';
}

signed main() {
  int tc;
  cin >> tc;

  while(tc--){
    solve();
  }
}
