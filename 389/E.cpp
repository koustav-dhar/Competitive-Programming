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
	ll n;
	cin >> n;
	vector<vector<ll>> v(n);
	ll moves = 0;
	loop(i, n)
	{
		ll s, el;
		cin >> s;
		moves += s;
		loop(j, s)	cin >> el , v[i].pb(el);
	}
	bool flag = true;
	ll ciel = 0, jiro = 0;
	while (moves > 0)
	{
		if (flag)
		{
			ll maxel = INT_MIN, ind = 0;
			loop(i, n)
			{
				if (!v[i].empty())
				{
					if (v[i][0] > maxel)
					{
						maxel = v[i][0];
						ind = i;
					}
				}
			}
			ciel += maxel;
			v[ind].erase(v[ind].begin());
			flag = false;
			moves--;
		}
		else
		{
			ll maxel = INT_MIN, ind = 0;
			loop(i, n)
			{
				if (!v[i].empty())
				{
					if (v[i][v[i].size() - 1] > maxel)
					{
						maxel = v[i][v[i].size() - 1];
						ind = i;
					}
				}
			}
			jiro += maxel;
			v[ind].erase(v[ind].end() - 1);
			flag = true;
			moves--;
		}
	}
	cout << ciel << " " << jiro << END;
	return 0;
}