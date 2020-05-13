#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<(n>=4?(n%2==0?0:1):4-n)<<endl;
    }
    return 0;
}