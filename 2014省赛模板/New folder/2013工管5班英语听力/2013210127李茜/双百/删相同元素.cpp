#include "iostream"
#include "string"
using namespace std;
void dfs(string &str,int k)
{
	if(k==str.size())  return;
	else
	{
		bool flag=true;
		while(flag)
		{
			flag=false;//Çå³ıÍê±ÏÔ¾³ö 
			for(int i=k+1;i<str.size();i++)
			{
				if(str[i]==str[k])
				{
					str.erase(i,i);
					flag=true;
					break;
				}
				else
				{
					flag=false;	
				} 
			}
		}
		dfs(str,k+1);
	}
}
int main()
{
	string str;
	cin>>str;
	dfs(str,0);
	cout<<str<<endl;
	return 0;
}
