#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 300003
vector<ll> v[MAX],ans[MAX];
ll vis[MAX]={0},countbridge=0,in[MAX],low[MAX],timer=0;

void dfs(ll node, ll par)
{
    vis[node]=1;
    in[node]=low[node]=timer;
    timer++;
    for(auto child : v[node])
    {
        if(child==par)
            continue;
        if(vis[child]==1)
        {
            low[node]=min(in[child],low[node]);
            if(in[child]<in[node])
                ans[node].push_back(child);
        }
        else
        {
            
            dfs(child,node);
            ans[node].push_back(child);
            if(low[child]>in[node])
                countbridge++;
            low[node]=min(low[node],low[child]);
        }
    }
}

signed main() {
	// your code goes here
	fast
	ll n,m,a,b;
	cin>>n>>m;
	for(ll i=0;i<m;i++)
	    cin>>a>>b , v[a].push_back(b) , v[b].push_back(a);
	dfs(1,-1);
	if(countbridge>0)
	    cout<<"0\n";
	else
	{
	    for(int i=1;i<=n;i++)
	    {
	        if(!ans[i].empty())
	        {
	            for(auto x:ans[i])
	            {
	                cout<<i<<" "<<x<<endl;
	            }
	        }
	    }
	}
	return 0;
}