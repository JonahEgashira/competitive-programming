#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using P = pair<int,int>;

const int N = 200005;

int J[N];
int O[N];
int I[N];
int JO[N];
int JI[N];

signed main() {
  int n;
  string s;
  cin >> n >> s;

  for (int i = 0 ; i < n; i++) {
    J[i + 1] += J[i] + (s[i] == 'J' ? 1 : 0);
    I[i + 1] += I[i] + (s[i] == 'I' ? 1 : 0);
    O[i + 1] += O[i] + (s[i] == 'O' ? 1 : 0);
    JO[i + 1] = J[i + 1] - O[i + 1];
    JI[i + 1] = J[i + 1] - I[i + 1];
  }

  map<P, int> mp;
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    P p = {JO[i], JI[i]};
//    cout << p.first << " " << p.second << endl;
    if (mp[p] == 0) mp[p] = i + 1;
    else ans = max(ans, i - mp[p] + 1);
  }

  cout << ans << '\n';

}
