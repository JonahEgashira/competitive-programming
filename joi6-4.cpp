#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
#define int long long

signed main() {
  int n;
  string s;
  cin >> n >> s;

  s = '?' + s;
  n = (int)s.size();
  vector<int> Jcnt(n), Ocnt(n), Icnt(n);
  for (int i = 1; i < n; i++) {
    Jcnt[i] += Jcnt[i - 1] + (s[i] == 'J' ? 1 : 0);
    Ocnt[i] += Ocnt[i - 1] + (s[i] == 'O' ? 1 : 0);
    Icnt[i] += Icnt[i - 1] + (s[i] == 'I' ? 1 : 0);
  }

  int tmpJ = 0;
  int tmpO = 0;
  int maxO = 0;
  int tmpI = 0;
  for (int i = 0; i < n; i++) {
    int Jnum = 0;
    int Inum = 0;

    Jnum = Jcnt[i];
    Inum = Icnt.back() - Icnt[i];

    if(s[i] == 'O') {
      tmpJ += (Jnum + 1) * Inum;
      tmpI += (Inum + 1) * Jnum;
      tmpO += Jnum * Inum;
    }
    maxO = max(maxO, Jnum * Inum);
  }

  int ans = max({tmpJ, tmpI, tmpO + maxO});
  cout << ans << '\n';
}

