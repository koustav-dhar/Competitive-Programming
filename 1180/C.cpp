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
#define MAXN 1000001
const string alpha = "abcdefghijklmnopqrstuvwxyz";

signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fast
	ll n, q;
	cin >> n >> q;
	vector<ll> a(n + 1);
	FOR(i, 1, n)	cin >> a[i];
	vector<pair<ll, ll>> ans, ans2;
	ll maxel = INT_MIN, ind = -1;
	FOR(i, 1, n)
	{
		if (maxel < a[i])
		{
			maxel = a[i];
			ind = i;
		}
	}
	// cout << ind << END;
	deque<ll> d, di;
	FOR(i, 1, n)
	{
		d.pb(a[i]);
		di.pb(i);
	}
	ll ctr = 0;
	while (di[0] != ind)
	{
		ll temp1, temp2, i1, i2;
		temp1 = d.front();
		i1 = di.front();
		d.pop_front();
		di.pop_front();
		temp2 = d.front();
		i2 = di.front();
		d.pop_front();
		di.pop_front();
		ans.pb({temp1, temp2});
		ctr++;
		if (temp1 > temp2)
		{
			d.push_front(temp1);
			di.push_front(i1);
			d.push_back(temp2);
			di.push_back(i2);
		}
		else
		{
			d.push_back(temp1);
			di.push_back(i1);
			d.push_front(temp2);
			di.push_front(i2);
		}
	}
	// for (auto itr : ans)
	// 	cout << itr.ff << " " << itr.ss << END;
	ll ctr2 = 0;
	ctr2++;
	// ans2.pb({d[0].ss,d[1].ss});
	ll ind1 = di[0], ind2 = di[1];
	ll temp1, temp2, i1, i2;
	temp1 = d.front();
	i1 = di.front();
	d.pop_front();
	di.pop_front();
	temp2 = d.front();
	i2 = di.front();
	d.pop_front();
	di.pop_front();
	ans2.pb({temp1, temp2});
	if (temp1 > temp2)
	{
		d.push_front(temp1);
		di.push_front(i1);
		d.push_back(temp2);
		di.push_back(i2);
	}
	else
	{
		d.push_back(temp1);
		di.push_back(i1);
		d.push_front(temp2);
		di.push_front(i2);
	}
	// for (auto itr : d)
	// {
	// 	cout << itr << " ";
	// }
	// cout << END;
	// for (auto itr : di)
	// 	cout << itr << " ";
	while (!(di[0] == ind1 && di[1] == ind2))
	{
		ll temp1, temp2, i1, i2;
		temp1 = d.front();
		i1 = di.front();
		d.pop_front();
		di.pop_front();
		temp2 = d.front();
		i2 = di.front();
		d.pop_front();
		di.pop_front();
		ans2.pb({temp1, temp2});
		ctr2++;
		if (temp1 > temp2)
		{
			d.push_front(temp1);
			di.push_front(i1);
			d.push_back(temp2);
			di.push_back(i2);
		}
		else
		{
			d.push_back(temp1);
			di.push_back(i1);
			d.push_front(temp2);
			di.push_front(i2);
		}
	}
	// ans2.pop_back();
	// for (auto itr : ans2)
	// 	cout << itr.ff << " " << itr.ss << END;
	while (q--)
	{
		ll m;
		cin >> m;
		if (m > ans.size())
		{
			m -= ans.size();
			m--;
			cout << ans2[m % ans2.size()].ff << " " << ans2[m % ans2.size()].ss << END;
		}
		else
		{
			m--;
			cout << ans[m].ff << " " << ans[m].ss << END;
		}
	}
	return 0;
}