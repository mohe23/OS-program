#include<stdio.h>
#include<stdlib.h>

typedef struct{
     int order; //�ڵ��������е����
     int num;   //ҳ��
     int length;//ҳ������һ�γ��ָ�ҳ�ŵľ��룬�����ҳ�Ų��ٳ��֣���999
     struct Page*next;
}Page;


int Pans(Page*h,Page*p)
{
  int labe=0;//���λ�������hΪͷ���������У��������л�����p֮����pҳ����ͬ�Ľڵ㣬����1������Ϊ0
  Page *q=(Page*)malloc(sizeof(Page));
  q=h->next;
  while(q!=NULL)
  {
      if(p->num==q->num)
      {
        labe=1;
        break;

      }

       else
        q=q->next;
  }
return labe;
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

Page*lengths(Page*h,Page*p,Page*p1)//h�Ǵ�����ҳ������p�Ǵ����������е�ҳ��ڵ㣬p1������������е�һ����㣬������p1ҳ���ٴγ��־���p�ľ���
{
   Page *q=(Page*)malloc(sizeof(Page)); //ָ�����ҳ��������p֮���ҳ��ڵ�
   q=h;  //һ��ʼָ��ͷ���
    for(int i=0;i<=p->order;i++)
      q=q->next;   //q��ָ����ҳ�������н���p֮���ҳ��ڵ�

   int k=Pans(h,p1);//�ж�������h��,��ǰ��������еĽڵ�p1��ҳ���Ƿ��ٴγ��֣��ٴγ��֣�kΪ1��


   if(k==1)
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


Page* AddNode(Page*h,Page*q,int i)//�������е�ָ��λ�ò���ڵ㡣�������Ҫ����һ�³���Ľ�׳�Ծ͸����ˣ�������������λ�ô�������ĳ��ȣ���δ���
{

  int j=0;

  Page *p=(Page*)malloc(sizeof(Page));

  p=h;
if(!(p->next))
  {

     q->next=p->next;
     p->next=q;
  }
else{
     while((p->next)&&(j<i-1))
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


Page*Getnodev(Page*h,int iv)
{

   Page*p=(Page*)malloc(sizeof(Page));
   Page*q=(Page*)malloc(sizeof(Page));
   p=h;
   for(int i=0;i<iv;i++)
    p=p->next;

    q->order=p->order;
    q->num=p->num;
    q->length=p->length;
    q->next=NULL;

   return q;
}

int Pant(Page*a,Page*b)//a�����������ͷ��㣬b�Ǵ�����ڵ㡣���b��ҳ��a�������нڵ��ҳ�Ŷ���ͬ������ֵ1
{
   int k,k1=0,k2=0;
   Page*p=(Page*)malloc(sizeof(Page));
   p=a->next;
   while(p!=NULL)
   {
       if(p->num==b->num)
        k1=k1;//���������ڵ�ҳ��������������е�ǰ�ڵ�ҳ����ͬ��k1����0.
       else
        k1=k1+1;//���������ڵ�ҳ��������������е�ǰ�ڵ�ҳ�Ų���ͬ��k1����1.

     p=p->next;
     k2=k2+1;//k2�����������k1���Աȣ��ó����ķ���ֵ
   }

  if(k1==k2)
    k=1;
  else
    k=0;

return k;
}


int  main()
{
      int s;
  Page*a=(Page*)malloc(sizeof(Page));
  Page*b=(Page*)malloc(sizeof(Page));
  Page*c=(Page*)malloc(sizeof(Page));
  Page*d=(Page*)malloc(sizeof(Page));
  Page*e=(Page*)malloc(sizeof(Page));
  Page*a1=(Page*)malloc(sizeof(Page));
  Page*a2=(Page*)malloc(sizeof(Page));
  Page*a3=(Page*)malloc(sizeof(Page));
   a->order=0;
    a->num=NULL;
    a->length=NULL;
    a->next=c;

    a1->order=0;
    a1->num=1;
    a1->length=NULL;
    a1->next=NULL;


     b->order=0;
    b->num=3;
    b->length=NULL;
    b->next=NULL;

    c->order=1;
    c->num=7;
    c->length=4;
    c->next=d;

    d->order=2;
    d->num=0;
    d->length=2;
    d->next=e;

     e->order=3;
    e->num=1;
    e->length=1;
    e->next=NULL;



  Page*b1=(Page*)malloc(sizeof(Page));
Page*b2=(Page*)malloc(sizeof(Page));
Page*b3=(Page*)malloc(sizeof(Page));
Page*b4=(Page*)malloc(sizeof(Page));

    b=lengths(a,c,b);
    printf("%d\n",b->length);



 return 0;
}
