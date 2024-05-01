#include<stdio.h>
#include<stdlib.h>

typedef struct{
     int order; //节点在链表中的序号
     int  num;   //页号
     int length;//页号与下一次出现该页号的距离，如果此页号不再出现，置999
     struct Page*next;
}Page;

Page* AddNode(Page*h,Page*q,int i)//在链表中的指定位置插入节点。
{

  int j=0;

  Page *p=(Page*)malloc(sizeof(Page));

  p=h;
if(!(p->next))//h所在的链表只有一个头结点。
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

Page* DeleteNode(Page *h,int d)//删除链表中指定位置的节点
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

int Pant(Page*a,Page*b)//a是物理块链表头结点，b是待处理节点。如果节点b的页号与a表中所有节点的页号都不同，返回值1
{
   int k,k1=0,k2=0;
   Page*p=(Page*)malloc(sizeof(Page));
   p=a->next;
   while(p!=NULL)
   {
       if(p->num!=b->num)
        k1=k1+1;//如果待处理节点页号与物理块链表中当前节点页号相同，k1加上0.
       else
        k1=k1;//如果待处理节点页号与物理块链表中当前节点页号不相同，k1加上1.

     p=p->next;
     k2=k2+1;//k2负责计数，与k1做对比，得出最后的返回值
   }

  if(k1==k2)
    k=1;
  else
    k=0;

return k;
}

Page*Getnodev(Page*h,int iv)//取链表中的给定位置的节点
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
    printf("%d  ",p->num);//输出当前节点的页号
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
    printf("%d  ",p->length);//输出当前节点的页号
    p=p->next;
  }
   printf("\n");
}


Page*Addone(Page*a)//a是物理块链表头结点
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

int Getnumf(Page*a)//获得物理块链表中被替换的节点序号(根据节点在物理块链表停留的的时间，用length表示。)
{
  int k=0,maxs=-1,t=1;//l是函数返回值，maxs是当前length的最大值，t用来表示物理块链表节点的序号
    Page *p=malloc(sizeof(Page));
    p=a->next;//a是头结点，p是第一个数据节点
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

Page* Fifofunc(Page*h,Page*a,Page*b,int le,int len)//h是待处理页号链表的头结点，a是一个待处理页号节点，b是物理块链表头结点，len代表物理块的数目，le代表当前要插入物理块链表的序号。
{
    Page *p=(Page*)malloc(sizeof(Page));
   Page *px=(Page*)malloc(sizeof(Page));



   int fd=Pant(b,a);//判断物理块链表b中是否有待处理节点a的页号
   if(fd==1)
    b->order = b->order+1;//技数页面替换的总次数。

   if(le<=len)
   {
    b=AddNode(b,a,le);//如果物理块链表未满，将页号放入物理块中。
    b=Addone(b);
   }
   if(le>len)
    {

        while(fd)
        {

      printf("\n当前要处理的节点页号：");
      printf("%d\n",a->num);
        printf("物理块链表中各页面停留在物理块链表的时间: ");
       Prinl(b);

        int ka=Getnumf(b);//获得物理块链表中要被替换的节点序号
         p=b;
         for(int df=0;df<ka;df++)
            p=p->next;
         printf("物理块中被替换的节点页号： ");
         printf("%d\n",p->num);
        b=DeleteNode(b,ka);//将被替换的节点删除

        b=AddNode(b,a,ka);//将替换的节点插入物理块链表

            break;
       }

       b=Addone(b);
    }

  return b;

}

void FIFO(Page*a,Page*b,int kd)//a待处理页链表头结点，b是物理块链表头结点，kd是物理块链表长度
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

  printf("待处理链表长度: ");
  printf("%d\n",cal);
   p=Getnodev(a,i);
   while(p!=NULL)
   {


     b=Fifofunc(a,p,b,i,kd);//处理待处理链表中的页面节点
     i=i+1;
     Prin(b);
      if(i==cal+1)
       {
          float b11=(float)(b->order);
          float b22=(float)cal;
          rate=b11/b22;
          printf("\n缺页率： ");
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



//printf("创建一个页面 \n");
    b->order=0;//用来计数缺页次数
    b->num=NULL;
    b->length=0;
    b->next=NULL;

  FIFO(a,b,3);
  return 0;
}
