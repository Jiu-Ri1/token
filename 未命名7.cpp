#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
    cin.ignore();
	vector<string> l(n);
    vector<string> l1(n);
    for(int i=0;i<n;i++)
        {
            getline(cin,l[i]);
            l1[i].push_back(l[i][0]);
            for(int j=1;j<l[i].size();j++)
                {
                    if(l[i][j-1]==' '&&l[i][j]!=' ')
                    {
                        l1[i].push_back(l[i][j]);
                    }
                }
        }
		
    int m;
    cin>>m;
    cin.ignore();
	vector<string> l3(n);
	vector<string> l4(n);
    
    for(int i=0;i<m;i++)
    {
		getline(cin,l3[i]);
		l4[i].push_back(l3[i][0]);
		for(int j=1;j<l3[i].size();j++)
		{
			if(l3[i][j-1]==' '&&l3[i][j]!=' ')
			{
				l4[i].push_back(l3[i][j]);
						
			}
		}
	}
//	for(int i=0;i<n;i++)
//	cout<<l1[i]<<endl;
//	for(int j=0;j<m;j++)
//	cout<<l4[j]<<endl;
	for(int i=0;i<m;i++)
	{
		bool ok=0;
		for(int j=0;j<n;j++)
		if(l4[i].size()==l1[j].size()&&l)
		{
			if(ok==1)
			{
				cout<<"|";
			}
			cout<<l[i];
			ok=1;
		}
		cout<<endl;
	}
 } 
