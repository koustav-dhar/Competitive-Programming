#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    string s;
    cin>>s;
    vector<ll> precompute[26];
    for(ll i=0;i<26;i++)
    	for(ll j=0;j<n;j++)
    		precompute[i].push_back(0);
    precompute[s[0]-97][0]=1;
    for(ll i=1;i<n;i++)
    {
    	
    	precompute[s[i]-97][i]++;
    	for(ll j=0;j<26;j++)
    	{
    		precompute[j][i]+=precompute[j][i-1];
    	}
    }
    ll q;
    cin>>q;
    while(q--)
    {
    	string str;
    	cin>>str;
    	set<char> alphas;
    	unordered_map<char,ll> alphacount;
    	for(ll i=0;str[i]!='\0';i++)
    	{
    		alphas.insert(str[i]);
    		alphacount[str[i]]++;
    	}
    	ll ans=-1;
    	for(auto x:alphas)
    	{
    		vector<ll>::iterator low;
    		low=lower_bound(precompute[x-97].begin(),precompute[x-97].end(),alphacount[x]);
    		ans=max(ans,ll(low-precompute[x-97].begin()));
    	}
    	cout<<ans+1<<endl;
    }
    return 0;
}