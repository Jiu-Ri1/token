#include<bits/stdc++.h>
using namespace std;
long cc[105],yc[105];
int main()
{
	int x,y,z;
	cc[1]=1;
	yc[1]=0;
	cin>>x>>y>>z;
	for(int i=2;i<=z+1;i++)
	{
		yc[i]=cc[i-x]*y;
		cc[i]=yc[i-2]+cc[i-1];
	}
	cout<<cc[z+1];
	//system("pause");
	return 0;
}
