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
#define MAXN 10001
const string alpha = "abcdefghijklmnopqrstuvwxyz";
vector<ll> phi(MAXN), prefix(MAXN);
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
	for (ll i = 1; i <= n; i++)
	{
		prefix[i] += phi[i] + prefix[i - 1];
	}
}
signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fast
	phi_1_to_n(MAXN - 1);
	ll t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		cout << prefix[n]*prefix[n] << END;
	}
	return 0;
