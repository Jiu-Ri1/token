#include<bits/stdc++.h>
using namespace std;
int ans=1,last[100005];
long long n,a[100005],b[100005],c[100005],a1[100005],b1[100005],c1[100005];
struct wyx
	{
		long long be,en;
	};
bool cmp(wyx a1,wyx a2)
{
	return a1.be<a2.be;
}
int main()
{
	
	char ch;
	wyx qmx[100005];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>ch>>b[i]>>ch>>c[i];
		cin>>a1[i]>>ch>>b1[i]>>ch>>c1[i];
		qmx[i].be=a[i]*3600+b[i]*60+c[i];
		qmx[i].en=a1[i]*3600+b1[i]*60+c[i];
	}
	sort(qmx,qmx+n,cmp);
	
	last[0]=qmx[0].en;
	for(int i=1;i<n;i++)
	{
		bool ok=0;
		for(int j=0;j<ans;j++)
		{
			if(last[j]<qmx[i].be)
			{
				ok=1;
				last[j]=qmx[i].en;
				break;
			}
		}
		if(ok==0)
		{
			ans++;
			last[ans]=qmx[i].en;
			
		}
	}
	cout<<ans;
	return 0;
}
