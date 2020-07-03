#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int long long

const int INF = 1e18;
const int MAX_V = 2510;
const int MAX_E = 5010;

int V, E, P;

struct edge {
    int from;
    int to;
    int cost;
};

edge es[MAX_E];

int d[MAX_V];
bool negative[MAX_V];

void bellman_ford(int s) {
  for (int i = 1; i <= V; i++) d[i] = INF;
  d[s] = 0;

  for (int i = 0; i < V - 1; i++) {
    for (int j = 0; j < E; j++) {
      edge e = es[j];
      if(d[e.from] != INF && d[e.from] + e.cost < d[e.to]) {
        d[e.to] = d[e.from] + e.cost;
      }
    }
  }
}

void find_negative_loop() {
  for (int i = 1; i <= V; i++) negative[i] = false;
  for (int i = 1; i <= V; i++) {
    for (int j = 0; j < E; j++) {
      edge e = es[j];
      if(d[e.to] != INF && d[e.from] + e.cost < d[e.to]) {
        d[e.to] = d[e.from] + e.cost;
        negative[e.from] = true;
      }
      if(negative[e.from]) negative[e.to] = true;
    }
  }
}

signed main() {
  cin >> V >> E >> P;

  for (int i = 0; i < E; i++) {
    int a,b,c;
    cin >> a >> b >> c;

    edge e = {a, b, P - c};
    es[i] = e;
  }

  bellman_ford(1);
  int answer = max(0LL, -d[V]);
  find_negative_loop();
  if(negative[V]) answer = -1;
  cout << answer << "\n";
}
