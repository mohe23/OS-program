#include<stdio.h>

float out(float m[3][3])//计算3*3系数矩阵的行列式
{
  int k;
  float h;
  for(k=0;k<3;k++)
     {
        m[1][k]= m[0][k]*(-m[1][0]/m[0][0])+m[1][k];
        m[2][k]= m[0][k]*(-m[2][0]/m[0][0])+m[2][k];
      }
    h=m[0][0]*(m[1][1]*m[2][2]-m[2][1]*m[1][2]);
     return h;
}
int main()
{ int i,j;
  float g,x,y,z;
   float  t[3][3],b[3][3],c[3][3],d[3][3],e[3],p[3];

   printf("input 3 dui :\n");
      for(i=0;i<3;i++)
      for(j=0;j<3;j++)
     scanf("%f",&t[i][j]);//输入系数，该数组每一行就是一个方程式x,y,z前面的系数。

     printf("input 1 dui:\n");//输入等式右边的值
    for(i=0;i<3;i++)
    scanf("%f",&e[i]);

      printf("\n");

      for(i=0;i<3;i++)
      for(j=0;j<3;j++)
       {
         b[i][j]=t[i][j];
         c[i][j]=t[i][j];
         d[i][j]=t[i][j];
       }

      for(i=0;i<3;i++)//将系数行列式第i列替换为最后一列的数值项
         {
          b[i][0]=e[i];
          c[i][1]=e[i];
          d[i][2]=e[i];
         }

      g=out(t);
      x=out(b);
      y=out(c);
      z=out(d);

     printf("\n");

    p[0]=x/g;//线性方程组的解
    p[1]=y/g;
    p[2]=z/g;
    for(i=0;i<3;i++)
    printf("%5f\n",p[i]);
    return 0;
}
