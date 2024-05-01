#include<stdio.h>
#include<stdlib.h>

typedef struct{
     int order; //�ڵ��������е����
     int  num;   //ҳ��
     int length;//ҳ������һ�γ��ָ�ҳ�ŵľ��룬�����ҳ�Ų��ٳ��֣���999
     struct Page*next;
}Page;

Page* CreateNode( Page*pag)//�����ڵ�
 {
   pag=(Page*)malloc(sizeof(Page));

    pag->order=0;
    pag->num=NULL;
    pag->length=0;
    pag->next=NULL;
   return pag;
 }

 Page* CreateList(Page*L,int k)//����һ������Ϊk����������ͷ���
 {

    int i,j,x[k];
    printf("��������ڵ��numֵ��\n");
     for(i=0;i<k;i++)
    scanf("%d",&x[i]);

    Page *r;
    L=(Page*)malloc(sizeof(Page));
    r=(Page*)malloc(sizeof(Page));
    L=CreateNode(L);
    L->next=NULL;
    r=L;
    for(i=0;i<k;i++)
      {
       Page *p;
       p=(Page*)malloc(sizeof(Page));
       p->order=i+1;
       p->num=x[i];
       p->length=0;
       p->next=NULL;
       r->next=p;
       r=p;
       }
    return L;
}


Page* AddNode(Page*h,Page*q,int i)//�������е�ָ��λ�ò���ڵ㡣
{

  int j=0;

  Page *p=(Page*)malloc(sizeof(Page));

  p=h;
if(!(p->next))//h���ڵ�����ֻ��һ��ͷ��㡣
  {

     q->next=p->next;
     p->next=q;
  }
else{

     while(j<i-1)
       {
        p=p->next;
        j=j+1;
       }
   q->next=p->next;
   p->next=q;
  }
   return h;
}

Page* DeleteNode(Page *h,int d)//ɾ��������ָ��λ�õĽڵ�
{
    int j=0;
    Page *p=malloc(sizeof(Page));
    Page *q=malloc(sizeof(Page));
    p=h;
    while((p->next)&&(j<d-1))
      {
       p=p->next;
       j=j+1;
      }
    q = p->next;
    p->next=q->next;
    free(q);
    return h;
}

int Pans(Page*h,Page*p,Page*p1)//h������������ͷ��㣻 p�ǵ�ǰ����Ľڵ㣻 p1������������һ���ڵ�
{
  int labe=0;//���λ�������hΪͷ���������У��������л�����p֮����p1ҳ����ͬ�Ľڵ㣬����1������Ϊ0
  Page *q=(Page*)malloc(sizeof(Page));
  q=h;
  for(int kf=0;kf<p->order;kf++)
     q=q->next;//qָ����p
      q=q->next;//qָ����p֮����ڵĽڵ�
  while(q!=NULL)
  {
      if(p1->num==q->num)
      {
        labe=1;
        break;

      }

       else
        q=q->next;
  }
return labe;
}

int Pant(Page*a,Page*b)//a�����������ͷ��㣬b�Ǵ�����ڵ㡣����ڵ�b��ҳ����a�������нڵ��ҳ�Ŷ���ͬ������ֵ1
{
   int k,k1=0,k2=0;
   Page*p=(Page*)malloc(sizeof(Page));
   p=a->next;
   while(p!=NULL)
   {
       if(p->num!=b->num)
        k1=k1+1;//���������ڵ�ҳ��������������е�ǰ�ڵ�ҳ����ͬ��k1����0.
       else
        k1=k1;//���������ڵ�ҳ��������������е�ǰ�ڵ�ҳ�Ų���ͬ��k1����1.

     p=p->next;
     k2=k2+1;//k2�����������k1���Աȣ��ó����ķ���ֵ
   }

  if(k1==k2)
    k=1;
  else
    k=0;

return k;
}

Page*lengths(Page*h,Page*p,Page*p1)//h�Ǵ�����ҳ������p�Ǵ����������е�ҳ��ڵ㣬p1������������е�һ����㣬������p1ҳ����������p֮���ٴγ��־���p�ľ���
{
   Page *q=(Page*)malloc(sizeof(Page)); //ָ�����ҳ��������p֮���ҳ��ڵ�
      q=h;
      for(int bh=0;bh<p->order;bh++)//q��ָ����ҳ�������н���p֮���ҳ��ڵ�
         q=q->next;
      q=q->next;
   int kt=Pans(h,p,p1);//�ж�������h�Ľڵ�p֮��,��ǰ��������еĽڵ�p1��ҳ���Ƿ��ٴγ��֣��ٴγ��֣�kΪ1��

    //printf("��ҳ��ҳ���Ƿ��ٴγ��֣�1���ٴγ��֣�0��������֣�: ");
    //printf("%d\n",kt);
   if(kt==1)
   {
    while(q!=NULL)
    {

      if((q->num)==(p1->num))
        {

            p1->length=q->order - p->order;
            break;//ע��
        }

        else
        q=q->next;
    }
   }
   else
     p1->length=999;//��ǰҳ��֮�������в���������ҳ����ͬ�Ľڵ�

 return p1;
}

