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
#define all(v) v.begin(),v.end()
#define END "\n"
#define pb push_back
#define MOD 1000000007
#define MODU 998244353
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN 1000001
const string alpha = "abcdefghijklmnopqrstuvwxyz";
 
vector<ll> phi(MAXN);
 
void phi_1_to_n(ll n) {
	phi[0] = 0;
	phi[1] = 1;
	for (ll i = 2; i <= n; i++)
		phi[i] = i;
 
	for (ll i = 2; i <= n; i++) {
		if (phi[i] == i) {
			for (ll j = i; j <= n; j += i)
				phi[j] -= phi[j] / i;
		}
	}
}
vector<ll> ans(MAXN);
void gcdextreme(ll n)
{
	for (ll i = 1; i <= n; i++)
	{
		for (ll j = i; j <= n; j += i)
		{
			ans[j] += phi[i] * j / i;
		}
	}
	for (ll i = 2; i <= n; i++)
	{
		ans[i] += ans[i - 1];
	}
}
 
signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fast
	phi_1_to_n(MAXN - 1);
	gcdextreme(MAXN - 1);
	while (1)
	{
		ll n;
		cin >> n;
		if (n == 0)
			return 0;
		else
			cout << ans[n] - n*(n + 1) / 2 << END;
	}
	return 0;
} 
