#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;

signed main() {
  int n,c,k;
  cin >> n >> c >> k;

  vector<int> t(n);
  rep(i,n) cin >> t[i];

  sort(t.begin(),t.end());

  int cur = 0;
  int answer = 1;
  while(true) {
    int i = 0;
    while(i < c && t[i + cur] <= t[cur] + k && cur + i < n)
      i++;

    if(cur + i == n) break;
    cur = cur + i;
    answer++;
  }
  cout << answer << endl;
  return 0;
}

