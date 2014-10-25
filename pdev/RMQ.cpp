void ST()        //初始化
{
    memset(RMQ,1,sizeof(RMQ));

    for(int i=1;i<=n;i++)
        RMQ[i][0]=a[i];
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
        RMQ[i][j]=min(RMQ[i][j-1],RMQ[i+(1<<(j-1))][j-1]);
}

int Query(int L,int R)    //求a[L..R]区间的最值
{
    int k=0;
    while((1<<(k+1))<=R-L+1) k++;
    int tb=min(RMQ[L][k],RMQ[R-(1<<k)+1][k]);
    return tb;
}