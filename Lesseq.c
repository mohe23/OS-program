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


 int Lesseq(int a[5][3],int b[3],int k) //�ж�һ�����̵Ļ������Դ�����Ƿ�С��ϵͳ��ʱ�ṩ����Դ������С�ھͷ���1��
 {
   int lab=1;
   int j;
   for(j=0;j<3;j++)
   {
    if(a[k][j]>b[j])
    {
       lab=0;
       break;
    }
   }
   return lab;
 }

int GetOrder(int N[5][3],int W[3],int F[5])  //�ҵ�һ����Դ����NeedС��Work�Ľ����������е���ţ��Ҳ��������س�ֵ100
 {
     int ke=100; //���صĽ������
     int i;
     for(i=0;i<5;i++)
     {
       int k1=Lesseq(N,W,i);
       if(k1&&(F[i]==0))
      {
         ke=i;
         break;
       }
     }
  return ke;
 }


void PanDu(int A[5][3],int B[5][3],int C[5],int D[3]) //A�ǽ��̻���Ҫ��m����Դ���� B�ǽ����ѷ����m����Դ��Ŀ��C���ж�ĳ������������Դ��5�������Ƿ��ڰ�ȫ״̬��D��m����Դ��ǰ���е�������
 {
     int i;
     fi=GetOrder(A,D,C);
     fl=Decises(C);

     while((fi!=100)&&(!fl))
     {
         for(i=0;i<3;i++)
         {
             D[i]=D[i]+B[fi][i]; //�н��̽����󣬸��µ�ǰ3����Դ��
             C[fi]=1;
         }
       fi=GetOrder(A,D,C);
       fl=Decises(C);
     }
     if(Decises(C))
        printf("ϵͳ���ڰ�ȫ״̬");
     else
        printf("����ȫ״̬");
 }

 int main()
 {
   int a[5][3]={{7,4,3},{1,2,2},{6,0,0},{0,1,1},{4,3,1}};
   int b[5][3]={{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};
   int c[5]={0,0,0,0,0};
   int d[3]={3,3,2};
   PanDu(a,b,c,d);
   return 0;
 }
