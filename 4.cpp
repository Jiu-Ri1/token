#include<bits/stdc++.h>
using namespace std;
int wyx(int n)
{
	if(n<10)
	return 0;
	int x=1;
	while(n>1)
	{
		x*=n%10;
		n/=10;
	}
	return 1+wyx(x);
}
int main()
{
	int l,m=0,r,ans[1005];
	cin>>l>>r;
	for(int i=l;i<=r;i++)
	{
		ans[i-l]=wyx(i);
		if(ans[i-l]>=m)
			m=ans[i-l];
	}
	bool ok=0;
	cout<<m<<endl;
	for(int i=l;i<=r;i++)
	{

		if(ans[i-l]==m)
		{
			if(ok==1)
				cout<<" ";
			cout<<i;
			
			ok=1;
		}
	}
	
}
