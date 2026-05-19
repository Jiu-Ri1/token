#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,num;
	cin>>n;
	vector<string> key(n);
	for(int i=0;i<n;i++)
	{
		cin>>key[i];
	}
	cin>>num;
	string l1;
	cin.ignore();
	getline(cin,l1);
	int ans=0,i=0;
	while(i<l1.size())
	{
		bool found=0;
		for(string word:key)
		{
			int x=word.size();
			if(x+i>l1.size())
				continue;
			if(l1.substr(i,x)==word)
			{
				string l2="<censored>";
				l1.replace(i,x,"<censored>");
				i+=10;
				found=true;
				ans++;
				break;
			}
		}
		if(!found)
		{
			i++;
		}
	}
	if(ans<num)
	{
		cout<<l1;
	}
	else
	{
		cout<<ans<<endl;
		cout<<"He Xie Ni Quan Jia!";	
	}
	
	//system("pause");
	return 0;
}
