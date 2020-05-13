#include <bits/stdc++.h>
using namespace std;
#define MAXN 44750
#define MOD 1000000007
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    ll a[n][2];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i][0]>>a[i][1];
    }
    
    set<ll> pfactors;
    for(ll i=2;i<=sqrt(a[0][0]);i++)
    {
        while(a[0][0]%i==0)
        {
            a[0][0]/=i;
            pfactors.insert(i);
        }
    }
    if(a[0][0]!=1)  pfactors.insert(a[0][0]);
    for(ll i=2;i<=sqrt(a[0][1]);i++)
    {
        while(a[0][1]%i==0)
        {
            a[0][1]/=i;
            pfactors.insert(i);
        }
    }
    if(a[0][1]!=1)  pfactors.insert(a[0][1]);
    bool flag=false;
    ll ans=-1;
    for(auto itr:pfactors)
    {
        ll ctr=0;
        for(ll i=1;i<n;i++)
        {
            if((a[i][0]%itr==0) || (a[i][1]%itr==0))
            {
                ctr++;    
            }
        }
        if(ctr==n-1)
        {
            flag=true;
            ans=itr;
            break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}