#include<stdio.h>
#include<stdlib.h>

int Decises(int *F,int len)  //Finish��һ��һά����,�ж�ϵͳ�Ƿ��԰�ȫ״̬.len��ʾ������Ŀ
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


int **IsLess(int **a,int *b,int *c,int k,int len) //�жϽ����������Դ�ܷ����Ԥ����������ԣ�����1��
{                                                //��ά����a�洢���Ǹ����̻���Ҫ����Դ������b�洢����һ�������������Դ��
 int i,j,key;                                     //����cϵͳ��ʱ������Դ��k�ǽ��̵���ţ�len����Դ������Ŀ��
 int **w=(int**)calloc(2,sizeof(int));
   for(i=0;i<2;i++)
     w[i]=(int*)calloc(len+1,sizeof(int));

    for(i=0;i<2;i++)
        for(j=0;j<len+1;j++)
           w[i][j]=-1000;

 for(i=0;i<len;i++)
 {
    if(b[i]>a[k][i])//��������������Դ���ڸý��̻���Ҫ����Դ�������������Դ���ڴ�ʱϵͳ���õ���Դ����ѭ����k1=0
       w[0][0]=0;//���������Դ�Ƿ���ڽ���������Դ�����ڵĻ���0�����򱣳�ԭֵ

    w[0][i+1]=b[i]-a[k][i];//ֵΪ��������ʾ���ڣ���ֵΪ���ڵĶ��١�ֵΪ��������ʾС�ڣ�����ֵΪС�˶���

    if(b[i]>c[i])//������Դ���ڿ�����Դ
        w[1][0]=0;//���������Դ�Ƿ���ڿ�����Դ�����ڵĻ���0�����߱���ԭֵ��

    w[1][i+1]=b[i]-c[i];//ֵΪ��������ʾ���ڡ�ֵΪ��������ʾС��
 }

 return w;

}

int Lessq(int**a,int *b,int k,int len)//�жϽ����������Դ�Ƿ�С�ڿ�����Դ�����ǣ�����ֵΪ1.
 {
   int i,la=1;
    for(i=0;i<len;i++)
   {
       if(a[k][i]>b[i])//�ý��̻���Ҫ����Դ���ڴ�ʱ���õ���Դ
       {
           la=0;
           break;
       }
   }

    return la;
 }



 int Lesseq(int **a,int *b,int k,int len) //�ж�һ�����̵Ļ������Դ�����Ƿ�С��ϵͳ��ʱ�ṩ����Դ������С�ھͷ���1��
 {                                          //a�����Ǹ����̻���Ҫ����Դ,b������ϵͳ������Դ��len��ʾ��Դ��������
   int i,lab=1;

   for(i=0;i<len;i++)
   {
       if(a[k][i]>b[i])//�ý��̻���Ҫ����Դ���ڴ�ʱ���õ���Դ
       {
           lab=0;
           break;
       }
   }

   return lab;
 }


int GetOrder(int **N,int *W,int *F,int len1,int len2)  //�ҵ�һ����Դ����NeedС��Work�Ľ����������е���ţ��Ҳ��������س�ֵ100
 {                                     //N��ʾ�����̻���Ҫ����Դ��W��ʾϵͳ������Դ��F��ǽ��̵���Դ�Ƿ�õ����䡣
     int ke=100; //���صĽ������      len1��len2��ʾ�ǽ���������Դ��������
     int i;
     for(i=0;i<len1;i++)
     {
       int k1=Lesseq(N,W,i,len2);
       if((k1==1)&&(F[i]==0))
        {
           ke=i;
           break;//����ѭ����
        }

     }
  return ke;
 }


