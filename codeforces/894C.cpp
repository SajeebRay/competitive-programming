#include <bits/stdc++.h>
using namespace std;

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
  #define db(x)
  #define dbs(x)
#endif

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e3+5, M = 1e6+5;

int n, a[N];
vi v;

int main() {
  scanf("%d", &n);
  int ok = 1;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    ok = ok && (a[i]%a[0]==0);
  }

  if (ok) {
    printf("%d\n", 2*n+1);
    for (int i = 0; i < n; i++) printf("%d %d ", a[0], a[i]);
    printf("%d\n", a[0]);
  } else printf("-1\n");

  return 0;
}
