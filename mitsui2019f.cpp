#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
using namespace std;
using ll = long long;

int main(){
  ll t1, t2, a1, a2, b1, b2;
  cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;

  ll diff1 = (a1 - b1) * t1;
  ll diff2 = (a2 - b2) * t2;

  if(0 < diff1) {
    diff1 = -diff1;
    diff2 = -diff2;
  }

  if(diff1 + diff2 < 0) {
    cout << 0 << endl;
    return 0;
  } else if(diff1 + diff2 == 0) {
    cout << "infinity" << endl;
    return 0;
  }

  ll answer = (-diff1/(diff1+diff2)) * 2 + (-diff1%(diff1+diff2) != 0);
  cout << answer << endl;

  return 0;
}
