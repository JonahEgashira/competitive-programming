#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n; i++)
typedef long long ll;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  double n;
  cin >> n;

  bool flag = false;
  double ans = 0;
  for(double i = 1; i <= 50000; i++){
    if(floor(i * 1.08) == n){
      flag = true;
      ans = i;
      break;
    }
  }

  if(flag) cout << ans << endl;
  else cout << ":(" << endl;
}
