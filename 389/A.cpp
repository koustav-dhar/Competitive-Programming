#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin>>n;
	vector<ll> x(n);
	for(ll i=0;i<n;i++)
		cin>>x[i];
	// sort(x.begin(),x.end());
	// reverse(x.begin(),x.end());
	ll ans=x[0];
	for(ll i=1;i<n;i++)
	{
		ans =__gcd(ans, x[i]);
	}
	cout<<n*ans<<"\n";
	return 0;
}