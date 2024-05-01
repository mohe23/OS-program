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


int Mincomet(node*l)
{
   int i=2;
   int j;
   node*h=(node*)malloc(sizeof(node));
   node*s=(node*)malloc(sizeof(node));
   h=l->next;
   s=h->next;
   while(s!=NULL)
   {
    if(h->comet<=s->comet)
       j=1;
    else j=i;
    s=s->next;
    i=i+1;
   }
   return j;
}

int main()
{
 node*l=(node*)malloc(sizeof(node));
 int k;
 printf("创建链表长度: ");
 scanf("%d",&k);
 l=CreateList(l,k);
 int v=Mincomet(l);
 printf("%d\n",v);
}
