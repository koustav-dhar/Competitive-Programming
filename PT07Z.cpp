#include <bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int> v[],int vis[],int dis[])
{
	vis[node]=1;
	for(int child:v[node])
	{
		if(vis[child]==0)
		{
			dis[child]=dis[node]+1;
			dfs(child,v,vis,dis);
		}
	}
}
int main() {
	// your code goes here
	int n;
	cin>>n;
	vector<int> v[n+1];
	int a,b;
	for(int i=0;i<n-1;i++)
		cin>>a>>b , v[a].push_back(b) , v[b].push_back(a);
	int vis[n+1]={0},dis[n+1]={0};
	dfs(1,v,vis,dis);
	int maxnode=1,maxdis=INT_MIN;
	for(int i=1;i<=n;i++)
		if(dis[i]>maxdis)
			maxdis=dis[i] , maxnode=i;
	//cout<<maxnode<<maxdis;
	int vis2[n+1]={0},dis2[n+1]={0};
	dfs(maxnode,v,vis2,dis2);
	maxdis=INT_MIN;
	for(int i=1;i<=n;i++)
		if(dis2[i]>maxdis)
			maxdis=dis2[i];
	cout<<maxdis;
	return 0;
