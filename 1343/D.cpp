#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main()
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
    	vector<ll> a(n);
    	unordered_map<ll,ll> hash;
    	for(ll i=0;i<n;i++)
    		cin>>a[i];
    	vector<ll> prefixtrick(2*k+1);
    	vector<pair<ll,ll>> ranges(n/2);
    	for(ll i=0;i<n/2;i++)
    	{
    		hash[a[i]+a[n-i-1]]++;
    		ranges[i]={min(a[i],a[n-i-1])+1, max(a[i],a[n-i-1])+k};
    	}
    	for(ll i=0;i<prefixtrick.size();i++)
    		prefixtrick[i]=0;
    	for(ll i=0;i<ranges.size();i++)
		{
			prefixtrick[ranges[i].first-1]+=1;
			prefixtrick[ranges[i].second]-=1;
		}
		for(ll i=1;i<prefixtrick.size();i++)
		{
			prefixtrick[i]+=prefixtrick[i-1];
		}
		ll ans=INT_MAX;
		for(ll x=2;x<=2*k;x++)
		{
			ll val0=hash[x],val1,val2;
			val1=prefixtrick[x-1]-val0;
			val2=(n/2-val0-val1);
			ans=min(ans,val1+2*val2);
		}
		cout<<ans<<endl;
    }
    return 0;
}