#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[1005],n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		a[i]=0;
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=i;j<=n;j+=i)
		{
			if(a[j]==0)
			a[j]=1;
			else if(a[j]==1)
			a[j]=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==1)
		cout<<i<<" ";
	}
	//system("pause");
	return 0;
}
