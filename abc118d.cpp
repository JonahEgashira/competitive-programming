#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

const string MINUS_INF = "-";

void chmax(string &a, string b) {
  int a_sz = (int)a.size();
  int b_sz = (int)b.size();

  if(a == MINUS_INF) a = b;
  else if(a_sz < b_sz) a = b;
  else if(a_sz == b_sz) {
    if(a < b) a = b;
  }
}

int main() {
  int n,m;
  cin >> n >> m;

  vector<int> matches{0,2,5,5,4,5,6,3,7,6};
  vector<int> a(m);
  rep(i,m) cin >> a[i];

  // dp[i]
  // マッチ棒をi本使った時にできる最大の数（文字列）
  vector<string> dp(n + 10, MINUS_INF);

  dp[0] = "";
  for (int i = 0; i <= n; i++) {
    if(dp[i] == MINUS_INF) continue;
    for (auto &it : a) {
      int match = matches[it];
      string number = to_string(it);
      chmax(dp[i + match], (dp[i] + number));
    }
  }
  cout << dp[n] << '\n';
}