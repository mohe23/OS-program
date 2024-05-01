#include<stdio.h>
#include<stdlib.h>
 typedef struct {
      char  name;   //进程标识符
      int comet;       //进程到来时间
      char state;       //进程状态
      struct node*next;
 }node;

 node* CreateNode(node *nenode)
 {
   char a,c,i;
   int b;

   printf("创建节点,输入i:");
   scanf("%d",&i);
    fflush(stdin);
   printf("\n");

   if(i==0)
   {
    nenode->name=NULL;
    nenode->comet=NULL;
    nenode->state=NULL;
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
        printf("state: ");
        scanf("%c",&c);
        fflush(stdin);
          printf("\n");

         nenode->name=a;
        nenode->comet=b;
         nenode->state=c;
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
   o->state=h->state;
   o->next=NULL;

    return o;

}

int Mincomet(node *l,int w)
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
    printf("11223 \n");
    int i,j;
    int len=length(m);
    int le=len;
    printf("length  ");
    printf("%d",len);
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
   Prinf(n);
}

void Prinf(node *h)
{
   node *t=(node*)malloc(sizeof(node));
   t=h->next;
   while(t!=NULL)
    {

      printf("name  ");
      printf("%c",t->name);
      printf("\n");
      printf("comet  ");
      printf("%d",t->comet);
       printf("\n");
      printf("state  ");
      printf("%c",t->state);
      printf("\n");
      t=t->next;
    }
}

int main()
{
 node*l=(node*)malloc(sizeof(node));
 node*p=(node*)malloc(sizeof(node));
 int k;
 printf("创建链表长度: ");
 scanf("%d",&k);
 l=CreateList(l,k);
 Orderfunc(l,p);
  return 0;
}
