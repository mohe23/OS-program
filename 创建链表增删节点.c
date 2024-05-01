#include<stdio.h>
#include<stdlib.h>
 typedef struct {
      char  name;   //进程标识符
      int comet;       //进程到来时间
      char state;       //进程状态
      struct node*next;
 }node;

 node* CreateNode(node *nenode,char a,int b,char c)//创建节点
 {
   nenode=(node*)malloc(sizeof(node));
   nenode->name=a;
   nenode->comet=b;
   nenode->state=c;
   return nenode;
 }

 node* CreateList(node *L,int k)//创建链表
 {
    char m;
    int n,i;
    char v;
    node *r;
    L=(node*)malloc(sizeof(node));
    r=(node*)malloc(sizeof(node));
    L=CreateNode(L,NULL,NULL,NULL);
    L->next=NULL;
    r=L;
    for(i=0;i<k;i++)
    {
       node *p;
       p=(node*)malloc(sizeof(node));
       printf("name: ");
       scanf("%c",&m);
       fflush(stdin);
       printf("\n");
       printf("comet: ");
       scanf("%d",&n);
       fflush(stdin);
       printf("\n");
       printf("state: ");
       scanf("%c",&v);
       fflush(stdin);
       printf("\n");
       p=CreateNode(p,m,n,v);
       p->next=NULL;
       r->next=p;
       r=p;

       }
    return L;
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

node* AddNode(node*h,int i)
{
  int j=0;
  char a,c;
  int b;
  node *p=malloc(sizeof(node));
  node *q=malloc(sizeof(node));
  p=h;
   scanf("%c\n",&a);
   scanf("%d\n",&b);
   scanf("%c",&c);
   q=CreateNode(q,a,b,c);

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




int main()
{
    node *h=malloc(sizeof(node));
    h=CreateList(h,3);
    Prinf(h);
    h=AddNode(h,2);
    Prinf(h);
    h=DeleteNode(h,4);
    Prinf(h);
    return 0;
}
