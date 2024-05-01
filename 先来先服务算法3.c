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

int firstcome(node *l,int w)
{

  int i=1;
  int j=2;
  int xs=1;
 printf("待处理的就绪队列长度: ");
 scanf("%d",&w);
 printf("\n");
  node*p=(node*)malloc(sizeof(node));
  node*q=(node*)malloc(sizeof(node));
  printf("创建空节点: \n");
  p=CreateNode(p);
  printf("创建空节点: \n");
  q=CreateNode(q);
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

void Prinf(node *h)
{
   node *s=(node*)malloc(sizeof(node));
   node *t=(node*)malloc(sizeof(node));
   s=h;
   t=h->next;
   while(t!=NULL)
    {
      printf("%c\n",t->name);
      printf("%d\n",t->comet);
      printf("%c\n",t->state);
      t=t->next;
    }
}

void fcfs(node*ready,node*run,int k)
{


    for(int j=1;j<=k;j++)
    {
       node *s=(node*)malloc(sizeof(node));
        int z,leng;
        printf("下一次待处理的链表长度是这一次链表长度减1 \n");
     z=firstcome(ready,leng);//k是链表长度，当链表发生增删就会变化
     s=GetNode(ready,z);
     printf("输出s \n");
     printf("%c\n",s->name);
     printf("%d\n",s->comet);
     printf("%c\n",s->state);

     ready=DeleteNode(ready,z);
     printf("输出就绪队列:\n");
     Prinf(ready);
     run=AddNode(run,s,j);
     printf("输出运行队列:\n");
     Prinf(run);
    }
}


int main()
{
  node *x,*y;
  int k;
  printf("就绪链表长度: ");
  scanf("%d",&k);

  x=(node*)malloc(sizeof(node));
  y=(node*)malloc(sizeof(node));
  printf("输入运行队列头结点:\n");
  y=CreateNode(y);
  printf("创建就绪队列: \n");
  x=CreateList(x,k);
  fcfs(x,y,k);
  return 0;


}
