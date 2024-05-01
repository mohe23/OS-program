#include<stdio.h>
#include<stdlib.h>

typedef struct{
     int order; //节点在链表中的序号
     int  num;   //页号
     int length;//页号与下一次出现该页号的距离，如果此页号不再出现，置999
     struct Page*next;
}Page;

Page* CreateNode( Page*pag)//创建节点
 {
   pag=(Page*)malloc(sizeof(Page));

    pag->order=0;
    pag->num=NULL;
    pag->length=0;
    pag->next=NULL;
   return pag;
 }


 Page* CreateList(Page*L,int k)//创建一个长度为k的链表，带有头结点
 {

    int i,j,x[k];
    printf("输入链表节点的num值：\n");
     for(i=0;i<k;i++)
    {
        scanf("%d",&x[i]);
        fflush(stdin);

    }

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

Page*Gozero(Page*a,Page*b)//待处理的节点a页号正好与物理块链表b的某个节点的页号相同（即页号已经在物理块链表中），将节点b表示时间的length归0。
{                           //a是待处理节点，b是物理块链表头结点。
  Page*p=(Page*)malloc(sizeof(Page));
 p=b->next;
 while(p!=NULL)
 {
    if(p->num==a->num)
      {
        p->length=0;
        break;
      }

    else
    p=p->next;
 }

 return b;
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
   int fd=Pant(b,a);//fd=1,表示物理块链表b中没有待处理节点a的页号
   if(fd==1)
    b->order = b->order+1;//技数页面替换的总次数。

   if(le<=len)
   {
    b=AddNode(b,a,le);//如果物理块链表未满，将页号放入物理块中。
    b=Addone(b);
   }
   if(le>len)
    {

        if(fd==1)
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

       }
    else
       b=Gozero(a,b);

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
  int kw,kv;
   Page*a,*b;
  printf("物理块长度: ");
  scanf("%d",&kw);
   fflush(stdin);
     printf("\n");
  printf("待处理页面长度：");
  scanf("%d",&kv);
  fflush(stdin);
  printf("\n");

  a=CreateList(a,kv);//创建一个长度为kv的节点链表

  b=CreateNode(b);

  FIFO(a,b,3);
  return 0;
}
