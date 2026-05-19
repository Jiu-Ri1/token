#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a1,a2,n;
    vector <int> b;
    cin>>a1>>a2>>n;
    b.push_back(a1);
    b.push_back(a2);
    for(int i=0;i<n;i++)
        {
            int x=b[i]*b[i+1];
            if(x>=10){
                b.push_back(x/10);
                b.push_back(x%10);
            }
            else if(x<10)
            {
                b.push_back(x);
            }
        }
    for(int i=0;i<n;i++)
        {
        	if(i>0) cout<<" ";
            cout<<b[i];
        }
}
