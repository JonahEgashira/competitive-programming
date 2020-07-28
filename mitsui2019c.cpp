#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  int x;
  cin >> x;

  int hundred = x / 100;
  int have = hundred * 5;
  int need = x - hundred * 100;

  if(have >= need) {
    cout << 1 << endl;
  } else {
    cout << 0 << endl;
  }
}
