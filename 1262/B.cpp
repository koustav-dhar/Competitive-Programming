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
#define MOD 1000000007
#define MODU 998244353
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 100001
const string alpha = "abcdefghijklmnopqrstuvwxyz";

signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fast
	ll t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		vector<ll> q(n);
		loop(i, n)	cin >> q[i];
		vector<ll> p(n), help;
		FOR(i, 1, n)
		{
			help.pb(i);
		}
		p[0] = q[0];
		vector<ll>::iterator beg;
		beg = lower_bound(help.begin(), help.end(), p[0]);
		help.erase(beg);
		bool flag = true;
		FOR(i, 1, n - 1)
		{
			if (q[i] > q[i - 1])
			{
				p[i] = q[i];
				vector<ll>::iterator low;
				low = lower_bound(help.begin(), help.end(), p[i]);
				help.erase(low);
			}
			else
			{
				if (p[i - 1] == 1)
				{
					cout << -1 << END;
					flag = false;
					break;
				}
				else
				{
					vector<ll>::iterator low;
					low = lower_bound(help.begin(), help.end(), p[i - 1]);
					if (low == help.begin())
					{
						cout << -1 << END;
						flag = false;
						break;
					}
					--low;
					p[i] = *low;
					help.erase(low);
				}
			}
		}
		if (flag)
		{
			loop(i, n)	cout << p[i] << " ";
			cout << END;
		}
	}
	return 0;
}