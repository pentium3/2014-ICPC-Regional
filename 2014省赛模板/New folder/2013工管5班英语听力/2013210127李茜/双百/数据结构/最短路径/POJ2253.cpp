#include "iostream"
#include "math.h"
#include "iomanip"
#include "fstream"
using namespace std;
double abs(int a)
{
    if(a<0) return -a;
    else return a;
}
int n;
double d[201][201];
struct point
{
    int x,y;
}p[201];
const double inf=10000000;
int main()
{
    #define fin cin
    ifstream fin("in.txt");
    int Case=0;
    while(cin>>n&&n!=0)
    {
    Case++;
    double x,y;
    for(int i=1;i<=n;i++)
        cin>>p[i].x>>p[i].y;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(i==j) d[i][j]=0;
            else
                d[i][j]=d[j][i]=sqrt((double)abs(p[i].x-p[j].x)*abs(p[i].x-p[j].x)+abs(p[i].y-p[j].y)*abs(p[i].y-p[j].y));
        }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
           for(int j=1;j<=n;j++)
              {
                  double tmp=d[i][k]>d[k][j]?d[i][k]:d[k][j];
                  if(tmp<d[i][j]) d[i][j]=tmp;
              }
    cout<<setprecision(3)<<fixed<<"Scenario #"<<Case<<endl<<"Frog Distance = "<<d[1][2]<<endl<<endl;
    }
}
