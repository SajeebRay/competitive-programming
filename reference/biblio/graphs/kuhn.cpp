// Kuhn (Bipartite Matching) O(VE)
int x, vis[N], b[n], ans;

bool match(int u) {
  if (vis[u]==x) return 0;
  vis[u] = x;
  for (int v : adj[u])
    if (!b[v] or match(b[v])) return b[v]=u;
  return 0;
}

for (int i = 1; i <= n; ++i) ++x, ans+=match(i);
