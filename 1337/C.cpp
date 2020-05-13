#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define LOOP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define ff first
#define ss second
#define END "\n"
#define pb push_back
#define MOD 1000000007
#define MODU 998244353
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAXN   200001 
struct anal
{
	ll away;
	ll childs;
	ll index;
};

vector<ll> v[MAXN];
ll vis[MAXN]={0},dis[MAXN]={0};
unordered_map<ll,ll> industry;
ll ans=0;
bool compare(anal s1,anal s2)
{
    if((s1.away-s1.childs)!=(s2.away-s2.childs))
	    return (s1.away-s1.childs)>(s2.away-s2.childs);
	else
	    return v[s1.index].size()<v[s2.index].size();
}
void dfs(ll node)
{
    vis[node]=1;
    for(ll child:v[node])
    {
        if(vis[child]==0)
        {
            dis[child]=dis[node]+1;
            dfs(child);
        }
    }
}
ll count1[MAXN],count2[MAXN];
void numberOfNodes(ll s, ll e) 
{ 
    vector<ll>::iterator u; 
    count2[s] = 1; 
    for (u = v[s].begin(); u != v[s].end(); u++) { 
          
        // condition to omit reverse path 
        // path from children to parent 
        if (*u == e) 
            continue; 
          
        // recursive call for DFS 
        numberOfNodes(*u, s); 
          
        // update count[] value of parent using  
        // its children 
        count2[s] += count2[*u]; 
    } 
} 
void calc(ll s, ll e) 
{ 
    vector<ll>::iterator u;
    // cout<<s<<" "<<count2[s]<<endl;
    count1[s] = 0; 
    for (u = v[s].begin(); u != v[s].end(); u++) { 
          
        // condition to omit reverse path 
        // path from children to parent 
        if (*u == e) 
            continue; 
          
        // recursive call for DFS 
        calc(*u, s); 
          
        // update count[] value of parent using  
        // its children 
        // cout<<*u<<" "<<count2[*u]<<endl;
        count1[s] += count1[*u] + count2[*u]; 
    } 
} 
void dfs2(ll node, ll check, ll dist)
{
	vis[node]=1;
	if(industry[node]==1)
		ans+=dist;
	// for(auto itr:industry)
	// {
	// 	cout<<itr.first<<":"<<itr.second<<endl;
	// }
	for(ll child:v[node])
	{
		if(vis[child]==0)
		{
			if(check==0)
			{
				// cout<<child<<" "<<dis[child]<<" "<<industry[child]<<endl;
				if(industry[child]==1)
					dfs2(child,1,dist);
				else
					dfs2(child,0,dist+1);
			}
			else
			{
				// cout<<node<<" "<<dist<<endl;
				
				dfs2(child,1,dist);
			}
		}
	}
}
int main()
{
    fast
    // ll t;
    // cin>>t;
    // while(t--)
    // {
		ll n,k;
		cin>>n>>k;
		// ans=0;
		// for(ll i=1;i<=n;i++)
		// 	vis[i]=0 , dis[i]=0 , v[i].clear();
		// industry.clear();
		ll a,b;
		for(ll i=0;i<n-1;i++)
			cin>>a>>b , v[a].pb(b) , v[b].pb(a);
		dfs(1);
		numberOfNodes(1, 0);
		// for(ll i=1;i<=n;i++)
		// 	cout<<count2[i]<<" ";
		// cout<<endl;
		calc(1,0);
		vector<anal> order;
		for(ll i=1;i<=n;i++)
		{
			anal temp;
			temp.away=dis[i];
			temp.childs=count2[i];
			temp.index=i;
			order.pb(temp);
		}
		
		// for(ll i=1;i<=n;i++)
		// 	cout<<count1[i]<<" ";
		sort(order.begin(),order.end(),compare);
		// reverse(order.begin(),order.end());
		for(ll i=1;i<=n;i++)
			vis[i]=0;
		for(ll i=0;i<k;i++)
		{
			// cout<<order[i].index<<" ";
			industry[order[i].index]=1;
		}
		// for(auto itr:industry)
		// {
		// 	// cout<<itr.first<<":"<<itr.second<<endl;
		// }
		dfs2(1,0,1);
		cout<<ans<<endl;
    // }
    return 0;
}