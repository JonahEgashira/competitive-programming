#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define int long long

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int left = 0, right = n - 1;
  string gender = "";
  int parity = 0;
  bool first = true;
  while(true) {

    int mid = (left + right)/2;

    if(first) cout << 0 << endl;
    else if(right - left <= 1) cout << right << endl;
    else cout << mid << endl;

    string input;
    cin >> input;

    if(input == "Vacant") return 0;
    if(gender == "") gender = input;

    bool flag = false;

   if((input != gender && parity == mid%2) || (input == gender && parity != mid%2))
     flag = true;

    if(first) {
      first = false;
      continue;
    }

    if(flag) {
      right = mid;
    } else {
      left = mid;
    }

  }
}