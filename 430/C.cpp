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
#define go(c,itr) for(auto itr=(c).begin(); itr!=(c).end(); itr++)
#define back(c,itr) for(auto itr=(c).rbegin(); itr!=(c).rend(); itr++)
#define END "\n"
#define pb push_back
#define inf 9e18
#define MOD 1000000007
#define MODU 998244353
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 100001
const string alpha = "abcdefghijklmnopqrstuvwxyz";
vector<ll> adj[MAXN];
vector<ll> init(MAXN), goal(MAXN), ans;

void addedge()
{
	ll a, b;
	cin >> a >> b;
	adj[a].pb(b);
	adj[b].pb(a);
}

void dfs(ll node, ll parent, ll level, ll odd, ll even)
{
	if (level % 2 == 0 && even % 2 == 1)	init[node] = init[node] ^ 1;
	else if (level % 2 == 1 && odd % 2 == 1)	init[node] = init[node] ^ 1;
	if (init[node] != goal[node])
	{
		ans.pb(node);
		if (level % 2 == 0)
			even++;
		else
			odd++;
	}
	for (auto child : adj[node])
	{
		if (child == parent)
			continue;
		dfs(child, node, level + 1, odd, even);
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
	loop(i, n - 1)	addedge();
	FOR(i, 1, n)	cin >> init[i];
	FOR(i, 1, n)	cin >> goal[i];
	dfs(1, -1, 0, 0, 0);
	cout << ans.size() << END;
	go(ans, itr)	cout << *itr << END;
	return 0;
}