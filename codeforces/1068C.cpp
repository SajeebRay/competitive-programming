// @subject: 
// @diff: 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
std::mt19937_64 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

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
  #define db(x) 42
  #define dbs(x) 42
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 105;

int n, m, vis[N];
vector<pii> ans[N];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) ans[i].push_back({i, i});
  for (int u, v, i = 0; i < m; i++) {
    scanf("%d%d", &u, &v);
    int a = min(u, v), b = max(u, v);
    int p = a*200+b;
    ans[u].push_back({ u, p });
    ans[v].push_back({ v, p });
  }

  for (int i = 1; i <= n; i++) {
    printf("%d\n", (int)ans[i].size());
    for (pii x : ans[i]) printf("%d %d\n", x.st, x.nd);
  }

  return 0;
}
