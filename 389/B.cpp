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
	char str[n+1][n];
	ll hashcount=0;
	for(ll i=0;i<n;i++)
	{
		cin>>str[i];
		for(ll j=0;j<n;j++)
		{
			if(str[i][j]=='#')
				hashcount++;
		}
	}
	if(hashcount==0)
	{
		cout<<"YES\n";
	}
	else if(hashcount%5==0)
	{
		unordered_map<ll,ll> check;
		bool flag=true;
		for(ll i=1;i<n-1;i++)
		{
			for(ll j=1;j<n-1;j++)
			{
				
				if(str[i][j]=='#' && check[i*n+j]==0)
				{
					if(str[i+1][j]=='#' && str[i-1][j]=='#' && str[i][j+1]=='#' && str[i][j-1]=='#')
					{
						if(check[(i+1)*n+j]==0 && check[(i-1)*n+j]==0 && check[i*n+j+1]==0 && check[i*n+j-1]==0)
						{
							check[i*n+j]=1;
							check[(i+1)*n+j]=1;
							check[(i-1)*n+j]=1;
							check[i*n+j+1]=1;
							check[i*n+j-1]=1;
						}
					}
				}
			}
		}
		for(ll i=0;i<n;i++)
		{
			for(ll j=0;j<n;j++)
			{
				if(str[i][j]=='#')
				{
					if(check[i*n+j]==0)
					{
						flag=false;
						break;
					}
				}
			}
		}
		if(flag)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	else
	{
		// cout<<"Yo Boi\n";
		cout<<"NO\n";
	}
	return 0;
}