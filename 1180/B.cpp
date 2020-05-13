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
	vector<ll> a(n);
	loop(i, n)	cin >> a[i];
	if (n % 2 == 0)
	{
		loop(i, n)
		{
			if (a[i] >= 0)
			{
				cout << (-1)*a[i] - 1 << " ";
			}
			else
			{
				cout << a[i] << " ";
			}
		}
	}
	else
	{
		loop(i, n)
		{
			if (a[i] >= 0)
			{
				a[i] = (-1) * a[i] - 1;
			}
		}
		ll maxneg = INT_MAX, ind = -1;
		loop(i, n)
		{
			if (a[i] < maxneg)
			{
				maxneg = a[i];
				ind = i;
			}
		}
		loop(i, n)
		{
			if (i == ind)
			{
				cout << (-1)*a[i] - 1 << " ";
			}
			else
				cout << a[i] << " ";
		}
	}
	return 0;
}