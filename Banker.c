#include<stdio.h>
#include<stdlib.h>

int Decises(int *F,int len)  //Finish是一个一维数组,判断系统是否处以安全状态.len表示进程数目
 {
  int k=1;
  int i;
  for(i=0;i<len;i++)
   {
     if(F[i]==0)
     {
        k=0;
        break;
     }
    }
  return k;
 }


int **IsLess(int **a,int *b,int *c,int k,int len) //判断进程申请的资源能否进行预处理，如果可以，返回1。
{                                                //二维数组a存储的是各进程还需要的资源，数组b存储的是一个进程申请的资源，
 int i,j,key;                                     //数组c系统此时可用资源，k是进程的序号，len是资源种类数目。
 int **w=(int**)calloc(2,sizeof(int));
   for(i=0;i<2;i++)
     w[i]=(int*)calloc(len+1,sizeof(int));

    for(i=0;i<2;i++)
        for(j=0;j<len+1;j++)
           w[i][j]=-1000;

 for(i=0;i<len;i++)
 {
    if(b[i]>a[k][i])//如果存在申请的资源大于该进程还需要的资源，或者申请的资源大于此时系统可用的资源跳出循环，k1=0
       w[0][0]=0;//标记申请资源是否大于进程所需资源。大于的话置0，否则保持原值

    w[0][i+1]=b[i]-a[k][i];//值为正数，表示大于，数值为大于的多少。值为负数，表示小于，绝对值为小了多少

    if(b[i]>c[i])//申请资源大于可用资源
        w[1][0]=0;//标记申请资源是否大于可用资源。大于的话置0，否者保持原值。

    w[1][i+1]=b[i]-c[i];//值为正数，表示大于。值为负数，表示小于
 }

 return w;

}

int Lessq(int**a,int *b,int k,int len)//判断进程申请的资源是否小于可用资源，若是，返回值为1.
 {
   int i,la=1;
    for(i=0;i<len;i++)
   {
       if(a[k][i]>b[i])//该进程还需要的资源大于此时可用的资源
       {
           la=0;
           break;
       }
   }

    return la;
 }



 int Lesseq(int **a,int *b,int k,int len) //判断一个进程的还需的资源数量是否小于系统此时提供的资源数量，小于就返回1。
 {                                          //a数组是各进程还需要的资源,b数组是系统可用资源，len表示资源种类数。
   int i,lab=1;

   for(i=0;i<len;i++)
   {
       if(a[k][i]>b[i])//该进程还需要的资源大于此时可用的资源
       {
           lab=0;
           break;
       }
   }

   return lab;
 }


int GetOrder(int **N,int *W,int *F,int len1,int len2)  //找到一个资源需求Need小于Work的进程在数组中的序号，找不到，返回初值100
 {                                     //N表示各进程还需要的资源，W表示系统可用资源，F标记进程的资源是否得到分配。
     int ke=100; //返回的进程序号      len1，len2表示是进程数，资源种类数。
     int i;
     for(i=0;i<len1;i++)
     {
       int k1=Lesseq(N,W,i,len2);
       if((k1==1)&&(F[i]==0))
        {
           ke=i;
           break;//跳出循环。
        }

     }
  return ke;
 }


int  PanDu(int **Q,int *h,int **A,int **B,int *C,int *D,int le1,int le2) //A是进程还需要的m类资源数量 B是进程已分配的m类资源数目。
 {                                              // C是判断某个进程申请资源后，5个进程是否处于安全状态，D是m类资源当前还有的数量。
     int i,j=0,vg;                                     //le1,le2表示进程数，资源种类数。Q数组是存放可用资源的每一次变化。
     int fi=GetOrder(A,D,C,le1,le2);                   //h数组存放安全序列（进程序号)。
     int fl=Decises(C,le1);

     while((fi!=100)&&(!fl))
     {
         h[j]=fi;
         j=j+1;
         for(i=0;i<le2;i++)
         {
             D[i]=D[i]+B[fi][i]; //有进程结束后，更新当前3类资源。
             Q[fi][i]=D[i];
             C[fi]=1;
         }
       fi=GetOrder(A,D,C,le1,le2);
       fl=Decises(C,le1);
     }


       Prits(Q,h,A,B,le1,le2,fl);//打印相关数据。
     vg=Decises(C,le1);
     return vg;
 }


 void Prits(int **Q,int *h,int **Need,int **Allocation,int length1,int length2,int key)//打印进程已分配资源，仍需要资源，以及可用资源的每次变化。
 {
   int i,j;
   printf("已分配资源\n");

    for(i=0;i<length1;i++)
    {
         for(j=0;j<length2;j++){
             printf("%d  ",Allocation[i][j]);
         }


        printf("\n");
    }


    printf("\n");


    printf("仍需要资源\n");
    for(i=0;i<length1;i++){
         for(j=0;j<length2;j++){
             printf("%d  ",Need[i][j]);
         }

        printf("\n");
    }

    printf("\n");


    printf("可用资源\n");
    for(i=0;i<length1;i++){
         for(j=0;j<length2;j++){
             printf("%d  ",Q[i][j]);
         }

        printf("\n");
    }


    if(key==1)
    {
        printf("安全序列：\n");
     for(i=0;i<length1;i++)
     printf("进程%d ,",h[i]);

     printf("\n");

    }

 else
  printf("\n");


 }


