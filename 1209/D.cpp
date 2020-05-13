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
#define END "\n"
#define pb push_back
#define all(v) v.begin(),v.end()
#define MOD 1000000007
#define MODU 998244353
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 100001
const string alpha = "abcdefghijklmnopqrstuvwxyz";

vector<ll> adj[MAXN];
ll vis[MAXN] = {0};
map<pair<ll, ll>, ll> flag;
ll cycles = 0;
void dfs(ll node, ll par)
{
	vis[node] = 1;
	for (auto child : adj[node])
	{
		if (vis[child] == 0)
		{
			dfs(child, node);
		}
		else
		{
			if (child != par)
			{
				if (flag[ {node, child}] == 0 && flag[ {child, node}] == 0)
				{
					// cout << "#DEBUG#>>" << node << " -> " << child << " is a back-edge\n";
					cycles++;
					flag[ {child, node}] = 1;
				}
			}
		}
	}
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fast
	ll n, k;
	cin >> n >> k;
	map<pair<ll, ll>, ll> ctr;
	ll ans = 0;
	loop(i, k)
	{
		ll x, y;
		cin >> x >> y;
		if (ctr[ {x, y}] == 1 || ctr[ {y, x}] == 1)
		{
			ans++;
		}
		else
		{
			adj[x].pb(y);
			adj[y].pb(x);
			ctr[ {x, y}] = 1;
		}
	}
	FOR(i, 1, n)
	{
		if (vis[i] == 0)
		{
			dfs(i, -1);
		}
	}
	cout << ans + cycles << END;
	return 0;
}