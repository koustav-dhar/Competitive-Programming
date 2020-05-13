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
		string s;
		cin >> s;
		vector<ll> col(n);
		bool checking = false;
		loop(x, 10)
		{
			vector<ll> check;
			loop(i, n)	col[i] = 0;
			bool flag = false;
			loop(i, s.length())
			{
				if (flag)
				{
					if (ll(s[i]) - 48 <= x)
					{
						col[i] = 1;
					}
					else
					{
						col[i] = 2;
					}
				}
				else
				{
					if (ll(s[i]) - 48 < x)
					{
						col[i] = 1;
					}
					else if (ll(s[i]) - 48 > x)
					{
						col[i] = 2;
						flag = true;
					}
				}
			}
			loop(i, n)
			{
				if (col[i] == 0)
				{
					col[i] = 2;
				}
			}
			loop(i, n)
			{
				if (col[i] == 1)
				{
					check.pb(ll(s[i]) - 48);
				}
			}
			loop(i, n)
			{
				if (col[i] == 2)
				{
					check.pb(ll(s[i]) - 48);
				}
			}
			flag = true;
			loop(i, n - 1)
			{
				if (check[i + 1] < check[i])
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				loop(i, n)	cout << col[i];
				cout << END;
				checking = true;
				break;
			}
		}
		if (!checking)
			cout << "-\n";
	}
	return 0;
}