int *ChangeR(int *Request,int *Available,int len)
{
     int i;
    for(i=0;i<len;i++)
    {
      if(Request[i]>Available[i])
           Request[i]=Available[i];
        else
           Request[i]=Request[i];

    }

    return Request;
}


void Banker(int **Q,int *h,int **Need,int **Allocation,int *Available,int *Request,int *Finish,int al,int leng1,int leng2,int ke)
{
  int i,j,k,k1;
  k=IsLess(Need,Request,Available,al,leng2);
    if(k==1)
    {
         for(i=0;i<leng2;i++)
         {
          Available[i]=Available[i]-Request[i];
          Allocation[al][i]=Allocation[al][i]+Request[i];
          Need[al][i]=Need[al][i]-Request[i];
         }
    }
    else
       {
          if(ke==1)//需要调整申请资源
          {
              printf("申请资源大于所需资源或可用资源，调整申请资源:\n");
               printf("进程序号：");
               printf("%d\n",al);
               Request=ChangeR(Request,Available,leng2);

               for(i=0;i<leng2;i++)
                printf("%d ",Request[i]);
               printf("\n");
              Banker(Q,h,Need,Allocation,Available,Request,Finish,al,leng1,leng2,0);
          }

          else
          printf("进程申请的资源超过自身仍需要的资源或者超过可用资源，无法为该进程预分配资源\n");
       }
       //printf("是否调整申请资源，%d\n",k1);

       while(k==1){

        if(PanDu(Q,h,Need,Allocation,Finish,Available,leng1,leng2)==1)
      printf("系统安全，可以执行这次申请,分配资源！\n");
      else
      {
         for(i=0;i<3;i++)
          {
          Available[i]=Available[i]+Request[i];
          Allocation[al][i]=Allocation[al][i]-Request[i];
          Need[al][i]=Need[al][i]+Request[i];
          }
          printf("系统不安全，拒绝这次申请，该进程申请资源无法分配\n");
      }

      break;
    }

}

int main()
{
   int i,j,leng1,leng2,order;
   printf("进程数，资源种类数，申请资源的进程在数组中的序号:\n");
   scanf("%d %d %d",&leng1,&leng2,&order);


   int**a=(int**)calloc(leng1,sizeof(int));//存储每一次进程完成后，可用资源数目。包括安全性算法中刚开始可用资源数目。
   int**b=(int**)calloc(leng1,sizeof(int));//进程仍然所需要的资源
   int**c=(int**)calloc(leng1,sizeof(int));//进程已经分配的资源
   int*d=(int*)calloc(leng2,sizeof(int));//系统可用资源
   int*r=(int*)calloc(leng2,sizeof(int));//某个进程申请的资源
   int*f=(int*)calloc(leng1,sizeof(int));//标记某个进程的资源申请是否得到满足。
   int*h=(int*)calloc(leng1,sizeof(int));//存放安全序列的进程序号排列。
   for(i=0;i<leng1;i++)
   {
     b[i]=(int*)calloc(leng2,sizeof(int));
     c[i]=(int*)calloc(leng2,sizeof(int));
     a[i]=(int*)calloc(leng2,sizeof(int));
   }

   printf("进程仍需的资源:\n");
     for(i=0;i<leng1;i++)
        for(j=0;j<leng2;j++)
        scanf("%d",&b[i][j]);

    printf("进程已分配的资源：\n");
        for(i=0;i<leng1;i++)
         for(j=0;j<leng2;j++)
          scanf("%d",&c[i][j]);

    printf("系统可用资源：\n");
    for(i=0;i<leng2;i++)
        scanf("%d",&d[i]);


        printf("进程序号：");
        printf("%d\n",order);

    printf("进程申请资源：\n");
   for(i=0;i<leng2;i++)
    scanf("%d",&r[i]);

    for(i=0;i<leng1;i++)//标记数组一开始全为0。
    {
       f[i]=0;
       h[i]=0;//一开始存放安全序列值全为0。
    }


    for(i=0;i<leng1;i++)
        for(j=0;j<leng2;j++)
           a[i][j]=0;//一开始值全为0


 Banker(a,h,b,c,d,r,f,order,leng1,leng2,1);

 return 0;
}
