//首先不难想到用FLOYD先求出任意2点的距离dis[i][j]
//接着枚举所有状态，用11位二进制表示10个城市和pizza店，1表示经过，0表示没有经过
//定义状态DP(S,i)表示在S状态下，到达城市I的最优值
//接着状态转移方程:DP(S,i) = min{DP(S^(1<<i-1),k) + dis[k][j],DP(S,i)},器重S^(1<<i-1)表示未到达城市i的所有状态，1<=k<=n
//对于全1的状态，即S = (1<<n)-1则表示经过所有城市的状态，最终还需要回到PIZZA店0
//那么最终答案就是min{DP(S,i) + dis[i][0]}
//dij[i][j]:i到j最短路
        
        for(int S = 0;S <= (1<<n)-1;++S)//枚举所有状态，用位运算表示
            for(int i = 1;i <= n;++i)
            {
                if(S & (1<<(i-1)))//状态S中已经过城市i
                {
                    if(S == (1<<(i-1)))    dp[S][i] = dis[0][i];//状态S只经过城市I，最优解自然是从0出发到i的dis,这也是DP的边界
                    else//如果S有经过多个城市
                    {
                        dp[S][i] = INF;
                        for(int j = 1;j <= n;++j)
                        {
                            if(S & (1<<(j-1)) && j != i)//枚举不是城市I的其他城市
                                dp[S][i] = min(dp[S^(1<<(i-1))][j] + dis[j][i],dp[S][i]);
                            //在没经过城市I的状态中，寻找合适的中间点J使得距离更短，和FLOYD一样
                        }
                    }
                }
            }
        ans = dp[(1<<n)-1][1] + dis[1][0];
        for(int i = 2;i <= n;++i)
            if(dp[(1<<n)-1][i] + dis[i][0] < ans)
                ans = dp[(1<<n)-1][i] + dis[i][0];
        printf("%d/n",ans);