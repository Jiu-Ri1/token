#include<bits/stdc++.h>
using namespace std;
struct wyx{
	int a,b;
 	bool ok;
};
int n;
wyx m[100005];
bool cmp(wyx a1,wyx b1)
{
	return a1.a<b1.a;
}
int main()
{	
    cin>>n;
    for(int i=0;i<n;i++)
        {
            cin>>m[i].a>>m[i].b;
            if(m[i].b==1)
            m[i].ok=1;
        }
    sort(m,m+n,cmp);
    vector<int> x;
    bool l=0;
	for(int i=0;i<n;i++)
    {
		if(m[i].ok==0)
//		cout<<m[i].a<<" ";
		{
			l=1;
			x.push_back(m[i].a);	
		}
    }
    if(l==0)
    {
		cout<<"NONE";
		return 0;
	}
	for(int i=1;i<x.size();i++)
	{
		if(x[i]==x[i-1])
		continue;
		if(i>0)
				cout<<" ";
		cout<<x[i];
	}
}
