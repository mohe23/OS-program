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
   char a,c;
   int b;
   printf("name:");
   scanf("%c\n",&a);
   printf("comet:");
   scanf("%d\n",&b);
   printf("state:");
   scanf("%c\n",&c);
   nenode=(node*)malloc(sizeof(node));
   nenode->name=a;
   nenode->comet=b;
   nenode->state=c;
   return nenode;
 }
  node* CreateList(node *L,int k)
 {
    char m;
    int n,i;
    char v;
    node *r;
    L=(node*)malloc(sizeof(node));
    r=(node*)malloc(sizeof(node));
    L=CreateNode(L);
    L->next=NULL;
    r=L;
    for(i=0;i<k;i++)
    {
       node *p;
       p=(node*)malloc(sizeof(node));

       p=CreateNode(p);
       p->next=NULL;
       r->next=p;
       r=p;

       }
    return L;
     }

node* AddNode(node*h,int i)
{
  int j=0;

  node *p=malloc(sizeof(node));
  node *q=malloc(sizeof(node));
  p=h;

   q=CreateNode(q);

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

    node*l=malloc(sizeof(node));
    l=CreateList(l,3);
    l=AddNode(l,4);
    Prinf(l);
    return 0;
 }

