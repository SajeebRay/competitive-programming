// @subject: grundy
// @diff: med

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
const int N = 1e2+5;

int g[N][N], n;

int main() {
  for (int i = 1; i < N; i++) for (int j = 1; j < N; j++) {
    int k[400] = {};
    for (int u = 1; u < i; u++) if (i - u != j) k[g[i-u][j]]=1;
    for (int u = 1; u < j; u++) if (i != j - u) k[g[i][j-u]]=1;
    for (int u = 1; u < min(i, j); u++) k[g[i-u][j-u]]=1;
    int mex = 0;
    for (; k[mex]; mex++) ;
    g[i][j] = mex;
  }

  int xr = 0;

  scanf("%d", &n);
  for (int u, v, i = 0; i < n; i++) {
    scanf("%d%d", &u, &v);
    if (u == v) return !printf("Y\n");
    xr ^= g[u][v];
  }

  printf("%c\n", xr ? 'Y' : 'N');

  return 0;
}
