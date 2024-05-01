#include<stdio.h>
#include<stdlib.h>

typedef struct {
      char  name;   //进程名
      float ecomet;    //进程每一次占用CPU的到来时间
      float comet;       //进程原始到来时间
      int  runt;       //进程总服务时间
      int  lrunt;      //进程剩余服务时间
      float finisht;     //进程完成时间
      float zhout;       //周转时间
      float qzhout;     //带权周转时间
      struct node*next;
 }node;


node* CreateNode(node *nenode)
 {
   char a;
   int c,i;
    float b;
   printf("创建节点,输入i:");//i=0，创建空节点；否则创建带数据的节点
   scanf("%d",&i);
    fflush(stdin);
   printf("\n");

   if(i==0)
   {
    nenode->name=NULL;
    nenode->comet=0;
    nenode->runt=0;

   }
   else{
        printf("name: ");
        scanf("%c",&(nenode->name));
        fflush(stdin);
        printf("\n");
        printf("comet: ");
        scanf("%f",&(nenode->comet));
        fflush(stdin);
        printf("\n");
        printf("runt: ");
        scanf("%d",&(nenode->runt));
        fflush(stdin);
        printf("\n");

      }
           nenode->ecomet=nenode->comet;
           nenode->lrunt=nenode->runt;
           nenode->finisht=0;
           nenode->zhout=0;
           nenode->qzhout=0;
           nenode->next=NULL;
   return nenode;
 }

  node* CreateList(node *L,int k)
 {

    int i;
    node *r;
    r=(node*)malloc(sizeof(node));
    r=L;
    for(i=0;i<k;i++)
      {
       node *p;
       p=(node*)malloc(sizeof(node));
       printf("创建数据节点:\n");
       p=CreateNode(p);
       r->next=p;
       r=p;
       }
    return L;
}

node* AddNode(node*h,node*q,int i)
{

  int j=0;

  node *p=(node*)malloc(sizeof(node));

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

node* DeleteNode(node *h,int d)//删除节点
{
    int j=0;
    node *p=malloc(sizeof(node));
    node *q=malloc(sizeof(node));
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

node*GetNode(node*l,int length)
{
   int j=0;
   node*h=(node *)malloc(sizeof(node));
   node*o=(node *)malloc(sizeof(node));

   h=l;
    while((h->next)&&(j<length-1))
      {
       h=h->next;
       j=j+1;
      }
    h=h->next;
   o->name=h->name;
   o->comet=h->comet;
   o->ecomet=h->ecomet;
   o->runt=h->runt;
   o->lrunt=h->lrunt;
   o->finisht=h->finisht;
   o->zhout=h->zhout;
   o->qzhout=h->qzhout;
   o->next=NULL;

    return o;

}

int length(node*l)//求一个链表的长度
{
    int i=0;
    node*p=(node*)malloc(sizeof(node));
    p=l->next;
    while(p)
    {
        i=i+1;
        p=p->next;
    }
  return i;
}




void Printe(node *l)//输出链表中各个节点的信息
{
  node *t1=(node*)malloc(sizeof(node));
  node *t2=(node*)malloc(sizeof(node));
  node *t3=(node*)malloc(sizeof(node));
  node *t4=(node*)malloc(sizeof(node));
  node *t5=(node*)malloc(sizeof(node));
  node *t6=(node*)malloc(sizeof(node));
   t1=l->next;
   t2=l->next;
   t3=l->next;
   t4=l->next;
   t5=l->next;
   t6=l->next;
   printf("name     ");
    while(t1!=NULL)
    {
        printf("%c      ",t1->name);
         t1=t1->next;
    }
    printf("\n");

     printf("comet    ");
     while(t2!=NULL)
    {
        printf("%.2f   ",t2->comet);
        t2=t2->next;
    }
    printf("\n");

    printf("runt     ");
     while(t3!=NULL)
    {
        printf("%d      ",t3->runt);
        t3=t3->next;
    }
    printf("\n");

   printf("finisht  ");
     while(t4!=NULL)
    {
        printf("%.2f   ",t4->finisht);
        t4=t4->next;
    }
    printf("\n");

     printf("zhout    ");
     while(t5!=NULL)
    {
        printf("%.2f   ",t5->zhout);
        t5=t5->next;
    }
    printf("\n");

     printf("qzhout   ");
     while(t6!=NULL)
    {
        printf("%.2f   ",t6->qzhout);
        t6=t6->next;
    }
    printf("\n");

}



 node *equ(node*m,node*n)//结点n=结点m
 {
     n->name=m->name;
     n->comet=m->comet;
     n->runt=m->runt;
     n->lrunt=m->lrunt;
     n->finisht=m->finisht;
     n->zhout=m->zhout;
     n->qzhout=m->qzhout;
     n->next=NULL;
     return n;
 }


 int Mincomet(node *l,int w)//返回一个进程链表中到来时间最小的节点位置
{

  int i=1;
  int j=2;
  int xs=1;

  node*p=(node*)malloc(sizeof(node));
  node*q=(node*)malloc(sizeof(node));

  p=l->next;
  q=p->next;

    for(int d=1;d<w;d++)
    {

      if((p->comet)>(q->comet))
          {
           p=q;
           i=i+1;
           xs=j;
          }
       else
           {
            xs=i;
           }

       q=q->next;
       j=j+1;
    }


  return xs;
}

void Orderfunc(node *m,node*n)//将节点按照到来时间由低到高挂在链表上
{

    int i,j;
    int len=length(m);
    int le=len;
     printf("\n");
   for(j=0;j<len;j++)
   {
     node*h=(node*)malloc(sizeof(node));
     i=Mincomet(m,le);
     le=le-1;
     h=GetNode(m,i);
     m=DeleteNode(m,i);
     n=AddNode(n,h,j+1);
    }
   Printe(n);
}


void rrf(node*ready,node*run,int q)//轮转算法
{
    int t=0;

    int l;
    l=length(ready);
    while(l!=0)//根据ready链表中的长度作为循环条件
   {
     node*p=(node*)malloc(sizeof(node));
     node*p1=(node*)malloc(sizeof(node));
     p=ready->next;

      p->ecomet=t;  //每一个链表表首进程开始运行时间
     if(p->lrunt>q)//待运行时间>时间片
        {
          p->lrunt=p->lrunt-q;
          p->finisht=p->ecomet+q;
          p1=equ(p,p1);
          ready=DeleteNode(ready,1);
          ready=AddNode(ready,p1,l);
        }

      else{   //待运行时间<时间片

            p->finisht=p->ecomet + p->lrunt;
            p->zhout=p->finisht - p->comet;
            p->qzhout=(p->zhout)/(p->runt);//带权周转时间.
            p1=equ(p,p1);
            ready=DeleteNode(ready,1);
            int x=length(run);

            run=AddNode(run,p1,x+1);
           }

      t= p1->finisht; //每一个进程的结束时间作为下一个进程的开始时间
      l=length(ready);
   }
 node*lx=(node*)malloc(sizeof(node));
 Orderfunc(run,lx);//输出链表中所有节点的数据。

}


int main()
{
  int k,de;
  printf("输入时间片长度: ");
  scanf("%d",&de);
   printf("\n");
  printf("就绪队列长度k: ");
  scanf("%d",&k);
  printf("\n");

  node*ready=(node*)malloc(sizeof(node));
  node*run=(node*)malloc(sizeof(node));

  printf("创建就绪队列: \n");
  ready=CreateList(ready,k);

  printf("创建一个空链表 :\n");
  run=CreateNode(run);



  rrf(ready,run,de);


    return 0;


}





