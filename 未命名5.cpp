#include<bits/stdc++.h>
using namespace std;
int ans[10005];
int main()
{
	int num,m;
	struct wyx{
		int n;
		vector<int> v;
	};
	wyx qmx[10005];
	cin>>num>>m;
	for(int i=0;i<num;i++)
	{
		cin>>qmx[i].n;
		for(int j=0;j<qmx[i].n;j++)
		{
			int x;
			cin>>x;
			qmx[i].v.push_back(x);
		}
	}
	int q;
	cin>>q;
	for(int k=0;k<q;k++)
	{
		int l,r;
		cin>>l>>r;
		for(int i=0;i<num;i++)
			{
				bool a=0,b=0;
				for(int j=0;j<qmx[i].n;j++)
				{
					if(qmx[i].v[j]==l)
						a=1;
					if(qmx[i].v[j]==r)
						b=1;
				}
				if(a==1&&b==1)
				ans[k]++;
			}
	}
	for(int i=0;i<q;i++)
	{
		cout<<ans[i]<<endl;	
	}
	return 0;
}
