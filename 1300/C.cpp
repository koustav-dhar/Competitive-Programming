#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define LOOP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define ff first
#define ss second
#define END "\n"
#define pb push_back
#define MOD 1000000007
#define MODU 998244353
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN   100001
ll spf[MAXN];
void sieve()
{
    spf[1] = 1;
    for (ll i = 2; i < MAXN; i++)
        spf[i] = i;

    for (ll i = 4; i < MAXN; i += 2)
        spf[i] = 2;

    for (ll i = 3; i * i < MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (ll j = i * i; j < MAXN; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}
ll binarySearch(ll arr[], ll l, ll r, ll x)
{
    if (r >= l) {
        ll mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}
ll BitCount(ll u)
{
    ll uCount;

    uCount = u - ((u >> 1) & 033333333333) - ((u >> 2) & 011111111111);
    return ((uCount + (uCount >> 3)) & 030707070707) % 63;
}
ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}
ll modInverse(ll a, ll m)
{
    ll x, y;
    ll g = gcdExtended(a, m, &x, &y);
    if (g != 1)
        return -1;
    else
    {
        ll res = (x % m + m) % m;
        return res;
    }
}
ll binexp(ll a, ll b, ll m=1e18) {
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
ll modinvfermat(ll a, ll m)
{
    return binexp(a, m - 2, m);
}
ll nCrModPFermat(ll n, ll r, ll p)
{
    if (r == 0)
        return 1;
    ll fac[n + 1];
    fac[0] = 1;
    for (ll i = 1 ; i <= n; i++)
        fac[i] = fac[i - 1] * i % p;
    return (fac[n] * modinvfermat(fac[r], p) % p * modinvfermat(fac[n - r], p) % p) % p;
}
void SieveOfEratosthenes(ll n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    for (ll p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}
ll ncr(ll n, ll r)
{
    ll p = 1, k = 1;
    if (n - r < r)
        r = n - r;
    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
            ll m = __gcd(p, k);
            p /= m;
            k /= m;
            n--;
            r--;
        }
    }
    else
        p = 1;
    return p;
}
struct answer{
	ll val;
	ll individuality;
	ll out;
};
bool comp(answer a, answer b)
{
	if(a.val!=b.val)
		return a.val > b.val;
	else
		return (a.individuality > b.individuality);
}
signed main() {
#ifndef ONLINE_JUDGE
	freeopen("input.txt", "r", stdin);
	freeopen("output.txt", "w", stdout);
#endif
	fast
	ll n;
	cin>>n;
	vector<ll> a(n);
	for(ll i=0;i<n;i++)
		cin>>a[i];
	vector<vector<ll>> bits(n, vector<ll>(32,0));
	unordered_map<ll,ll> bitfreq;
	for(ll i=0;i<n;i++)
	{
		ll j=0;
		ll num=a[i];
		while(num>0)
		{
			if(num%2==1)
				bitfreq[j]++;
			bits[i][j++]=num%2;
			num/=2;
		}
	}
	vector<answer> ans(n);
	for(ll i=0;i<n;i++)
	{
		ans[i].val=0;
		ll ctr=0;
		for(ll j=0;j<32;j++)
		{
			if(bits[i][j]==1 && bitfreq[j]==1)
			{
				ctr++;
				ans[i].val+=binexp(2,j);
			}
		}
		ans[i].individuality=ctr;
		ans[i].out=a[i];
	}
	sort(ans.begin(),ans.end(),comp);
	for(auto itr : ans)
	{
		cout<<itr.out<<" ";
	}
	return 0;
}