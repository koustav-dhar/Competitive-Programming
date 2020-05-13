#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
#define MAX 100001
vector<ll> v[MAX];
ll vis[MAX]={0},col[MAX];
bool dfs(ll node, ll c)
{
    vis[node]=1;
    col[node]=c;
    for(auto child : v[node])
    {
        if(vis[child]==0)
        {
            if(dfs(child,!c)==0)
                return false;
        }
        else
            if(col[node]==col[child])
                return false;
    }
    return true;
}
signed main()
{
    fast
    ll n,m;
    cin>>n>>m;
    ll a,b;
    for(ll i=0;i<m;i++)
        cin>>a>>b , v[a].push_back(b) , v[b].push_back(a);
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            if(v[i].empty())
                continue;
            else
                if(!dfs(i,0))
                {
                    cout<<"-1\n";
                    return 0;
                }
        }
    }
    
    ll count1=0,count2=0;
    vector<ll> c1,c2;
    for(ll i=1;i<=n;i++)
    {
        if(vis[i]==1)
        {
            if(col[i]==0)
            {
                count1++;
                c1.push_back(i);
            }
            else if(col[i]==1)
            {
                count2++;
                c2.push_back(i);
            }
        }
    }
    cout<<count1<<endl;
    for(auto x : c1)
        cout<<x<<" ";
    cout<<endl;
    cout<<count2<<endl;
    for(auto x : c2)
        cout<<x<<" ";
    cout<<endl;

    return 0;
}