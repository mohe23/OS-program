 #include<stdio.h>

 int Decises(int F[5])  //Finish��һ��һά����,�ж�ϵͳ�Ƿ��԰�ȫ״̬
 {
  int k=1;
  int i;
  for(i=0;i<5;i++)
   {
     if(F[i]==0)
     {
        k=0;
        break;
     }
    }
  return k;
 }

int main()
{
  int a[5]={1,0,1,1,1};
  int ca;
  ca=Decises(a);
  printf("%d",ca);
  return 0;
}
