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

int n, x, a[3];

int main() {
  scanf("%d%d", &n, &x);
  n = n%6;

  for (int i = 0; i < 3; ++i) a[i] = i;
  for (int i = 1; i <= n; ++i) swap(a[1], a[2-2*(i&1)]);
  printf("%d\n", a[x]);

  return 0;
}
