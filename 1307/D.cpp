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
#define MAXN 200002
const string alpha = "abcdefghijklmnopqrstuvwxyz";

vector<ll> adj[MAXN], a, track1(MAXN, -1), trackn(MAXN, -1);
ll vis[MAXN] = {0};
vector<ll> dis[MAXN];
// void dfs(ll node, ll dist)
// {
// 	vis[node] = 1;
// 	dis[dist].pb(node);
// 	track[node] = dist;
// 	for (auto child : adj[node])
// 	{
// 		if (vis[child] == 0)
// 		{
// 			dfs(child, dist + 1);
// 		}
// 	}
// }

void bfs(ll node, ll dis, vector<ll>& dist)
{
	dist[node] = dis;
	queue<ll> q;
	q.push(node);
	while (!q.empty())
	{
		ll el = q.front();
		q.pop();
		for (auto child : adj[el])
		{
			if (dist[child] == -1)
			{
				dist[child] = dist[el] + 1;
				q.push(child);
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
	ll n, m, k, x, y;
	cin >> n >> m >> k;
	loop(i, k)	cin >> x , a.pb(x);
	loop(i, m)	cin >> x >> y , adj[x].pb(y) , adj[y].pb(x);
	bfs(1, 0, track1);
	// FOR(i, 1, n)	vis[i] = 0;
	bfs(n, 0, trackn);
	// FOR(i, 1, n)	cout << track1[i] << " ";
	// cout << END;
	// FOR(i, 1, n)	cout << trackn[i] << " ";
	// cout << END;
	vector<pair<ll, ll>> order;
	loop(i, k)	order.pb({track1[a[i]] - trackn[a[i]], a[i]});
	sort(all(order));
	// for (auto itr = order.begin(); itr != order.end(); itr++)
	// {
	// 	cout << itr->ss << " : " << itr->ff << END;
	// }
	ll best = 0, maxm = INT_MIN;
	for (auto itr = order.begin(); itr < order.end() - 1; itr++)
	{
		maxm = max(maxm, track1[itr->ss]);
		best = max(best, maxm + trackn[(itr + 1)->ss]);
	}
	cout << min(track1[n], best + 1) << END;
	return 0;
}