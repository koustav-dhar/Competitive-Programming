#include <bits/stdc++.h>
using namespace std;
bool dfs(int node, int c, vector<int> v[], int vis[], int col[])
{
	vis[node]=1;
	col[node]=c;
	for(int child:v[node])
	{
		if(vis[child]==0)
		{
			if(dfs(child,c^1,v,vis,col)==false)
				return false;
		}
		else
		{
			if(col[node]==col[child])
				return false;
		}
	}
	return true;
}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n,m;
		cin>>n>>m;
		vector<int> v[n+1];
		int vis[n+1]={0},col[n+1];
		int a,b;
		for(int j=0;j<m;j++)
		cin>>a>>b , v[a].push_back(b) , v[b].push_back(a);
		int flag=1;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==0)
			{
				if(dfs(i,1,v,vis,col)==false)
				{
					flag=0;
					break;
				}
			}
		}
		if(flag)
		{
			cout<<"Scenario #"<<i<<":\nNo suspicious bugs found!\n";
		}
		else
		{
			cout<<"Scenario #"<<i<<":\nSuspicious bugs found!\n";
		}
	}
	return 0;
