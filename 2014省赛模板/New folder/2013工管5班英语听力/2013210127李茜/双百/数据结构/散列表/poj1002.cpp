#include "iostream"
#include "string"
#include "map"
#include  "fstream"
using namespace std;
char trans(char c)
{
    if(c=='A'||c=='B'||c=='C') return '2';
    if(c=='D'||c=='E'||c=='F') return '3';
    if(c=='G'||c=='H'||c=='I') return '4';
    if(c=='J'||c=='K'||c=='L') return '5';
    if(c=='M'||c=='N'||c=='O') return '6';
    if(c=='P'||c=='R'||c=='S') return '7';
    if(c=='T'||c=='U'||c=='V') return '8';
    if(c=='W'||c=='X'||c=='Y') return '9';
}
map<string,int> bag;
int main()
{
    //#define fin cin
    //ifstream fin("in.txt");
    bool ok=false;
    int n;
    string tmp;
    string work;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>tmp;
        for(int i=0;i<tmp.size();i++)
        {
            if(tmp[i]!='-')
            {
                if(tmp[i]>=65&&tmp[i]<=90) work.push_back(trans(tmp[i]));
                else work.push_back(tmp[i]);
            }
        }
        if(!bag.count(work)) bag[work]=1;
        else bag[work]++;
        work.clear();
    }
    for(map<string,int>::iterator i=bag.begin();i!=bag.end();i++)
    {
        if(i->second>=2)
        {
            ok=true;
            string k=i->first;
            k.insert(3,"-");
            cout<<k<<" "<<i->second<<endl;
        }
    }
    if(!ok) cout<<"No duplicates."<<endl;
    return 0;

}
