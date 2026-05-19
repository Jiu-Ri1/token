#include<bits/stdc++.h>
using namespace std;
int sign=0;
vector<int> d;
vector<int> ans;
void wyx(int x)
{
	if(sign==9)
	{
		sign=0;
		return;
		
	}
	int a=0;
	while(x>1)
	{
		a+=(x%10)*(x%10);
		x/=10;
	}
	if(a==0)
		{
			sign=0;		
			d.push_back(a);
		}
	sign+=1;
	wyx(a);
}
int main()
{
	int l,r;
	cin>>l>>r;
	for(int i=l;i<=r;i++)
	{
		wyx(i);
	}
	if(ans.empty()==0)
	{
		cout<<-1;
		return 0;
	}
	for(auto num:ans)
	{
		cout<<num<<" ";
	}
	//system("pause");
	return 0;
}
