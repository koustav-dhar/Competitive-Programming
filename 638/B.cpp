#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
#define MAX 26
ll key(ll i, ll j, ll n, ll m)
{
    return i*m+j+1;
}
vector<ll> v[MAX];
ll vis[MAX]={0},par[MAX];

void dfs(ll node)
{
    vis[node]=1;
    cout<<char(97+node);
    for(auto child : v[node])
    {
        if(vis[child]==0)
        {
            dfs(child);
        }
    }
}
signed main()
{
    fast
    // memset(par,-2,sizeof(par));
    for(ll i=0;i<MAX;i++)
        par[i]=-2;
    ll n;
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
        if(par[s[0]-97]==-2)
            par[s[0]-97]=-1;
        for(ll i=1;i<s.length();i++)
        {
            if(par[s[i]-97]!=s[i-1]-97)
            {
                par[s[i]-97]=s[i-1]-97;
                v[s[i-1]-97].push_back(s[i]-97);
            }
        }
    }
    // for(ll i=0;i<MAX;i++)
    // {
    //     for(auto itr:v[i])
    //     {
    //         cout<<i<<":"<<itr<<endl;
    //     }
    // }
    for(ll i=0;i<MAX;i++)
    {
        if(par[i]==-1)
        {
            dfs(i);
        }
    }
    return 0;
}