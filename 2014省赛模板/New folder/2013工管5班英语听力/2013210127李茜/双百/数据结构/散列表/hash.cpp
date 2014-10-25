#include "iostream"
#include "map"
#include "string"
#include "cstring"
#include "stdlib.h"
#include "fstream"
using namespace std;
bool isCh(char x)
{
    if(x>=65&&x<=122) return true;
    else return false;
}
int main()
{
    //#define fin cin
    //ifstream fin("in.txt");
    int Case,len;
    string str1,str2,t1,t2;
    string num,emp;
    int cnum;
    int wnum;
    int start,pos;
    map<string,int> b1,b2,e1,e2;
    cin>>Case;
    int no=0;
    while(Case--)
    {
        no++;
        cin>>len>>t1>>t2;
        for(int i=0;i<t1.size();i++)
        {
            if(!isCh(t1[i])) num.push_back(t1[i]);
            else
            {
                cnum=atoi(num.c_str());
                num=emp;
                for(int j=1;j<=cnum;j++) str1.push_back(t1[i]);
            }
        }
        for(int i=0;i<t2.size();i++)
        {
            if(!isCh(t2[i])) num.push_back(t2[i]);
            else
            {
                cnum=atoi(num.c_str());
                num=emp;
                for(int j=1;j<=cnum;j++) str2.push_back(t2[i]);
            }
        }
        wnum=str1.size()/len;
        start=0;
        t1=emp,t2=emp;
        while(wnum--)
        {
            for(int i=start;i<str1.size();i=i+str1.size()/len)
            {
                t1.push_back(str1[i]);
                t2.push_back(str2[i]);
            }
            if(!b1.count(t1)) b1[t1]=1;
            else b1[t1]++;
            if(!b2.count(t2)) b2[t2]=1;
            else b2[t2]++;
            t1=emp;
            t2=emp;
            start++;
        }
        bool flag=true;
        for(map<string,int>::iterator i=b1.begin();i!=b1.end();i++)
        {
            if(i->second!=b2[i->first]) flag=false;
        }
        if(flag) cout<<"Case "<<no<<": Yes"<<endl;
        else cout<<"Case "<<no<<": No"<<endl;
        b1=e1;b2=e2;
        str1=emp,str2=emp;
    }
}
