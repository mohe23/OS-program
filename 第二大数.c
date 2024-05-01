#include<stdio.h>

int main()
{
  float v[4][4],a[4],b[4],c[4],d[4],t;
  int i,j;
  printf("输入数据:\n");

   for(i=0;i<4;i++)
      for(j=0;j<4;j++)
      scanf("%f",&v[i][j]);



    for(i=0;i<4;i++)//将4行中每一行输入到一个一维数组中，保证原二维数组中的数据位置不变
       {
        a[i]=v[0][i];
        b[i]=v[1][i];
        c[i]=v[2][i];
        d[i]=v[3][i];
       }
      for(i=0;i<4;i++)
       for(j=i+1;j<4;j++)
       {
           if(a[i]<a[j])//将4个一维数组中的元素按照降序排列
           {t=a[i];
            a[i]=a[j];
            a[j]=t;
           }
            if(b[i]<b[j])
           {t=b[i];
            b[i]=b[j];
            b[j]=t;
           }
            if(c[i]<c[j])
           {t=c[i];
            c[i]=c[j];
            c[j]=t;
           }
           if(d[i]<d[j])
           {t=d[i];
            d[i]=d[j];
            d[j]=t;
           }
       }
   printf("第二大数    位置:\n");

     for(i=0;i<4;i++)//每一行第二大的元素与原二维数组中每行的每一个元素做比较，如果相等，则输出数据以及位置
         if(a[1]==v[0][i])
        printf("%f%6d\n",a[1],i+1);

     for(i=0;i<4;i++)
         if(b[1]==v[1][i])
        printf("%f%6d\n",b[1],i+1);

        for(i=0;i<4;i++)
         if(c[1]==v[2][i])
        printf("%f%6d\n",c[1],i+1);

        for(i=0;i<4;i++)
          if(d[1]==v[3][i])
        printf("%f%6d\n",d[1],i+1);

    return 0;

}
