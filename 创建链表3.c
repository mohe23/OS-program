#include<stdio.h>
#include<stdlib.h>
 typedef struct {
      char  name;   //进程标识符
      int comet;       //进程到来时间
      char state;       //进程状态
      struct node*next;
 }node;

 node* CreateNode(node *nenode,char a,int b,char c)
 {
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

int main()
{
  node*f,*h;
  h=(node*)malloc(sizeof(node));
   f=CreateList(f,3);
   h=f->next;
   while(h!=NULL)
    {
     printf("%c\n",h->name);
    printf("%d\n",h->comet);
    printf("%c\n",h->state);
    h=h->next;
     }
}
