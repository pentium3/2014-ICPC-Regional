#include "iostream"
#include "string"
using namespace std;
int res[105];
int form[101][101];
int main()
{
    string tmp;
    int k=0,MAX=0;
    while(cin>>tmp)
    {
        k++;
        int tail=tmp.size()-1;
        if(tmp.size()>MAX) MAX=tmp.size();
        for(int i=0;i<tmp.size();i++)
        {
            form[k][i]=tmp[tail]-48;
        }
    }
   int leap=0;
   for(int i=0;i<=MAX;i++)
   {
       res[i]+=leap;
       leap=0;
       for(int j=1;j<=k;j++)
       {
           res[i]+=form[j][i];
       }
       leap=res[i]/10;
       res[i]=res[i]%10;
   }
   for(int i=MAX;i>=0;i--)
   {
       cout<<res[i];
   }
   return 0;
}
