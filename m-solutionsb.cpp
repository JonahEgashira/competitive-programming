#include <iostream>
using namespace std;

int main() {
  int a,b,c,k;
  cin >> a >> b >> c >> k;

  bool flag = false;
  bool a_b = false;
  bool b_c = false;

  while(true) {
    if(a < b) {
      a_b = true;
    }
    if(a_b && b < c) {
      b_c = true;
    }
    if(a_b && b_c) {
      flag = true;
      break;
    }

    if(k == 0) {
      break;
    }

    if(!a_b) {
      b *= 2;
    }
    if(a_b && !b_c) {
      c *= 2;
    }
    k--;
  }

  if(flag) cout << "Yes" << '\n';
  else cout << "No" << '\n';

  return 0;
}