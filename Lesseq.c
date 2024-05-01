 #include<stdio.h>
 int Decises(int F[5])  //Finish是一个一维数组,判断系统是否处以安全状态
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


 int Lesseq(int a[5][3],int b[3],int k) //判断一个进程的还需的资源数量是否小于系统此时提供的资源数量，小于就返回1。
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

int GetOrder(int N[5][3],int W[3],int F[5])  //找到一个资源需求Need小于Work的进程在数组中的序号，找不到，返回初值100
 {
     int ke=100; //返回的进程序号
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


void PanDu(int A[5][3],int B[5][3],int C[5],int D[3]) //A是进程还需要的m类资源数量 B是进程已分配的m类资源数目。C是判断某个进程申请资源后，5个进程是否处于安全状态，D是m类资源当前还有的数量。
 {
     int i;
     fi=GetOrder(A,D,C);
     fl=Decises(C);

     while((fi!=100)&&(!fl))
     {
         for(i=0;i<3;i++)
         {
             D[i]=D[i]+B[fi][i]; //有进程结束后，更新当前3类资源。
             C[fi]=1;
         }
       fi=GetOrder(A,D,C);
       fl=Decises(C);
     }
     if(Decises(C))
        printf("系统处于安全状态");
     else
        printf("不安全状态");
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
