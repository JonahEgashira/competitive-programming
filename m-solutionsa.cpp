#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int answer = 0;
  if(n <= 599) {
    answer = 8;
  } else if(n <= 799) {
    answer = 7;
  } else if(n <= 999) {
    answer = 6;
  } else if(n <= 1199) {
    answer = 5;
  } else if(n <= 1399) {
    answer = 4;
  } else if(n <= 1599) {
    answer = 3;
  } else if(n <= 1799) {
    answer = 2;
  } else if(n <= 1999) {
    answer = 1;
  }
  cout << answer << '\n';

  return 0;
}