#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x) memset((x), 0, sizeof(x))
#define cli(x) memset((x), 63, sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int n, k;
int a[N], b[N];
int co;
int res = INF;

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]), co+=a[i];
  for (int i = 0; i < n; ++i) scanf("%d", &b[i]), res = min(res, b[i]/a[i]);

  for (int i = 0; i < n; ++i) b[i] -= a[i]*res;

  while (1) {
    for (int i = 0; i < n; ++i) {
      b[i] -= a[i];
      if (b[i] < 0) k += b[i], b[i] = 0;
    }
    if (k < 0) break;
    res++;
  }

  printf("%d\n", res);

  return 0;
}
