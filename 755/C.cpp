#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define loop(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define cases ll T=0;cin>>T;while(T--)
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define END "\n"
#define pb push_back
#define inf 9e18
#define MOD 1000000007
#define MODU 998244353
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 100001
const string alpha = "abcdefghijklmnopqrstuvwxyz";

void dfs(vector<ll> adj[], ll node, vector<ll>& vis)
{
	vis[node] = 1;
	for (auto child : adj[node])
	{
		if (vis[child] == 0)
			dfs(adj, child, vis);
	}
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fast
	ll n;
	cin >> n;
	vector<ll> p(n);
	loop(i, n)	cin >> p[i];
	vector<ll> adj[n + 1];
	loop(i, n)	adj[p[i]].pb(i + 1) , adj[i + 1].pb(p[i]);
	vector<ll> vis(n + 1, 0);
	ll ans = 0;
	for (ll i = 1; i <= n; i++)
	{
		if (vis[i] == 0)
		{
			dfs(adj, i, vis);
			ans++;
		}
	}
	cout << ans << END;
	return 0;
}