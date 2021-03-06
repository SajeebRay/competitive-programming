// @subject: 
// @diff: 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define gcd(x,y) __gcd((x),(y))

#ifndef ONLINE_JUDGE
  #define db(x) cerr << #x << " == " << x << endl
  #define dbs(x) cerr << x << endl
  #define _ << ", " <<
#else
  #define db(x) ((void)0)
  #define dbs(x) ((void)0)
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 2e5+5;

int c, p, x, l, cnt[N], sz[N], out[N];
vector<int> adj[N];

int main() {
  scanf("%d%d%d%d", &c, &p, &x, &l);
  for (int a, b, i = 0; i < p; i++) {
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
    cnt[a]++; sz[a]++;
    cnt[b]++; sz[b]++;
  }

  queue<int> q;
  out[l] = 1;
  q.push(l);

  while (q.size()) {
    int u = q.front(); q.pop();

    for (int v : adj[u]) if (!out[v]) {
      cnt[v]--;
      if (2*cnt[v] <= sz[v]) {
        q.push(v);
        out[v] = 1;
      }
    }
  }

  printf("%s\n", out[x] ? "leave" : "stay");

  return 0;
}
