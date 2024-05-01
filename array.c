#include<stdio.h>
#include<stdlib.h>

typedef struct{
     int order; //�ڵ��������е����
     int  num;   //ҳ��
     int length;//ҳ������һ�γ��ָ�ҳ�ŵľ��룬�����ҳ�Ų��ٳ��֣���999
     struct Page*next;
}Page;

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


Page*Addone(Page*a)//a�����������ͷ���
{
 Page*p=(Page*)malloc(sizeof(Page));
 p=a->next;
 while(p!=NULL)
 {
    p->length=p->length+1;
    p=p->next;
 }

 return a;
}

int Getnumf(Page*a)//�������������б��滻�Ľڵ����(���ݽڵ������������ͣ���ĵ�ʱ�䣬��length��ʾ��)
{
  int k=0,maxs=-1,t=1;//l�Ǻ�������ֵ��maxs�ǵ�ǰlength�����ֵ��t������ʾ���������ڵ�����
    Page *p=malloc(sizeof(Page));
    p=a->next;//a��ͷ��㣬p�ǵ�һ�����ݽڵ�
    while(p!=NULL)
    {
      if(p->length>maxs)
       {
         maxs=p->length;
         k=t;
       }
     p=p->next;
     t=t+1;
    }
  return k;

}

Page* Fifofunc(Page*h,Page*a,Page*b,int le,int len)//h�Ǵ�����ҳ�������ͷ��㣬a��һ��������ҳ�Žڵ㣬b�����������ͷ��㣬len������������Ŀ��le����ǰҪ����������������š�
{
    Page *p=(Page*)malloc(sizeof(Page));
   Page *px=(Page*)malloc(sizeof(Page));



   int fd=Pant(b,a);//�ж����������b���Ƿ��д�����ڵ�a��ҳ��
   if(fd==1)
    b->order = b->order+1;//����ҳ���滻���ܴ�����

   if(le<=len)
   {
    b=AddNode(b,a,le);//������������δ������ҳ�ŷ���������С�
    b=Addone(b);
   }
   if(le>len)
    {

        while(fd)
        {

      printf("\n��ǰҪ����Ľڵ�ҳ�ţ�");
      printf("%d\n",a->num);
        printf("����������и�ҳ��ͣ��������������ʱ��: ");
       Prinl(b);

        int ka=Getnumf(b);//��������������Ҫ���滻�Ľڵ����
         p=b;
         for(int df=0;df<ka;df++)
            p=p->next;
         printf("������б��滻�Ľڵ�ҳ�ţ� ");
         printf("%d\n",p->num);
        b=DeleteNode(b,ka);//�����滻�Ľڵ�ɾ��

        b=AddNode(b,a,ka);//���滻�Ľڵ�������������

            break;
       }

       b=Addone(b);
    }

  return b;

}

void FIFO(Page*a,Page*b,int kd)//a������ҳ����ͷ��㣬b�����������ͷ��㣬kd�������������
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


     b=Fifofunc(a,p,b,i,kd);//��������������е�ҳ��ڵ�
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

    }
}

int main()
{
  Page*a=(Page*)malloc(sizeof(Page));
  Page*b=(Page*)malloc(sizeof(Page));
  Page*c=(Page*)malloc(sizeof(Page));
  Page*d=(Page*)malloc(sizeof(Page));
  Page*e=(Page*)malloc(sizeof(Page));
  Page*f=(Page*)malloc(sizeof(Page));
  Page*c1=(Page*)malloc(sizeof(Page));
  Page*d1=(Page*)malloc(sizeof(Page));
  Page*e1=(Page*)malloc(sizeof(Page));
  Page*f1=(Page*)malloc(sizeof(Page));
  Page*c2=(Page*)malloc(sizeof(Page));
  Page*d2=(Page*)malloc(sizeof(Page));
  Page*e2=(Page*)malloc(sizeof(Page));
  Page*f2=(Page*)malloc(sizeof(Page));
  Page*c3=(Page*)malloc(sizeof(Page));
  Page*d3=(Page*)malloc(sizeof(Page));
  Page*e3=(Page*)malloc(sizeof(Page));
  Page*f3=(Page*)malloc(sizeof(Page));
  Page*c4=(Page*)malloc(sizeof(Page));
  Page*d4=(Page*)malloc(sizeof(Page));
  Page*e4=(Page*)malloc(sizeof(Page));
  Page*f4=(Page*)malloc(sizeof(Page));

    a->order=0;
    a->num=NULL;
    a->length=NULL;
    a->next=c;

    c->order=1;
    c->num=7;
    c->length=0;
    c->next=d;

    d->order=2;
    d->num=0;
    d->length=0;
    d->next=e;

     e->order=3;
    e->num=1;
    e->length=0;
    e->next=f;

    f->order=4;
    f->num=2;
    f->length=0;
    f->next=c1;

    c1->order=5;
    c1->num=0;
    c1->length=0;
    c1->next=d1;

    d1->order=6;
    d1->num=3;
    d1->length=0;
    d1->next=e1;

    e1->order=7;
    e1->num=0;
    e1->length=0;
    e1->next=f1;

    f1->order=8;
    f1->num=4;
    f1->length=0;
    f1->next=c2;

     c2->order=9;
    c2->num=2;
    c2->length=0;
    c2->next=d2;

    d2->order=10;
    d2->num=3;
    d2->length=0;
    d2->next=e2;

    e2->order=11;
    e2->num=0;
    e2->length=0;
    e2->next=f2;

    f2->order=12;
    f2->num=3;
    f2->length=0;
    f2->next=c3;

    c3->order=13;
    c3->num=2;
    c3->length=0;
    c3->next=d3;

    d3->order=14;
    d3->num=1;
    d3->length=0;
    d3->next=e3;

    e3->order=15;
    e3->num=2;
    e3->length=0;
    e3->next=f3;

    f3->order=16;
    f3->num=0;
    f3->length=0;
    f3->next=c4;

    c4->order=17;
    c4->num=1;
    c4->length=0;
    c4->next=d4;

    d4->order=18;
    d4->num=7;
    d4->length=0;
    d4->next=e4;

    e4->order=19;
    e4->num=0;
    e4->length=0;
    e4->next=f4;

    f4->order=20;
    f4->num=1;
    f4->length=0;
    f4->next=NULL;



//printf("����һ��ҳ�� \n");
    b->order=0;//��������ȱҳ����
    b->num=NULL;
    b->length=0;
    b->next=NULL;

  FIFO(a,b,3);
  return 0;
}
