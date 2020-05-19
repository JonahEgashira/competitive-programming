#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int a,b;
  cin >> a >> b;

  int ans = -1;
  for (int i = 0; i <= 100000; i++) {
    int x = floor(double(i) * 0.08);
    int y = floor(double(i) * 0.10);

    if(x == a && y == b) {
      ans = i;
      break;
    }
  }
  cout << ans << '\n';
  return 0;
}
