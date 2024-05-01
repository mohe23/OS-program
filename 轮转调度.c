#include<stdio.h>
#include<stdlib.h>

typedef struct {
      char  name;   //进程名
      int ecomet;    //进程每一次占用CPU的到来时间
      int comet;       //进程原始到来时间
      int runt;       //进程总服务时间
      int lrunt;      //进程剩余服务时间
      int finisht;     //进程完成时间
      int zhout;       //周转时间
      int qzhout;     //带权周转时间
      struct node*next;
 }node;


node* CreateNode(node *nenode)
 {
   char a;
   int b,c,i;

   printf("创建节点,输入i:");//i=0，创建空节点；否则创建带数据的节点
   scanf("%d",&i);
    fflush(stdin);
   printf("\n");

   if(i==0)
   {
    nenode->name=NULL;
    nenode->comet=NULL;
    nenode->ecomet=NULL;
    nenode->runt=NULL;
    nenode->lrunt=NULL;
    nenode->finisht=NULL;
    nenode->zhout=NULL;
    nenode->qzhout=NULL;
   }
   else{
        printf("name: ");
        scanf("%c",&a);
        fflush(stdin);
        printf("\n");
        printf("comet: ");
        scanf("%d",&b);
        fflush(stdin);
        printf("\n");
        printf("runt: ");
        scanf("%d",&c);
        fflush(stdin);
          printf("\n");


         nenode->name=a;
         nenode->comet=b;
         nenode->ecomet=b;
         nenode->runt=c;
         nenode->lrunt=c;
         nenode->finisht=0;
         nenode->zhout=0;
         nenode->qzhout=0;

      }
   nenode->next=NULL;
   return nenode;
 }

  node* CreateList(node *L,int k)
 {

    int i;

    node *r;

    r=(node*)malloc(sizeof(node));
    printf("创空节点: \n");
    r=CreateNode(r);
    printf("创建头节点：\n");
    L=CreateNode(L);
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

int length(node*l)
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


int main()
{
  int l,t,k,q,i;
  printf("就绪队列长度k: ");
  scanf("%d",&k);
  printf("\n");
  q=1;
  t=0;

  node*ready=(node*)malloc(sizeof(node));
  node*r=(node*)malloc(sizeof(node));

  printf("创建就绪队列: \n");
  ready=CreateList(ready,k);

  printf("创建空节点 :\n");
  r=CreateNode(r);

  l=length(ready);

  while(l!=0)
   {
     node*p=(node*)malloc(sizeof(node));
     node*p1=(node*)malloc(sizeof(node));
     p=ready->next;
      p1=p;
     p->ecomet=t;

     if(p->lrunt>q)
      {

       p->lrunt=p->lrunt-q;
       p->finisht=p->ecomet+q;
       ready=DeleteNode(ready,1);
       ready=AddNode(ready,p1,l);

      }

      else{
            p->finisht=p->ecomet + p->lrunt;
            p->zhout=p->finisht - p->comet;
            p->qzhout=p->zhout/(p->runt/q+1);
            ready=DeleteNode(ready,1);
            int x=length(r);
            r=AddNode(r,p,x+1);
          }

      t= p1->finisht;
      l=length(ready);
   }

   int u=length(r);
    node*h=(node*)malloc(sizeof(node));
    h=r->next;


     printf("周转时间  ");
     for(i=0;i<u;i++)
   {

      printf("%5c",h->zhout);
      h=h->next;

    }

    return 0;



}




void Prinf(node *h)
{
   node *t=(node*)malloc(sizeof(node));
   t=h->next;
   while(t!=NULL)
    {

      printf("name  ");
      printf("%c\n",t->name);
      printf("comet  ");
      printf("%.2f\n",t->comet);
      printf("runt  ");
      printf("%d\n",t->runt);
      printf("lrunt  ");
      printf("%d\n",t->lrunt);
      printf("finisht  ");
      printf("%.2f\n",t->finisht);
       printf("zhout  ");
      printf("%.2f\n",t->zhout);
       printf("qzhout  ");
      printf("%.2f\n",t->qzhout);
      printf("\n");

      t=t->next;
    }
}

void Prn(node*neno)//输出一个结点
{
     printf("name  ");
      printf("%c\n",neno->name);
      printf("comet  ");
      printf("%.2f\n",neno->comet);
      printf("runt  ");
      printf("%d\n",neno->runt);
       printf("lrunt  ");
      printf("%d\n",neno->lrunt);
      printf("finisht  ");
      printf("%.2f\n",neno->finisht);
       printf("zhout  ");
      printf("%.2f\n",neno->zhout);
       printf("qzhout  ");
      printf("%.2f\n",neno->qzhout);
      printf("\n");

}



