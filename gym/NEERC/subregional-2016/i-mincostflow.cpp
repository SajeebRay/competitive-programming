#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 3e3+5;

int xn, xp, xs, a[N], b[N];

struct edge {int u, v, f, w, c; };

int n, m, k, s, t, f, c, p[N], d[N], et[N];
vector<edge> e;
vector<int> g[N];

void add_edge(int u, int v, int w, int c) {
  int k = e.size();
  g[u].push_back(k);
  g[v].push_back(k+1);
  e.push_back({ u, v, 0,  w, c });
  e.push_back({ v, u, 0, -w, 0 });
}

void min_cost_max_flow() {
  f = 0, c = 0;
  while (f < k) {
    memset(et, 0, n * sizeof et[0]);
    memset(d, 63, n * sizeof d[0]);
    deque<int> q;
    q.push_back(s), d[s] = 0;

    while (!q.empty()) {
      int u = q.front(); q.pop_front();
      et[u] = 2;

      for(int i : g[u]) {
        edge &dir = e[i];
        int v = dir.v;
        if (dir.f < dir.c and d[u] + dir.w < d[v]) {
          d[v] = d[u] + dir.w;
          if (et[v] == 0) q.push_back(v);
          else if (et[v] == 2) q.push_front(v);
          et[v] = 1;
          p[v] = i;
        }
      }
    }

    if (d[t] >= INF) break;

    int inc = k - f;
    for (int u=t; u != s; u = e[p[u]^1].v) {
      edge &dir = e[p[u]];
      inc = min(inc, dir.c - dir.f);
    }

    for (int u=t; u != s; u = e[p[u]^1].v) {
      edge &dir = e[p[u]], &rev = e[p[u]^1];
      dir.f += inc;
      rev.f -= inc;
      c += inc * dir.w;
    }

    f += inc;
  }
}

int main() {
  scanf("%d%d%d", &xn, &xp, &xs);
  for (int i = 1; i <= xn; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= xn; ++i) scanf("%d", &b[i]);

  for (int i = 1; i <= xn; ++i) {
    add_edge(0, i, 1, 1);
    add_edge(i, xn+1, 3001-a[i], 1);
    add_edge(i, xn+2, 3001-b[i], 1);
  }
  add_edge(xn+1, xn+3, 1, xp);
  add_edge(xn+2, xn+3, 1, xs);

  n = xn+4;
  s = 0; t = xn+3;
  k = INF;
  min_cost_max_flow();

  int ans = 0;
  vi sp, ss;
  for (auto ed : e) if (ed.f == 1) {
    if (ed.u < 1 or ed.u > xn) continue;

    ans += 3001-ed.w;
    if (ed.v == xn+2) ss.pb(ed.u);
    else sp.pb(ed.u);
  }

  printf("%d\n", ans);
  for (auto u : sp) printf("%d ", u); printf("\n");
  for (auto u : ss) printf("%d ", u); printf("\n");

  return 0;
}
