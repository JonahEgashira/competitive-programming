#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

const int ALPHABET = 26;

int main() {
  string s,t;
  cin >> s >> t;

  int n = (int)s.size();
  vector<vector<int>> freq(ALPHABET);
  for (int i = 0; i < (int)s.size(); i++) {
    freq[(s[i] - 'a')].push_back(i + 1);
  }

  ll ans = 0;
  int last = 0;
  int current = 0;
  for (int i = 0; i < (int)t.size(); i++) {
    int c = t[i] - 'a';
    if(freq[c].empty()) {
      cout << -1 << '\n';
      return 0;
    }
    auto itr = upper_bound(freq[c].begin(), freq[c].end(), current);
    if(itr == freq[c].end()) {
      ans += n;
      last = freq[c].front();
    } else {
      last = *itr;
    }
    current = last;
  }
  ans += last;
  cout << ans << '\n';
}
