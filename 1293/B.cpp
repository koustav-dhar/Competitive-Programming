#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    double ans=0;
    for(int i=1;i<=n;i++)
        ans+=double(1*1.0/i);
    printf("%lf\n",ans);
    return 0;
}