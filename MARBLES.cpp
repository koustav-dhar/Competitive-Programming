#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        cout<<ncr(n-1,k-1)<<endl;
    }
