#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
#define MAX 200001
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
    vector<pair<ll,ll>> uv;
    for(ll i=0;i<m;i++)
        cin>>a>>b , uv.push_back({a,b}) , v[a].push_back(b) , v[b].push_back(a);
    if(dfs(1,0))
    {
        cout<<"YES\n";
        for(ll i=0;i<m;i++)
        {
            if(col[uv[i].first]==0)
                cout<<"0";
            else
                cout<<"1";
        }
    }
    else
        cout<<"NO\n";
    return 0;
}