int  PanDu(int **Q,int *h,int **A,int **B,int *C,int *D,int le1,int le2) //A�ǽ��̻���Ҫ��m����Դ���� B�ǽ����ѷ����m����Դ��Ŀ��
 {                                              // C���ж�ĳ������������Դ��5�������Ƿ��ڰ�ȫ״̬��D��m����Դ��ǰ���е�������
     int i,j=0,vg;                                     //le1,le2��ʾ����������Դ��������Q�����Ǵ�ſ�����Դ��ÿһ�α仯��
     int fi=GetOrder(A,D,C,le1,le2);                   //h�����Ű�ȫ���У��������)��
     int fl=Decises(C,le1);

     while((fi!=100)&&(!fl))
     {
         h[j]=fi;
         j=j+1;
         for(i=0;i<le2;i++)
         {
             D[i]=D[i]+B[fi][i]; //�н��̽����󣬸��µ�ǰ3����Դ��
             Q[fi][i]=D[i];
             C[fi]=1;
         }
       fi=GetOrder(A,D,C,le1,le2);
       fl=Decises(C,le1);
     }


       Prits(Q,h,A,B,le1,le2,fl);//��ӡ������ݡ�
     vg=Decises(C,le1);
     return vg;
 }


 void Prits(int **Q,int *h,int **Need,int **Allocation,int length1,int length2,int key)//��ӡ�����ѷ�����Դ������Ҫ��Դ���Լ�������Դ��ÿ�α仯��
 {
   int i,j;
   printf("�ѷ�����Դ\n");

    for(i=0;i<length1;i++)
    {
         for(j=0;j<length2;j++){
             printf("%d  ",Allocation[i][j]);
         }


        printf("\n");
    }


    printf("\n");


    printf("����Ҫ��Դ\n");
    for(i=0;i<length1;i++){
         for(j=0;j<length2;j++){
             printf("%d  ",Need[i][j]);
         }

        printf("\n");
    }

    printf("\n");


    printf("������Դ\n");
    for(i=0;i<length1;i++){
         for(j=0;j<length2;j++){
             printf("%d  ",Q[i][j]);
         }

        printf("\n");
    }


    if(key==1)
    {
        printf("��ȫ���У�\n");
     for(i=0;i<length1;i++)
     printf("����%d ,",h[i]);

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
          if(ke==1)//��Ҫ����������Դ
          {
              printf("������Դ����������Դ�������Դ������������Դ:\n");
               printf("������ţ�");
               printf("%d\n",al);
               Request=ChangeR(Request,Available,leng2);

               for(i=0;i<leng2;i++)
                printf("%d ",Request[i]);
               printf("\n");
              Banker(Q,h,Need,Allocation,Available,Request,Finish,al,leng1,leng2,0);
          }

          else
          printf("�����������Դ������������Ҫ����Դ���߳���������Դ���޷�Ϊ�ý���Ԥ������Դ\n");
       }
       //printf("�Ƿ����������Դ��%d\n",k1);

       while(k==1){

        if(PanDu(Q,h,Need,Allocation,Finish,Available,leng1,leng2)==1)
      printf("ϵͳ��ȫ������ִ���������,������Դ��\n");
      else
      {
         for(i=0;i<3;i++)
          {
          Available[i]=Available[i]+Request[i];
          Allocation[al][i]=Allocation[al][i]-Request[i];
          Need[al][i]=Need[al][i]+Request[i];
          }
          printf("ϵͳ����ȫ���ܾ�������룬�ý���������Դ�޷�����\n");
      }

      break;
    }

}

int main()
{
   int i,j,leng1,leng2,order;
   printf("����������Դ��������������Դ�Ľ����������е����:\n");
   scanf("%d %d %d",&leng1,&leng2,&order);


   int**a=(int**)calloc(leng1,sizeof(int));//�洢ÿһ�ν�����ɺ󣬿�����Դ��Ŀ��������ȫ���㷨�иտ�ʼ������Դ��Ŀ��
   int**b=(int**)calloc(leng1,sizeof(int));//������Ȼ����Ҫ����Դ
   int**c=(int**)calloc(leng1,sizeof(int));//�����Ѿ��������Դ
   int*d=(int*)calloc(leng2,sizeof(int));//ϵͳ������Դ
   int*r=(int*)calloc(leng2,sizeof(int));//ĳ�������������Դ
   int*f=(int*)calloc(leng1,sizeof(int));//���ĳ�����̵���Դ�����Ƿ�õ����㡣
   int*h=(int*)calloc(leng1,sizeof(int));//��Ű�ȫ���еĽ���������С�
   for(i=0;i<leng1;i++)
   {
     b[i]=(int*)calloc(leng2,sizeof(int));
     c[i]=(int*)calloc(leng2,sizeof(int));
     a[i]=(int*)calloc(leng2,sizeof(int));
   }

   printf("�����������Դ:\n");
     for(i=0;i<leng1;i++)
        for(j=0;j<leng2;j++)
        scanf("%d",&b[i][j]);

    printf("�����ѷ������Դ��\n");
        for(i=0;i<leng1;i++)
         for(j=0;j<leng2;j++)
          scanf("%d",&c[i][j]);

    printf("ϵͳ������Դ��\n");
    for(i=0;i<leng2;i++)
        scanf("%d",&d[i]);


        printf("������ţ�");
        printf("%d\n",order);

    printf("����������Դ��\n");
   for(i=0;i<leng2;i++)
    scanf("%d",&r[i]);

    for(i=0;i<leng1;i++)//�������һ��ʼȫΪ0��
    {
       f[i]=0;
       h[i]=0;//һ��ʼ��Ű�ȫ����ֵȫΪ0��
    }


    for(i=0;i<leng1;i++)
        for(j=0;j<leng2;j++)
           a[i][j]=0;//һ��ʼֵȫΪ0


 Banker(a,h,b,c,d,r,f,order,leng1,leng2,1);

 return 0;
}
