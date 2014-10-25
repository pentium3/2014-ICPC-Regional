#include "iostream"
#include "string"
#include "map"
#include "vector"
#include "fstream"
using namespace std;
map<vector<long long int>,int> bag;
map<long long int,vector<vector<long long int> > > Hash;
bool ok=false;
void right_trans(vector<long long int> str)
{
    long long k;
    vector<long long int> work=str;
    for(int i=0;i<5;i++)
    {
        k=work[0];
        work.erase(work.begin());
        work.push_back(k);
        if(!bag.count(work)) bag[work]=1;
        else bag[work]++;
    }
    if(!bag.count(str)) bag[str]=1;
        else bag[str]++;
}
void left_trans(vector<long long int> str)
{
    vector<long long int> work;
    work.push_back(str[0]);
    int tail=str.size()-1;
    for(int i=0;i<5;i++)
    {
        work.push_back(str[tail]);
        tail--;
    }
    right_trans(work);
}
int main()
{
    //#define fin cin
    //ifstream fin("in.txt");
    vector<long long int> tmp;
    int n,m;
    cin>>n;
 while(n--)
 {
    long long int key=0;
    for(int i=0;i<6;i++)
    {
        cin>>m;
        key+=m;
        tmp.push_back(m);
    }
    //key=key%prime;
    if(Hash.count(key))
    {
        Hash[key].push_back(tmp);
    }
    else
    {
        vector<vector<long long int> > link;
        link.push_back(tmp);
        Hash[key]=link;
    }
    tmp.clear();
    key=0;
 }
 for(map<long long int,vector<vector<long long int> > >::iterator i=Hash.begin();i!=Hash.end();i++)
 {
     if(i->second.size()>=2) //链中有两个以上元素,添加到第二哈希表
     {
         int num=i->second.size();
         bag.clear();
         for(int j=0;j<num;j++)
         {
             if(ok) break;
             left_trans(i->second[j]);
             right_trans(i->second[j]);
             if(j>=1)
             {
                  for(map<vector<long long int>,int>::iterator j=bag.begin();j!=bag.end();j++)
                  {
                      if(j->second>=2) {ok=true;break;}
                      //cout<<j->second<<endl;
                  }
             }
             if(ok) break;
         }
         if(ok) {cout<<"Twin snowflakes found.";break;}
     }
 }
    if(!ok) cout<<"No two snowflakes are alike.";
    return 0;
}