int Getnums(Page*a)//���������������Ҫ�������Ŀ����ڵ����
{
    int l=0,maxs=-1,t=1;//l�Ǻ�������ֵ��maxs�ǵ�ǰlength�����ֵ��t������ʾ���������ڵ�����
    Page *p=malloc(sizeof(Page));
    p=a->next;//a��ͷ��㣬p�ǵ�һ�����ݽڵ�
    while(p!=NULL)
    {
      if(p->length>maxs)
       {
         maxs=p->length;
         l=t;
       }
     p=p->next;
     t=t+1;
    }
  return l;
}

Page*Getnodev(Page*h,int iv)//ȡ�����еĸ���λ�õĽڵ�
{

   Page*p=(Page*)malloc(sizeof(Page));
   Page*q=(Page*)malloc(sizeof(Page));
   p=h;
   for(int i=0;i<iv;i++)
    p=p->next;

    q->order=p->order;//*********************//
    q->num=p->num;
    q->length=p->length;
    q->next=NULL;
   return q;
}

void Prin(Page*h)
{
  Page *p=(Page*)malloc(sizeof(Page));
  p=h->next;
  while(p!=NULL)
  {
    printf("%d  ",p->num);//�����ǰ�ڵ��ҳ��
    p=p->next;
  }
   printf("\n");
}

void Prinl(Page*h)
{
  Page *p=(Page*)malloc(sizeof(Page));
  p=h->next;
  while(p!=NULL)
  {
    printf("%d  ",p->length);//�����ǰ�ڵ��ҳ��
    p=p->next;
  }
   printf("\n");
}

Page* Optfunc(Page*h,Page*a,Page*b,int le,int len)//h�Ǵ�����ҳ�������ͷ��㣬a��һ��������ҳ�Žڵ㣬b�����������ͷ��㣬len������������Ŀ��le����ǰҪ����������������š�
{
    Page *p=(Page*)malloc(sizeof(Page));
   Page *px=(Page*)malloc(sizeof(Page));
   int cal=0;


   int fd=Pant(b,a);//�ж����������b���Ƿ��д�����ڵ�a��ҳ��
   if(fd==1)
    b->order = b->order+1;

  if(le<=len)
   b=AddNode(b,a,le);//������������δ������ҳ�ŷ���������С�

   if(le>len)
    {
        px=b->next;
        while(fd)
        {

         while(px!=NULL)
        {
         px=lengths(h,a,px);//����ڵ�֮�����������ͬҳ�Žڵ�ľ��룬���û�У���999

         px=px->next;
        }

      printf("\n��ǰҪ����Ľڵ�ҳ�ţ�");
      printf("%d\n",a->num);
        printf("����������и�ҳ���ٴγ���ʱ�뵱ǰ������ҳ��ڵ����ľ��루���ٳ��֣���999��: ");
       Prinl(b);

        int ka=Getnums(b);//��������������Ҫ���滻�Ľڵ����
         p=b;
         for(int df=0;df<ka;df++)
            p=p->next;
         printf("������б��滻�Ľڵ�ҳ�ţ� ");
         printf("%d\n",p->num);
        b=DeleteNode(b,ka);//�����滻�Ľڵ�ɾ��

        b=AddNode(b,a,ka);//���滻�Ľڵ�������������

            break;
       }
    }

  return b;

}

void Optimal(Page*a,Page*b,int kd)//a������ҳ����ͷ��㣬b�����������ͷ��㣬kd�������������
{
  Page *p=(Page*)malloc(sizeof(Page));
   Page *b1=(Page*)malloc(sizeof(Page));
   float rate;
  int i=1;
  int cal=0;
  b1=a->next;
  while(b1!=NULL)
  {
      cal=cal+1;
      b1=b1->next;
  }

  printf("������������: ");
  printf("%d\n",cal);
   p=Getnodev(a,i);
   while(p!=NULL)
   {


     b=Optfunc(a,p,b,i,kd);//��������������е�ҳ��ڵ�
     i=i+1;
     Prin(b);
      if(i==cal+1)
       {
          float b11=(float)(b->order);
          float b22=(float)cal;
          rate=b11/b22;
          printf("\nȱҳ�ʣ� ");
          printf("%f\n",rate);
       }
     p=Getnodev(a,i);
     //printf("b->order: ");
     //printf("%d\n",b->order);

    }


}

int main()//����ʱ����������order�Զ���һ
{
  int kw,kv;
   Page*a,*b;
  printf("����鳤��: ");
  scanf("%d",&kw);
   fflush(stdin);
     printf("\n");
  printf("������ҳ�泤�ȣ�");
  scanf("%d",&kv);
  fflush(stdin);
  printf("\n");



  a=CreateList(a,kv);//����һ������Ϊkv�Ľڵ�����

  b=CreateNode(b);

    Optimal(a,b,kw);

    return 0;

}
