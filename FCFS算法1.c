#include<stdio.h>
#include<stdlib.h>
 typedef struct {
      char  name;   //进程标识符
      int comet;       //进程到来时间
      char state;       //进程状态
      struct node*next;
 }node;

 node* CreateNode(node *nenode,int i)
 {
   char a,c;
   int b;
   printf("创建节点,输入i:");
   scanf("%d",&i);
    fflush(stdin);
   printf("\n");
   nenode=(node*)malloc(sizeof(node));
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

    int i,j;

    node *r;
    L=(node*)malloc(sizeof(node));
    r=(node*)malloc(sizeof(node));
    printf("创建头节点：\n");
    L=CreateNode(L,j);
    L->next=NULL;
    r=L;
    for(i=0;i<k;i++)
      {
       node *p;
       p=(node*)malloc(sizeof(node));
       printf("创建数据节点:\n");
       p=CreateNode(p,j);
       p->next=NULL;
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

  while(p&&(j<i-1))
  {
    p=p->next;
    j=j+1;
  }
   q->next=p->next;
   p->next=q;
   return h;
}

void Prinf(node *h)
{
   node *s=(node*)malloc(sizeof(node));
   s=h->next;
   while(s!=NULL)
    {
      printf("%c\n",s->name);
      printf("%d\n",s->comet);
      printf("%c\n",s->state);
      s=s->next;
     }
}

node* fcfs(node*ready,node*run)
{
   node *p=(node*)malloc(sizeof(node));
   p=ready->next;
   int i=1;
   while(p)
   {
    run=AddNode(run,p,i);
    p=p->next;
    i=i+1;
   }
 return run;
}

int main()
{
  node *x,*y;
  int i;
  x=(node*)malloc(sizeof(node));
  y=(node*)malloc(sizeof(node));
  printf("输入运行队列头结点:\n");
  y=CreateNode(y,i);
  printf("创建就绪队列: \n");
  x=CreateList(x,3);

  printf("\n");
  y=fcfs(x,y);
  printf("就绪队列: \n");
  Prinf(x);
   printf("\n");
    printf("运行队列: \n");
  Prinf(y);

}
