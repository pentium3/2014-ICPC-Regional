#include<stdio.h>
#include "iostream"
using namespace std;
int chess[8][8];              //��8*8�������ö�ά��������ʾλ�� 
int a[8],b[15],c[15];  
int sum=0;             //ͳ�����аڷ�   
void PutQueen(int n)            //��������PutQueen�ĵݹ����
{  
    int col,i,j;  
    for(col=0;col<8;col++)    //col��ʾ����
    {  
        if(a[col]&&b[n+col]&& c[n-col+7])                 //�жϰ�ȫλ�ã�ʹ�ʺ󲻻ᱻ�ʺ�Ե�   
        {  
            chess[n][col]=1;                            //���ûʺ�   
            a[col]=0;  
            b[n+col]=0;  
            c[n-col+7]=0;  
            if(n==7)  
            {  
                sum++;  
                cout<<"��"<<sum<<"�ְڷ�"<<endl;   //����ʺ�ڷ�   
                    for(i=0;i<8;i++)
					{  
                        for(j=0;j<8;j++)  
                            cout<<chess[i][j]<<" ";
						cout<<endl; 
                    }   
//                  goto END;                         //�����һ�ְڷ�   
                    if(sum%10==0)                     //ÿ���ʮ����ͣ   
                    {  
                        printf("���س�������");   //ʹÿʮ����ʾ���س�����ʾ��ʮ��
                        getchar();  
                    }  
            }  
            else   
                PutQueen(n+1);		                        //�ݹ�   
            chess[n][col]=0;                            //ȡ���ʺ�   
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
    printf("�˻ʺ�ڷ�����: %d/n",sum);  
    return 0;  
}  

