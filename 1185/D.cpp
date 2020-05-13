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
    vector<pair<ll,ll>> b;
    ll el;
    for(ll i=0;i<n;i++)
        cin>>el , b.push_back({el,i});
    sort(b.begin(),b.end());
    if(n<=3)
    {
    	cout<<"1\n";
    }
    else
    {
    	ll diff=b[2].first-b[1].first;
    	bool flag=true;
    	for(ll i=1;i<n-1;i++)
    	{
    		if(b[i+1].first-b[i].first!=diff)
    		{
    			flag=false;
    			break;
    		}
    	}
    	if(flag)
    	{
    		cout<<b[0].second+1<<endl;
    	}
    	else
    	{
    		diff=b[2].first-b[0].first;
    		flag=true;
    		for(ll i=2;i<n-1;i++)
	    	{
	    		if(b[i+1].first-b[i].first!=diff)
	    		{
	    			flag=false;
	    			break;
	    		}
	    	}
	    	if(flag)
	    	{
	    		cout<<b[1].second+1<<endl;
	    	}
	    	else
	    	{
	    		diff=b[1].first-b[0].first;
	    		ll ansind,ctr=0;
	    		flag=true;
	    		for(ll i=1;i<n-1;i++)
	    		{
	    			if(b[i+1].first-b[i].first!=diff)
	    			{
	    				if(i+1==n-1)
	    				{
	    					ansind=n-1;
	    					ctr++;
	    					break;
	    				}
	    				else if(b[i+2].first- b[i].first==diff)
	    				{
	    					ctr++;
	    					ansind=i+1;
	    					i+=2;
	    				}
	    				else
	    				{
	    					flag=false;
	    					break;
	    				}
	    			}
	    		}
	    		// cout<<ctr<<endl;
	    		if(flag && ctr==1)
	    		{
	    			cout<<b[ansind].second+1<<"\n";
	    		}
	    		else
	    		{
	    			cout<<"-1\n";
	    		}
	    	}
    	}
    }
    return 0;
}