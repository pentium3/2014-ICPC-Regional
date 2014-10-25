#include "iostream"
#include "string"
#include "vector"
using namespace std;
string mirror(string str)
{
	string x(str);
	int tail=str.size()-1;
	int head=0;
	for(int i=0;i<str.size();i++)
	{
		x[head]=str[tail];
		head++;
		tail--;
	}
	return x;
}
int main()
{
	vector<string> lib;
	string str;
	string sum;
	int MAX=0;
	while(cin>>str)
	{
	   lib.push_back(str);
	   if(str.size()>MAX) MAX=str.size();
    }
    int bit=0;int leap=0;
	for(int j=0;j<MAX;j++)
	{
	  for(int i=0;i<lib.size();i++)
	  {
	  	  if(!lib[i].empty())
	  	  {
		    int tail=lib[i].size()-1; 
		    bit+=lib[i][tail]-48;
		    if(tail>=1)
		    lib[i].erase(tail,tail); //erase函数不能删成空字符串 
		    else
		    lib[i]="";
		  }		
	  }
	  leap=bit/10;
	  bit=bit%10;
	  sum.push_back(bit+48);
	  bit=leap;
   }
   	//补下末尾进位 
     if(bit>0) sum.push_back(bit+48);
     //镜面一下 
	 cout<<mirror(sum)<<endl;
	return 0;
}
   
