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
const int N = 1e5+5;

int n, a, v[4];

int main() {
  scanf("%d", &n);
  v[1] = v[2] = 1;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    if (!v[a]) return printf("NO\n"), 0;
    int k[4] = {};
    for (int j = 1; j <= 3; j++) k[j] = !v[j];
    k[a] = 1;
    for (int j = 1; j <= 3; j++) v[j] = k[j];
  }
  printf("YES\n");
  return 0;
}
