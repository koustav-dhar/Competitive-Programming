#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define loop(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define END "\n"
#define pb push_back
#define MOD 1000000007
#define MODU 998244353
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 100001
const string alpha = "abcdefghijklmnopqrstuvwxyz";

vector<ll> adj[MAXN];
vector<bool> visited(MAXN, false);
vector<ll> tin(MAXN, -1), low(MAXN, -1);
ll timer = 0;
ll articulationpts = 0;
unordered_map<ll, ll> pts;
void IS_CUTPOINT(ll node)
{
	if (pts[node] == 0)
	{
		articulationpts++;
		pts[node] = 1;
	}
}
void dfs(ll v, ll p = -1) {
	visited[v] = true;
	tin[v] = low[v] = timer++;
	ll children = 0;
	for (ll to : adj[v]) {
		if (to == p) continue;
		if (visited[to]) {
			low[v] = min(low[v], tin[to]);
		} else {
			dfs(to, v);
			low[v] = min(low[v], low[to]);
			if (low[to] >= tin[v] && p != -1)
				IS_CUTPOINT(v);
			++children;
		}
	}
	if (p == -1 && children > 1)
		IS_CUTPOINT(v);
}

// void find_cutpoints() {
// 	timer = 0;
// 	visited.assign(n, false);
// 	tin.assign(n, -1);
// 	low.assign(n, -1);
// 	for (ll i = 1; i <= n; ++i) {
// 		if (!visited[i])
// 			dfs (i);
// 	}
// }
signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fast
	while (1)
	{
		ll n, m;
		cin >> n >> m;
		if (n == 0 && m == 0)
			return 0;
		else
		{
			while (m--)
			{
				ll a, b;
				cin >> a >> b;
				adj[a].push_back(b);
				adj[b].push_back(a);
			}
			timer = 0;
			FOR(i, 1, n)
			{
				if (!visited[i])
					dfs(i, -1);
			}
			cout << articulationpts << END;
		}
		FOR(i, 1, n)	adj[i].clear() , visited[i] = false , tin[i] = -1 , low[i] = -1;
		pts.clear();
		articulationpts = 0;
	}
	return 0;
