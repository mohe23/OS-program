#include<stdio.h>
#include<stdlib.h>
typedef struct{
     int order; //节点在链表中的序号
     int num;   //页号
     int length;//页号与下一次出现该页号的距离，如果此页号不再出现，置999
     struct Page*next;
}Page;

Page* CreateNode( Page*pag)//创建节点
 {
   int i,a,b,c;
   printf("创建节点,输入i:");//如果输入的是0，表示创建空节点；如果输入的是1，表示创建数据节点
   scanf("%d",&i);
    fflush(stdin);
   printf("\n");
   pag=(Page*)malloc(sizeof(Page));
   if(i==0)
   {
    pag->order=0;
    pag->num=NULL;
    pag->length=0;
   }
   else{
        printf("order: ");
        scanf("%d",&a);
        fflush(stdin);
        printf("\n");
        printf("num: ");
        scanf("%d",&b);
        fflush(stdin);
        printf("\n");
        printf("length: ");
        scanf("%d",&c);
        fflush(stdin);
          printf("\n");

       pag->order=a;
       pag->num=b;
       pag->length=c;
      }
  pag->next=NULL;
   return pag;
 }

 Page* CreateList(Page*L,int k)//创建一个长度为k的链表，带有头结点
 {

    int i,j;

    Page *r;
    L=(Page*)malloc(sizeof(Page));
    r=(Page*)malloc(sizeof(Page));
    printf("创建头节点：\n");
    L=CreateNode(L);
    L->next=NULL;
    r=L;
    for(i=0;i<k;i++)
      {
       Page *p;
       p=(Page*)malloc(sizeof(Page));
       printf("创建数据节点:\n");
       p=CreateNode(p);
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
  printf("创建空节点: \n");
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

Page*lengths(Page*h,Page*p)//计算当前页面与该页面下一次出现的距离
{
   Page *q=(Page*)malloc(sizeof(Page)); //指向进程页面链表中p之后的页面节点
   q=h;  //一开始指向头结点
    for(int i=0;i<=p->order;i++)
      q=q->next;   //q就指向了页面链表中紧随p之后的页面节点

   int k=Pans(h,p);
   printf("%d\n",k);

   if(k==1)
   {
    while(q!=NULL)
    {
      if((q->num)==(p->num))
        {
            p->length=q->order-p->order;
            break;//注意
        }

        else
        q=q->next;
    }
   }
   else
     p->length=999;//当前页号之后链表中不存在与其页号相同的节点

 return p;
}

int main()
{
  Page*a=(Page*)malloc(sizeof(Page));
  Page*b=(Page*)malloc(sizeof(Page));
  //printf("创建一个页面链表");

  Page*c=(Page*)malloc(sizeof(Page));
  Page*d=(Page*)malloc(sizeof(Page));
  Page*e=(Page*)malloc(sizeof(Page));
  Page*f=(Page*)malloc(sizeof(Page));

    a->order=NULL;
    a->num=NULL;
    a->length=NULL;
    a->next=c;

    c->order=1;
    c->num=0;
    c->length=0;
    c->next=d;

    d->order=2;
    d->num=1;
    d->length=0;
    d->next=e;

    e->order=3;
    e->num=2;
    e->length=0;
    e->next=f;

    f->order=4;
    f->num=0;
    f->length=0;
    f->next=NULL;

//printf("创建一个页面 \n");
    b->order=1;
    b->num=0;
    b->length=0;

  b=lengths(a,b);
  printf("order:\n");
  printf("%d\n",b->order);
   printf("num:\n");
  printf("%d\n",b->num);
   printf("length:\n");
  printf("%d\n",b->length);

  return 0;
}
