#include<stdio.h>

float func(float m[3][3])//��������ʽ��ֵ
{
  int s;
  float e;
  for(s=0;s<3;s++)
       {
    m[1][s]= m[0][s]*(-m[1][0]/m[0][0])+m[1][s];
    m[2][s]= m[0][s]*(-m[2][0]/m[0][0])+m[2][s];
        }
      e=m[0][0]*(m[1][1]*m[2][2]-m[2][1]*m[1][2]);
      return e;
}

int main()
{ int i,j,h,k;
  float g,x,y,z;
   float  t[3][3],b[3][3],c[3][3],d[3][3],e[3],p[3];

   printf("input 3 dui :\n");
      for(i=0;i<3;i++)
      for(j=0;j<3;j++)
     scanf("%f",&t[i][j]);//����ϵ����������ÿһ�о���һ������ʽx,y,zǰ���ϵ����

     printf("input 1 dui:\n");//�����ʽ�ұߵ�ֵ
    for(h=0;h<3;h++)
    scanf("%f",&e[h]);

      printf("\n");

      for(i=0;i<3;i++)
      for(j=0;j<3;j++)
       {
         b[i][j]=t[i][j];
         c[i][j]=t[i][j];
         d[i][j]=t[i][j];
       }

    for(i=0;i<3;i++)//��ϵ������ʽ��i���滻Ϊ���һ�е���ֵ��
         {

          b[i][0]=e[i];

          c[i][1]=e[i];

          d[i][2]=e[i];
         }

      g=func(t);
      x=func(b);
      y=func(c);
      z=func(d);

    p[0]=x/g;//���Է�����Ľ�
    p[1]=y/g;
    p[2]=z/g;
    for(i=0;i<3;i++)
    printf("%5f\n",p[i]);
    return 0;

}
