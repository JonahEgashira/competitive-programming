#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n; i++)
typedef long long ll;

string S;
int N, cnt;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> S;
  for(int i = 0; i < 1000; i++){
    int c[3] = {i / 100, (i / 10) % 10, i % 10};
    int f = 0;
    for(int j = 0; j < N; j++){
      if(S[j] == ('0' + c[f])) f++;
      if(f == 3) break;
    }
    if(f == 3) cnt++;
  }
  cout << cnt << endl;
}
