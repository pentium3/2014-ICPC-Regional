//���ִ����r-l�����ֵ
l=0;    r=n;
        while (r>=l)
        {
            int mid=(l+r)/2;    //mid: r-l
            if (calc(mid))        //calc(mid): �ж�mid���Ƿ����Ҫ��
                l=mid+1;
            else
                r=mid-1;
        }
-------------------------------------
//���ִ�����Сֵ
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
//��¼��ֵ������calc(mid)��������