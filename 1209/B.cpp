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

ll lcm(ll a, ll b)
{
	return ((1LL * a * b) / (__gcd(a, b)));
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fast
	ll n;
	cin >> n;
	string s;
	cin >> s;
	vector<ll> a(n), b(n);
	ll iter = 1, maxstart = -1;
	loop(i, n)	cin >> a[i] >> b[i] , maxstart = max(maxstart, b[i]) , iter = lcm(iter, 2 * a[i]);
	iter *= 10;
	vector<ll> track(iter + 1, 0);
	FOR(i, 0, iter)
	{
		loop(j, n)
		{
			if (s[j] == '1')
			{
				if (i >= b[j])
				{
					if ((i - b[j]) % (2 * a[j]) >= a[j])
					{
						track[i]++;
					}
				}
				else
				{
					track[i]++;
				}
			}
			else
			{
				if (i >= b[j])
				{
					if ((i - b[j]) % (2 * a[j]) < a[j])
					{
						track[i]++;
					}
				}
			}
		}
	}
	ll ans = INT_MIN;
	FOR(i, 0, iter)
	{
		ans = max(ans, track[i]);
	}
	cout << ans << END;
	return 0;
}