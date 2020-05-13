#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define LOOP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define ff first
#define ss second
#define END "\n"
#define pb push_back
#define MOD 1000000007
#define MODU 998244353
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void bfs(vector<ll> v[], vector<ll>& dis, ll node)
{
	dis[node] = 0;
	queue<ll> q;
	q.push(node);
	while(!q.empty())
	{
		ll ele = q.front();
		q.pop();
		for(auto child : v[ele])
		{
			if(dis[child] == -1)
			{
				dis[child] = dis[ele] + 1;
				q.push(child);
			}
		}
	}
}

signed main()
{
	fast
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m,a,b,c;
		cin>>n>>m>>a>>b>>c;
		vector<ll> p(m);
		for(ll i=0;i<m;i++)
			cin>>p[i];
		sort(p.begin(),p.end());
		vector<ll> prefix(m+1);
		prefix[0]=0;
		for(ll i=0;i<m;i++)
			prefix[i+1] = p[i] + prefix[i];
		// for(ll i=0;i<=m;i++)
		// 	cout<<prefix[i]<<" ";
		// cout<<END;
		vector<ll> v[n+1];
		ll x,y;
		for(ll i=0;i<m;i++)
			cin>>x>>y , v[x].pb(y) , v[y].pb(x);
		vector<ll> disa(n+1,-1),disb(n+1,-1),disc(n+1,-1);
		bfs(v, disa, a);
		bfs(v, disb, b);
		bfs(v, disc, c);
		ll ans=1e18;
		for(ll i = 1; i <= n; i++)
		{
			if(disa[i]+disb[i]+disc[i]>m)	
				continue;
			else
			{
				// cout<<disb[b]<<END;
				ans=min(ans, prefix[disb[i]] + prefix[disa[i]+disb[i]+disc[i]]);
			}
		}
		cout<<ans<<END;
	}
	return 0;
}