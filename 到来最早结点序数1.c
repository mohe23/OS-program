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

   int e,b;
   char a,c;
   printf("创建节点,输入e:");
   scanf("%d",&e);
    fflush(stdin);
   printf("\n");

   if(e==0)
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

node* CreateList(node *L)
 {

    int z,k;
    printf("创建链表的长度: ");
    scanf("%d",&k);
     fflush(stdin);
     printf("\n");
    node *r;

    r=(node*)malloc(sizeof(node));
    printf("创空节点: \n");
    r=CreateNode(r);
    printf("创建头节点：\n");
    L=CreateNode(L);
    r=L;
    for(z=0;z<k;z++)
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

void Prinf(node *h)
{
   node *s=malloc(sizeof(node));
   s=h->next;
   while(s!=NULL)
    {
      printf("%c\n",s->name);
      printf("%d\n",s->comet);
      printf("%c\n",s->state);
      s=s->next;
     }
}

int firstcome(node *l,int w)
{

  int i=1;
  int j=2;
  int xs=1;

  node*p=(node*)malloc(sizeof(node));
  node*q=(node*)malloc(sizeof(node));
  printf("创建空节点: \n");
  p=CreateNode(p);
  printf("创建空节点: \n");
  q=CreateNode(q);
  p=l->next;
  Prinf(p);
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

int main()
{
   int u;
   int g=0;
   node *v=(node*)malloc(sizeof(node));
   v=CreateList(v);
    printf("输入待处理链表长度: ");
   scanf("%d",&u);
   printf("\n");
   g=firstcome(v,u);
   printf("输出最先到达的结点序数:");
   printf("%d\n",g);
   return 0;
}
