#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,s,k;
        cin>>n>>s>>k;
        int K[k]={0},flag=0;
        for(int i=0;i<k;i++)
        {
            cin>>K[i];
            if(K[i]==s)
                flag=1;
        }
        if(flag==0)
        {
            cout<<"0"<<endl;
        }
        else
        {
            sort(K,K+k);
            int min1=0,min2=0;
            for(int i=0;i<k;i++)
            {
                if(K[i]==s)
                {
                    int x=1;
                    for(int j=i+1;j<k;j++)
                    {
                        if(s+x==K[j])
                        {
                            min1++;
                            x++;
                        }
                        else
                        {
                            min1++;
                            break;
                        }
                    }
                    if(s+x==K[k-1]+1)   min1++;
                    x=1;
                    for(int j=i-1;j>=0;j--)
                    {
                        if(s-x==K[j])
                        {
                            min2++;
                            x++;
                        }
                        else
                        {
                            min2++;
                            break;
                        }
                    }
                    if(s-x==K[0]-1) min2++;
                    break;
                }
            }
            //cout<<min1<<" "<<min2<<" ";
            if(min1<min2)
            {
                if(s+min1<=n)
                    cout<<min1<<endl;
                else
                    cout<<min2<<endl;
            }
            else
            {
                if(s-min2>0)
                    cout<<min2<<endl;
                else
                    cout<<min1<<endl;
            }
        }
    }
}