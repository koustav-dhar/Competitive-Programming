#include <bits/stdc++.h>
using namespace std;
void dfs(int node, int vis[], vector<int> v[])
{
	vis[node]=1;
	for(int child:v[node])
	{
		if(vis[child]==0)
			dfs(child, vis, v);
	}
}
int main() {
	// your code goes here
	int n,m;
	cin>>n>>m;
	vector<int> v[n+1];
	int a,b;
	for(int i=0;i<n;i++)
	cin>>a>>b , v[a].push_back(b) , v[b].push_back(a);
	if(m==n-1)
	{
		int vis[n+1]={0};
		int cc=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==0)
			{
				dfs(i, vis, v);
				cc++;
			}
		}
		if(cc==1)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	else
	{
		cout<<"NO\n";
	}
	return 0;
