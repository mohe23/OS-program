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
   node *s=(node *)malloc(sizeof(node));
   s=h->next;
   while(s!=NULL)
    {
      printf("%c\n",s->name);
      printf("%d\n",s->comet);
      printf("%c\n",s->state);
      s=s->next;
     }
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
    o=h->next;
    return o;

}

int main()
{
 int j;

  node*d1=(node *)malloc(sizeof(node));
  node*d2=(node *)malloc(sizeof(node));
  d1=CreateList(d1);
  printf("输入要查找的结点序数: ");
  scanf("%d",&j);
  printf("\n");
  d2=GetNode(d1,j);
  printf("%c\n",d2->name);
  printf("%d\n",d2->comet);
  printf("%c\n",d2->state);
  return 0;
}
