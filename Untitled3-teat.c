#include<stdio.h>
#include<stdlib.h>

typedef struct{
     int order; //节点在链表中的序号
     int num;   //页号
     int length;//页号与下一次出现该页号的距离，如果此页号不再出现，置999
     struct Page*next;
}Page;


int Pans(Page*h,Page*p)
{
  int labe=0;//标记位，如果以h为头结点的链表中，若链表中还存在p之后与p页号相同的节点，则置1，否者为0
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
    printf("%d  ",p->num);//输出当前节点的页号
    p=p->next;
  }
   printf("\n");
}

Page*lengths(Page*h,Page*p,Page*p1)//h是待处理页面链表，p是待处理链表中的页面节点，p1是物理块链表中的一个结点，计算与p1页号再次出现距离p的距离
{
   Page *q=(Page*)malloc(sizeof(Page)); //指向进程页面链表中p之后的页面节点
   q=h;  //一开始指向头结点
    for(int i=0;i<=p->order;i++)
      q=q->next;   //q就指向了页面链表中紧随p之后的页面节点

   int k=Pans(h,p1);//判断在链表h中,当前在物理块中的节点p1的页号是否再次出现，再次出现，k为1。


   if(k==1)
   {
    while(q!=NULL)
    {
      if((q->num)==(p1->num))
        {
            p1->length=q->order - p->order;
            break;//注意
        }

        else
        q=q->next;
    }
   }
   else
     p1->length=999;//当前页号之后链表中不存在与其页号相同的节点

 return p1;
}


Page* AddNode(Page*h,Page*q,int i)//在链表中的指定位置插入节点。这个程序还要考虑一下程序的健壮性就更好了，比如插入链表的位置大于链表的长度，如何处理
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

int Getnums(Page*a)//返回物理块链表中要被换出的块所在的序号
{
    int l=0,maxs=-1,t=1;//l是函数返回值，maxs是当前length的最大值，t用来表示物理块链表节点的序号
    Page *p=malloc(sizeof(Page));
    p=a->next;//a是头结点，p是第一个数据节点
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

int Pant(Page*a,Page*b)//a是物理块链表头结点，b是待处理节点。如果b的页号a表中所有节点的页号都不同，返回值1
{
   int k,k1=0,k2=0;
   Page*p=(Page*)malloc(sizeof(Page));
   p=a->next;
   while(p!=NULL)
   {
       if(p->num==b->num)
        k1=k1;//如果待处理节点页号与物理块链表中当前节点页号相同，k1加上0.
       else
        k1=k1+1;//如果待处理节点页号与物理块链表中当前节点页号不相同，k1加上1.

     p=p->next;
     k2=k2+1;//k2负责计数，与k1做对比，得出最后的返回值
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
