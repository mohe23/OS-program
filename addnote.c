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

node* AddNode(node*h,node*q)
{
  int i,j=0;
  printf("输入插入位置i: \n");
  scanf("%d",&i);
  node *p=(node*)malloc(sizeof(node));
  p->next=NULL;
  p=h;
  if(i==1)
  {
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

void Prinf(node *h)
{
   int i;
   node *s=(node*)malloc(sizeof(node));
   printf("创建头结点: \n");
   s=CreateNode(s,i);
   s=h->next;
   while(s!=NULL)
    {
      printf("%c\n",s->name);
      printf("%d\n",s->comet);
      printf("%c\n",s->state);
      s=s->next;
     }
}

int main()
{
  int i;


   node*l=(node*)malloc(sizeof(node));
   node*p=(node*)malloc(sizeof(node));
     printf("创建头结点: \n");
   l=CreateNode(l,i);
    printf("创建数据节点：\n");
   p=CreateNode(p,i);
   l=AddNode(l,p);
   Prinf(l);
   return 0;
}
