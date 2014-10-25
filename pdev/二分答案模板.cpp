//二分答案输出r-l的最大值
l=0;    r=n;
        while (r>=l)
        {
            int mid=(l+r)/2;    //mid: r-l
            if (calc(mid))        //calc(mid): 判断mid答案是否符合要求
                l=mid+1;
            else
                r=mid-1;
        }
-------------------------------------
//二分答案求最小值
l:=0;   r:=mx;
while l<r do
 begin
 mid:=(l+r) div 2;
 ok:=calc(mid);
 if ok then
  r:=mid;
 else
  l:=mid+1;
 end;
------------------------------------
//记录最值：都在calc(mid)函数里面