#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1000000007;

struct mint {
    ll x;

    mint(ll x = 0) : x((x % mod + mod) % mod) {}

    mint operator-() const { return mint(-x); }

    mint &operator+=(const mint a) {
      if ((x += a.x) >= mod) x -= mod;
      return *this;
    }

    mint &operator-=(const mint a) {
      if ((x += mod - a.x) >= mod) x -= mod;
      return *this;
    }

    mint &operator*=(const mint a) {
      (x *= a.x) %= mod;
      return *this;
    }

    mint operator+(const mint a) const {
      mint res(*this);
      return res += a;
    }

    mint operator-(const mint a) const {
      mint res(*this);
      return res -= a;
    }

    mint operator*(const mint a) const {
      mint res(*this);
      return res *= a;
    }

    mint pow(ll t) const {
      if (!t) return 1;
      mint a = pow(t >> 1);
      a *= a;
      if (t & 1) a *= *this;
      return a;
    }

    mint inv() const {
      return pow(mod - 2);
    }

    mint &operator/=(const mint a) {
      return (*this) *= a.inv();
    }

    mint operator/(const mint a) const {
      mint res(*this);
      return res /= a;
    }
};

mint table[2020];

void init(){
  table[0] = table[1] = 1;
  for (ll i = 2; i < 2020; i++) {
    table[i] = table[i - 1] * i;
  }
}

int main() {
  int n,k;
  cin >> n >> k;

  init();

  for (int c = 1; c <= k; c++) {
    if(n - k + 1 - c < 0) {
      cout << 0 << '\n';
      continue;
    }
    mint ans = 0;
    mint b = table[k - 1] / table[c - 1] / table[k - 1 - (c - 1)];
    mint a = table[n - k + 1] / table[n - k + 1 - c] / table[c];
    ans = a * b;
    cout << ans.x << '\n';
  }
  return 0;
}