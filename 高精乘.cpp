#include<bits/stdc++.h>
using namespace std;
int c[20100],a1[1005],b1[1005],n1,n2;
int main()
{
	string a,b;
	cin>>a>>b;
	n1=a.size();
	n2=b.size();
	for(int i=0;i<n1;i++)
	{
		a1[i]=a[n1-i-1]-'0';
	}
	for(int i=0;i<n2;i++)
	{
		b1[i]=b[n2-i-1]-'0';
	}
	int len=n1+n2;
	for(int i=0;i<n1;i++)
	{
		for(int j=0;j<n2;j++)
		{
			c[i+j]+=a1[i]*b1[j];
		}
	}
	for(int i=0;i<=len;i++)
	{
		if(c[i]>=10)
		{
			c[i+1]+=c[i]/10;
			c[i]%=10;
		}
	}
	while(c[len]==0&&len>0)
		len--;
	for(int i=len;i>=0;i--)
	{
		cout<<c[i];
	}
	//system("pause");
	return 0;
}
