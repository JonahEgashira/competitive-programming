#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define int long long

const int ALPHABET = 26;

signed main() {
  string s;
  cin >> s;

  int n = s.size();

  vector<int> cnt(ALPHABET);
  for(char c : s) {
    int x = c - 'a';
    cnt[x]++;
  }
  int answer = 1 + n * (n - 1) / 2;

  for (int i = 0; i < ALPHABET; i++) {
    int x = cnt[i];
    answer -= x * (x - 1) / 2;
  }

  cout << answer << endl;
  return 0;
}
