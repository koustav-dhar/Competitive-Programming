#include <bits/stdc++.h>
using namespace std;
int ans=0;
void dfs(int node,int m,int streak[],int vis[],int col[],vector<int> v[])
{
	vis[node]=1;
	for(int child:v[node])
	{
		if(vis[child]==0)
		{
			if(col[child]==1)
				streak[child]=streak[node]+col[child];
			else
				streak[child]=0;
			if(streak[child]<=m)
			{
				if(v[child].size()==1)
					ans++;
				else
					dfs(child,m,streak,vis,col,v);
			}
		}
	}
	
}
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	int col[n+1]={0};
	for(int i=1;i<=n;i++)	cin>>col[i];
	vector<int> v[n+1];
	int a,b;
	for(int i=0;i<n-1;i++)
	cin>>a>>b , v[a].push_back(b) , v[b].push_back(a);
	int streak[n+1]={0},vis[n+1]={0};
	streak[1]=col[1];
	dfs(1,m,streak,vis,col,v);
	//for(int i=1;i<=n;i++)	cout<<streak[i]<<" ";
	cout<<ans<<endl;
	return 0;
}