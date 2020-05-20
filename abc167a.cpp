#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s,t;
  cin >> s >> t;

  string s1 = s + t.back();
  if(s1 == t) cout << "Yes" << endl;
  else cout << "No" << endl;
}