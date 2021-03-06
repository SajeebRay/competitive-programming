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
const int N = 1e5+5;

int n, l, v0, v1, k;

int main() {
  scanf("%d%d%d%d%d", &n, &l, &v0, &v1, &k);
  if (k >= n) return 0*printf("%.9f\n", l / double(v1));

  ld c = ceil(n/ld(k)) - 1;
  ld s = v0+v1;
  ld y = (l*s) / (v1*s + 2*c*v0*v1);
  ld t = y + 2*y*c*v1/s;

  printf("%.9f\n", (double)t);

  return 0;
}
