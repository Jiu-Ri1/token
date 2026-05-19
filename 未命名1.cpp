#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x;
    cin>>n;
    char a;
    cin>>a;
    for(int i=1;2*i*i-1<=n;i++)
        {
            x=i;
        }
    int ans=n-2*x*x+1;
    int x1=2*x-1;
    for(int i=0;i<x;i++)
        {
            int u=x1-2*i;
            for(int j=0;j<i;j++)
                {
                    cout<<" ";
                }
            for(int j=u;j>0;j--)
                {
                    cout<<a;
                }
            for(int j=0;j<i;j++)
                {
                    cout<<" ";
                }
            cout<<endl;
        }
    for(int i=x;i>1;i++)
        {
            for(int j=i-1;j>0;j--)
                {
                    cout<<" ";
                }
            for(int j=1;j<x1;j+=2)
                {
                    cout<<a;
                }
            for(int j=i-1;j>0;j--)
                {
                    cout<<" ";
                }
            cout<<endl;
        }
    cout<<ans;
}
