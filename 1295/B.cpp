#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,x;
        cin>>n>>x;
        char s[n+1];
        scanf("%s",s);
        int c[n]={0},a[n]={0};
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
                a[i]=1;
            else if(s[i]=='1')
                a[i]=-1;
        }
        for(int i=0;i<n;i++)
        {
            if(i>0)
                c[i]=c[i-1];
            if(s[i]=='0')
                c[i]+=1;
            else if(s[i]=='1')
                c[i]-=1;
        }
        //for(int i=0;i<n;i++)
        //    cout<<c[i]<<" ";
        if(c[n-1]==0)
        {
            cout<<"-1"<<endl;
        }
        else
        {
            int max=c[0],min=c[0];
            for(int i=0;i<n;i++)
            {
                if(max<c[i])
                    max=c[i];
                if(min>c[i])
                    min=c[i];
            }
            if((x*c[n-1]<0 && x>max) || (x*c[n-1]<0 && x<min))
                cout<<"0"<<endl;
            else
            {
                int j;
                if(c[n-1]>0)
                {
                    //j=(x>c[n-1])?n*(x/c[n-1]-1):0;
                    
                    j=(x>c[n-1])?((x%c[n-1]==0)?x/c[n-1]-1:x/c[n-1]):0;
                    //cout<<c[n-1]<<" "<<j<<" ";
                    int temp=c[n-1]*j,count=0;
                    for(int i=0;i<2*n;i++)
                    {
                        if(temp==x)
                            count++;
                        temp+=a[i%n];
                        //cout<<temp<<" ";
                    }
                    cout<<count<<endl;
                }
                else
                {
                    /*j=(x<c[n-1])?n*(x/c[n-1]-1):0;
                    int temp=(x<c[n-1])?c[n-1]*j:0,count=0;
                    for(int i=j;i<j+n;i++)
                    {
                        if(temp==x)
                            count++;
                        temp+=c[i%n];
                        
                    }
                    cout<<count<<endl;
                    */
                    j=(x<c[n-1])?((x%c[n-1]==0)?x/c[n-1]-1:x/c[n-1]):0;
                    //cout<<c[n-1]<<" "<<j<<" ";
                    int temp=c[n-1]*j,count=0;
                    for(int i=0;i<2*n;i++)
                    {
                        if(temp==x)
                            count++;
                        temp+=a[i%n];
                        //cout<<temp<<" ";
                    }
                    cout<<count<<endl;
                }
            }
            
        }
    }
}