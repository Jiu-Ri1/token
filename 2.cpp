#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i=0,ans;
	cin>>n;
	vector<string> k(n);
	while(i<n)
	{
		cin>>k[i];
		i++;	
	}
	cin>>ans;
	string l;
	cin.ignore();
	getline(cin,l);
	string str=l;
	int num=0;
	for(string key:k)
	{
		int pos=0;
		while((pos=str.find(key,pos))!=string::npos)
		{
			num++;
			pos+=key.size();
		}
	}
	if(num>=ans)
	{
		cout<<num<<endl<<"He Xie Ni Quan Jia!";
		return 0;
	}
	for(string key:k)
	{
		size_t pos=0;
		while((pos=l.find(key,pos))!=string::npos)
		{
			l.replace(pos,key.size(),"<censored>");
			
			pos+=10;
		}
	}
	cout<<l;
	//system("pause");
	return 0;
}
