#include<stdio.h>
#include<stdlib.h>
#define delta 2
typedef struct {
      char  name;      //进程标识符
      int time;       //进程还需要的时间，初值就是整个进程需要的时间。
      char state;      //进程状态
      int  pri;       //优先级
      struct node*next;
 }node;

 node* CreateNode(node *nenode)
 {
   char a,c,i;
   int b,d;

   printf("创建节点,输入i:");
   scanf("%d",&i);
    fflush(stdin);
   printf("\n");

   if(i==0)
   {
    nenode->name=NULL;
    nenode->time=NULL;
    nenode->state=NULL;
    nenode->pri=NULL;
   }
   else{
        printf("name: ");
        scanf("%c",&a);
        fflush(stdin);
        printf("\n");
        printf("time: ");
        scanf("%d",&b);
        fflush(stdin);
        printf("\n");
        printf("state: ");
        scanf("%c",&c);
        fflush(stdin);
          printf("\n");
         printf("pri: ");
        scanf("%d",&d);
        fflush(stdin);
          printf("\n");
         nenode->name=a;
        nenode->time=b;
         nenode->state=c;
         nenode->pri=d;
      }
   nenode->next=NULL;
   return nenode;
 }

  node* CreateList(node *L)
 {

    int i,k;
    printf("创建链表的长度: ");
    scanf("%d",&k);
     fflush(stdin);
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

int main()
{
  node*l=(node*)malloc(sizeof(node));
  l=CreateList(l);
  int j=length(l);
  printf("%d\n",j);
  return 0;

}
