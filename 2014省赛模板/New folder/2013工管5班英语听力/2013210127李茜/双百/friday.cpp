#include "iostream"
#include "cstring"
using namespace std;
int day[8];
void add(int x)
{
	int temp=x%7;
	switch(temp)
	{
		case 0:
			day[7]++;
			break;
			case 1:
				day[1]++;
				break;
				case 2:
					day[2]++;
					break;
					case 3:
						day[3]++;
						break;
						case 4:
							day[4]++;
						    break;
						    case 5:
						    	day[5]++;
						    	break;
						    	case 6:
						    		day[6]++;
						    		break;
   }								
}
int main()
{
	int n,year;
	cin>>n;
	year=1900+n-1;
	int x=13;
	memset(day,0,sizeof(day));
	for(int i=1900;i<=year;i++)
	{
		bool isX=false;
		if(year==1900||year==2100||year==2200) isX=false;
		else
		{
			if(year%4==0) isX=true;
		}
		for(int j=1;j<=12;j++)
		{
			if(j==1&&x==13) {add(13);x+=31;continue;} 
			if(isX) 
			{
				if(j==2) {add(x);x+=29;continue;}
			}			
			if(!isX&&j==2) {add(x);x+=28;continue;}
			if(j==4||j==6||j==9||j==11) {add(x);x+=30;continue;}
			add(x);
			x+=31;
		}
	}
	cout<<day[6]<<" "<<day[7]<<" ";
	for (int i=1;i<=5;i++)
	{
		cout<<day[i]<<" ";
	}
	cout<<endl;
	cout<<x;
	return 0;
}
