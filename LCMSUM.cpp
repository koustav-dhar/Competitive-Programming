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
#define MAXN 1000002
const string alpha = "abcdefghijklmnopqrstuvwxyz";
vector<ll> phi(MAXN);
void totient(ll n) {
	phi[0] = 0;
	phi[1] = 1;
	for (ll i = 2; i <= n; i++)
		phi[i] = i;

	for (ll i = 2; i <= n; i++) {
		if (phi[i] == i) {
			for (ll j = i; j <= n; j += i)
				phi[j] *= (i - 1) , phi[j] /= i;
		}
	}
}
vector<ll> ans(MAXN);
void lcmsum(ll n)
{
	for (ll i = 1; i <= n; i++)
	{
		for (ll j = i; j <= n; j += i)
		{
			ans[j] += phi[i] * i;
		}
	}
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fast
	ll t;
	cin >> t;
	totient(MAXN - 1);
	lcmsum(MAXN - 1);
	while (t--)
	{
		ll n;
		cin >> n;
		ll out = ans[n];
		out++;
		out *= n;
		out /= 2;
		cout << out << END;
	}
	return 0;
