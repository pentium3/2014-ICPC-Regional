//POJ3463
//dij�ɳڵ������ı��£����������
//1.�����·��2.�������·3.�������·�����ڴζ�·4.���ڴζ�·
//d[i][0]�����·�� d[i][1]�Ǵζ�·
//�����ö��Ż�+�ڽӱ���Ϊ��Ҫ����dis[i][0]��dis[i][1]���ף����������һ�������������
//�������ڽӾ�����Ϊ�����ر�
#include <stdio.h>
#include <string.h>
#define INF 999999

struct node
{
    int to,dat;
}edge[1010][1010];

int cnt[1010][2],d[1010][2],vis[1010][2];
int x,y,z,n,m,T,st,ed;

void insert_node(int x,int y,int z)
{
    edge[x][0].dat++;
    int tmp=edge[x][0].dat;
    edge[x][tmp].to=y;
    edge[x][tmp].dat=z;
}

void dijkstra()
{
    memset(vis,0,sizeof(vis));
    memset(d,INF,sizeof(d));
    memset(cnt,0,sizeof(cnt));
    d[st][0]=0;
    cnt[st][0]=1;

    for (int i=1;i<=2*n;i++)
    {
        int minj,flag,minx=INF;
        for (int j=1;j<=n;j++)
            if ((vis[j][0]==0)&&(d[j][0]<minx))
            {
                minx=d[j][0];
                minj=j;
                flag=0;
            }
            else if ((vis[j][1]==0)&&(d[j][1]<minx))
            {
                minx=d[j][1];
                minj=j;
                flag=1;
            }
        vis[minj][flag]=1;
        int tmp=edge[minj][0].dat;
        for (int j=1;j<=tmp;j++)
        {
            int yy=edge[minj][j].to;
            int zz=edge[minj][j].dat;
            //if (vis[yy][flag]==0)
            //{
                int tm=minx+zz;
                if (tm<d[yy][0])
                {
                    d[yy][1]=d[yy][0];
                    cnt[yy][1]=cnt[yy][0];
                    d[yy][0]=tm;
                    cnt[yy][0]=cnt[minj][flag];
                }
                else if (tm==d[yy][0])
                {
                    cnt[yy][0]+=cnt[minj][flag];
  		    //��Ϊ�ɳڲ����Ǵ�minj�㿪ʼ��
   		    //��d[minj]+a[minj,j]<d[j]��
    	  	    //���Լ�¼cnt��ʱ��Ҫ+=cnt[minj][flag]
   		    //һ��ʼ��Ϊֱ��+1���У�WA��
   		    //ǰ���cnt[yy][0]=cnt[minj][flag]ͬ��
                }
                else if (tm<d[yy][1])
                {
                    d[yy][1]=tm;
                    cnt[yy][1]=cnt[minj][flag];
                }
                else if (tm==d[yy][1])
                {
                    cnt[yy][1]+=cnt[minj][flag];
                }
            //}

        }

    }
}

int main()
{
//    freopen("in.txt","r",stdin);

    scanf("%d",&T);
    while (T--)
    {
        memset(edge,0,sizeof(edge));
        scanf("%d %d",&n,&m);
        for (int i=1;i<=m;i++)
        {
            scanf("%d %d %d",&x,&y,&z);
            insert_node(x,y,z);
        }
        scanf("%d %d",&st,&ed);

/*
        for (int i=1;i<=n;i++)
            for (int j=1;j<=edge[i][0].dat;j++)
                printf("Debug: %d -> %d = %d\n",i,edge[i][j].to,edge[i][j].dat);
*/

        dijkstra();

        int tx,ty,ans2,ans1;
        tx=d[ed][0];    ty=d[ed][1];
        ans1=cnt[ed][0];
        if (ty-tx==1)   ans2=cnt[ed][1];
            else ans2=0;
//        printf("%Debug: %d %d %d %d\n",tx,ty,ans1,ans2);
        printf("%d\n",ans1+ans2);
    }
    return 0;
}