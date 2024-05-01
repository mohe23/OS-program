#include<stdio.h>

int*Tone(int*s,int*h,int*k,int p1,int p2)//获得2个集合合并后的大集合。
{
   int i,j,p,k1,k2;
   p=p1+p2;
   
   if(p1>=p2)//将元素多的集合放入到预先构造的大集合中。
   {
      for(i=0;i<p1;i++)
		  k[i]=s[i];

	  k1=p1;//此时合并集合中的元素数目。
	  k2=p2;
   }

   else
   {
      for(i=0;i<p2;i++)
		  k[i]=h[i];

	  k1=p2;//此时合并集合中的元素数目。
	  k2=p1;
   }


   for(i=k1,j=0;i<p,j<k2;i++,j++)//这里可能要考虑如果两个集合中要是有相同元素会怎样。
   {
     int key;
	 key=Pan()
   }
}

  int Pan(int*d,int l,int e)//判断整数e是否在集合d中（若在，返回0；不在，返回1）
  {
     int i,t=1;//t是返回值，代表判断结果。
	 for(i=0;i<l;i++)
	 {
	    if((d[i]-e)==0)//如果d集合中一个元素值等于e,跳出循环，返回值为0。
		{
			t=0;
			break;
		}

	 }
    
	 return t;
  }


int main()
{
  int a[4],b[4],c[8];

}