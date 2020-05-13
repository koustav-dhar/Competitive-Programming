#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int ans=n+m+n*m-3;
    vector<char> str;
    for(int i=0;i<n-1;i++)  str.push_back('U');
    for(int i=0;i<m-1;i++)  str.push_back('L');
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            for(int j=0;j<m-1;j++)
                str.push_back('R');
        }
        else
        {
            for(int j=0;j<m-1;j++)
                str.push_back('L');
        }
        str.push_back('D');
    }
    str.erase(str.end()-1);
    cout<<ans<<endl;
    for(char i:str) cout<<i;
    cout<<endl;
    return 0;
}