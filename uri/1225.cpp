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

const int INF = 0x3f3f3f3f, MOD = 1e9+7, EPS = 1e-6;
const int N = 1e4+5;

int n, a[N];

int main() {
  while (~scanf("%d", &n)) {
    int t = 0;
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]), t+=a[i];
    if (t%n) { printf("-1\n"); continue; }

    int d = 0;
    for (int i = 0; i < n; ++i) d += abs(t/n-a[i]);
    printf("%d\n", d/2+1);
  }
  return 0;
}
