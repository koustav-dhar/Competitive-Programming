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
#define MAXN 100001 
ll spf[MAXN]; 
void sieve() 
{ 
    spf[1] = 1; 
    for (ll i=2; i<MAXN; i++) 
        spf[i] = i; 
    for (ll i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
    for (ll i=3; i*i<MAXN; i++) 
    { 
        if (spf[i] == i) 
        { 
            for (ll j=i*i; j<MAXN; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
ll binarySearch(ll arr[], ll l, ll r, ll x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
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
    ll gcd = gcdExtended(b%a, a, &x1, &y1); 
    *x = y1 - (b/a) * x1; 
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
        ll res = (x%m + m) % m; 
        return res;
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
ll modinvfermat(ll a,ll m)
{
    return binexp(a,m-2,m);
}
ll nCrModPFermat(ll n, ll r, ll p) 
{ 
    if (r==0) 
      return 1; 
    ll fac[n+1]; 
    fac[0] = 1; 
    for (ll i=1 ; i<=n; i++) 
        fac[i] = fac[i-1]*i%p; 
    return (fac[n]* modinvfermat(fac[r], p) % p * modinvfermat(fac[n-r], p) % p) % p; 
} 
void SieveOfEratosthenes(ll n) 
{ 
	bool prime[n+1]; 
	memset(prime, true, sizeof(prime)); 
	for (ll p=2; p*p<=n; p++) 
	{ 
		if (prime[p] == true) 
		{ 
			for (int i=p*p; i<=n; i += p) 
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


void phi_1_to_n(int n) {
    vector<ll> phi(n + 1);
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
// bool check(string s, ll mid)
// {
// 	ll j=s.length()-1;
// 	bool flag=true;
// 	ll ctr=0;
// 	while(j>0)
// 	{
// 		if(s[j]=='R')
// 		{
// 			ctr=0;
// 			if(j<=mid)
// 				return true;
			
// 		}
// 		else
// 		{
// 			ctr++;
// 			if(ctr>=mid)
// 				return false;
// 		}
// 		j--;
// 	}
// 	return true;
// 	while(j>0)
// 	{
// 		for(ll i=j;i>j-mid;i--)
// 		{
// 			if(s[i]=='R')
// 			{
// 				j=i;
// 			}
// 			if(j==mid && s[j]=='R')
// 			{
// 				return true;
// 			}
// 		}
// 		if(j<mid)
// 		{
// 			return true;
// 		}
// 		else
// 			return false;
// 	}
// }
signed main()
{
    fast
    ll t;
    cin>>t;
    while(t--)
    {
    	string s;
    	cin>>s;
    	
    	ll n=s.length();
		char res[n+2];
    	for(ll i=0;i<n+2;i++)
    	{
    		if(i==0 || i==n+1)
    			res[i]='R';
    		else
    			res[i]=s[i-1];
    		// cout<<res[i];
    	}
    	ll ans=1;
    	for(ll i=0;i<n+2;i++)
    	{
    		if(res[i]=='R')
    		{
    			ll ctr=1;
    			i++;
    			while(i<n+2 && res[i]!='R')
    			{
    				// cout<<i<<":"<<ctr<<" ";
    				ctr++;
    				i++;
    			}
    			i--;
    			// cout<<i<<" ";
    			ans=max(ans,ctr);
    		}
    	}
    	// ll lo=1,hi=s.length()+1,mid,best=hi;
    	// while(lo<hi)
    	// {
    	// 	mid=(lo+hi)/2;
    	// 	if(check(s,mid))
    	// 	{
    	// 		best=mid;
    	// 		hi=mid;
    	// 	}
    	// 	else
    	// 	{
    	// 		lo=mid+1;
    	// 	}
    	// }
    	cout<<ans<<END;
    }
    return 0;
}