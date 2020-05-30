#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int long long

int return_sum(int n) {
  return n * (n + 1) / 2;
}

signed main() {
  int n, x;
  cin >> n >> x;

  vector<int> days(2 * n);
  for (int i = 0; i < n; i++) {
    cin >> days[i];
    days[i + n] = days[i];
  }
  vector<int> prefix_days(2 * n + 1);
  vector<int> prefix_sums(2 * n + 1);

  for (int i = 0; i < 2 * n; i++) {
    prefix_days[i + 1] = prefix_days[i] + days[i];
  }

  for (int i = 0; i < 2 * n; i++) {
    prefix_sums[i + 1] = prefix_sums[i] + return_sum(days[i]);
  }

  int ans = 0;
  for (int end = n + 1, first = 0; end <= 2 * n; end++) {
    while(first < end && prefix_days[end] - prefix_days[first + 1] >= x) {
      first++;
    }
    //prefix_days[i + 1] == days[i]
    int tmp = prefix_sums[end] - prefix_sums[first + 1];
    int days_in_first = x - (prefix_days[end] - prefix_days[first + 1]);
    tmp += return_sum(days[first]) - return_sum(days[first] - days_in_first);
    ans = max(ans, tmp);
  }
  cout << ans << '\n';
  return 0;
}