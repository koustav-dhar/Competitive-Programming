#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int c[n];
		vector<int> v[n];
		for(int i=0;i<n;i++)
		{
			cin>>c[i];
			for(int j=0;j<c[i];j++)
			{
				int el;
				cin>>el;
				v[i].push_back(el);
			}
		}
		unordered_map<int,int> m;
		int flag=0,pos=0;
		for(int i=0;i<n;i++)
		{
			flag=0;
			for(int j=0;j<c[i];j++)
			{
				if(m[v[i][j]]==0)
				{
					m[v[i][j]]=1;
					flag=1;
					break;
				}
			}
			if(flag==0)
				pos=i+1;
		}
		int check=0;
		for(int i=1;i<=n;i++)
		{
			check+=m[i];
		}
		if(check<n)
		{
			cout<<"IMPROVE"<<endl;
			for(int i=1;i<=n;i++)
			{
				if(m[i]==0)
				{
					cout<<pos<<" "<<i<<endl;
					break;
				}
			}
		}
		else
		{
			cout<<"OPTIMAL"<<endl;
		}
	}
	return 0;
}