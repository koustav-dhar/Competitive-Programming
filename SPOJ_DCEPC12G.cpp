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
#define MAXN 10000001
const string alpha = "abcdefghijklmnopqrstuvwxyz";
bool prime[MAXN];
vector<ll> countprimes(MAXN);
void SieveOfEratosthenes(ll n)
{
	memset(prime, true, sizeof(prime));
	for (ll p = 2; p * p <= n; p++)
	{
		if (prime[p] == true)
		{
			for (ll i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}
	for (ll i = 2; i <= n; i++)
	{
		if (prime[i])
			countprimes[i]++;
		countprimes[i] += countprimes[i - 1];
	}
}
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
ll binexp(ll a, ll b, ll m) {
	a %= m;
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}
vector<ll> fact(MAXN, 1);
void factcalc(ll n)
{
	FOR(i, 2, n)
	{
		fact[i] = (fact[i - 1] * i) % (MOD - 1);
	}
}
signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fast
	phi_1_to_n(MAXN - 1);
	SieveOfEratosthenes(MAXN - 1);
	factcalc(MAXN - 1);
	ll t;
	cin >> t;
	FOR(x, 1, t)
	{
		ll n;
		cin >> n;
		if (countprimes[n] <= phi[n])
			cout << phi[n] % MOD << END;
		else
		{
			cout << binexp(phi[n], fact[countprimes[n] - phi[n]], MOD) << END;
		}
	}
	return 0;
} 
