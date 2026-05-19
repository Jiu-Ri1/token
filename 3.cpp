#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,n;
	bool trees[10005];
	cin>>a>>n;
	for(int i=0;i<=a;i++)
	{
		trees[i]=true;
	}
	for(int i=1;i<=n;i++)
	{
		int l,r;
		cin>>l>>r;
		for(int j=l;j<=r;j++)
		{
			trees[j]=false;
		}
		
	}
	int ans=0;
	for(int i=0;i<=a;i++)
	{
		if(trees[i]==true)
		ans++;
	}
	cout<<ans;
	//system("pause");
	return 0;
}
