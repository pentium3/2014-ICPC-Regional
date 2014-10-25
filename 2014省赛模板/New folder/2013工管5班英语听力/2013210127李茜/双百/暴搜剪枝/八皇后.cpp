#include<stdio.h>
#include "iostream"
using namespace std;
int chess[8][8];              //将8*8的棋盘用二维数组来表示位置 
int a[8],b[15],c[15];  
int sum=0;             //统计所有摆法   
void PutQueen(int n)            //声明函数PutQueen的递归调用
{  
    int col,i,j;  
    for(col=0;col<8;col++)    //col表示横向
    {  
        if(a[col]&&b[n+col]&& c[n-col+7])                 //判断安全位置，使皇后不会被皇后吃掉   
        {  
            chess[n][col]=1;                            //放置皇后   
            a[col]=0;  
            b[n+col]=0;  
            c[n-col+7]=0;  
            if(n==7)  
            {  
                sum++;  
                cout<<"第"<<sum<<"种摆法"<<endl;   //输出皇后摆法   
                    for(i=0;i<8;i++)
					{  
                        for(j=0;j<8;j++)  
                            cout<<chess[i][j]<<" ";
						cout<<endl; 
                    }   
//                  goto END;                         //输出第一种摆法   
                    if(sum%10==0)                     //每输出十种暂停   
                    {  
                        printf("按回车键继续");   //使每十个显示，回车键显示下十个
                        getchar();  
                    }  
            }  
            else   
                PutQueen(n+1);		                        //递归   
            chess[n][col]=0;                            //取消皇后   
            b[n+col]=1;                                    
            c[n-col+7]=1;  
            a[col]=1;                             
        }  
    }    
}  
int main()  
{    
    int i;  
    for(i=0;i<8;++i)  
        a[i]=1;  
    for(i=0;i<15;++i)  
    {  
        b[i]=1;  
        c[i]=1;  
    }  
    PutQueen(0);  
    printf("八皇后摆法总数: %d/n",sum);  
    return 0;  
}  

