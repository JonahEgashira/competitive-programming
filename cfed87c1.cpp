#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const long double PI = acos(-1);

int main(){
  int tc;
  cin >> tc;

  while(tc--) {
    int n;
    cin >> n;

    n *= 2;

    if(n % 4 == 0) {
      long double theta = PI / n;
      long double side = 0.5 / tan(theta);
      side *= 2.0;
      cout << fixed << setprecision(10) << side << '\n';
    } else {
      long double deg = 180.0 / (double)n;
      deg = deg * PI / 180.0;

      long double res = 1.0 / sin(deg);
      cout << fixed << setprecision(10) << res << '\n';
    }
  }
  return 0;
}