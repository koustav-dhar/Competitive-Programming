#include<bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        vector<int> v,c;
        int t;
        for(int i=0;i<n;i++)
            cin>>t , v.push_back(t);
        c.push_back(1);
        int col=1,freq=1;
        for(int i=1;i<v.size();i++)
        {
            if(v[i]==v[i-1])
            {
                c.push_back(col);
            }
            else
            {
                if(col==1)
                {
                    col=2;
                    c.push_back(col);
                    freq=2;
                }
                else
                {
                    col=1;
                    c.push_back(col);
                }
            }
        }
        if(c[0]==c[v.size()-1] && v[0]!=v[v.size()-1])
        {
            for(int i=v.size()-1;i>=0;i--)
            {
                if(v[i]==v[v.size()-1])
                {
                    c[i]=3;
                    freq=3;
                }
            }
        }
        cout<<freq<<endl;
        for(int el:c)
        {
            cout<<el<<" ";
        }
        cout<<endl;
    }
    return 0;
}