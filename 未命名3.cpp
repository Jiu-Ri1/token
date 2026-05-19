#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m=INT_MIN,mi=INT_MAX,num=0;
    int a[1005];
    cin>>n;
    for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]>m)
                m=a[i];
            if(a[i]<mi)
                mi=a[i];
            num+=a[i];
        }
    num/=n;
    bool ok=0,x;
    cout<<m<<" "<<mi<<" "<<num<<endl;
    for(int i=0;i<n;i++)
        {
            if(a[i]>num*2)
            {
            	x=0;
                if(ok==1)
                    cout<<" ";
                cout<<i+1;
                ok=1;
            }
        }
        if(x==0)
        cout<<"Normal";
}
