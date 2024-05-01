#include<stdio.h>
#include<stdlib.h>

typedef struct {
      char  name;   //进程名
      float ecomet;    //进程每一次占用CPU的到来时间
      float comet;       //进程原始到来时间
      float runt;       //进程总服务时间
      float lrunt;      //进程剩余服务时间
      float finisht;     //进程完成时间
      float zhout;       //周转时间
      float qzhout;     //带权周转时间
      struct node*next;
 }node;


node* CreateNode(node *nenode)
 {
   char a;
   int b,c,i;

   printf("创建节点,输入i:");//i=0，创建空节点；否则创建带数据的节点
   scanf("%d",&i);
    fflush(stdin);
   printf("\n");

   if(i==0)
   {
    nenode->name=NULL;
    nenode->comet=0;
    nenode->ecomet=0;
    nenode->runt=0;
    nenode->lrunt=0;
    nenode->finisht=0;
    nenode->zhout=0;
    nenode->qzhout=0;
   }
   else{
        printf("name: ");
        scanf("%c",&a);
        fflush(stdin);
        printf("\n");
        printf("comet: ");
        scanf("%f",&b);
        fflush(stdin);
        printf("\n");
        printf("runt: ");
        scanf("%f",&c);
        fflush(stdin);
          printf("\n");


         nenode->name=a;
         nenode->comet=b;
         nenode->ecomet=b;
         nenode->runt=c;
         nenode->lrunt=c;
         nenode->finisht=0;
         nenode->zhout=0;
         nenode->qzhout=0;

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

void Prinf(node *h)
{
   node *s=(node*)malloc(sizeof(node));
   node *t=(node*)malloc(sizeof(node));
   t=h->next;
   while(t!=NULL)
    {
      printf("%c\n",t->name);
      printf("%d\n",t->comet);
      printf("%d\n",t->finisht);
      printf("%d\n",t->zhout);
      printf("%d\n",t->qzhout);
      printf("\n");

      t=t->next;
    }
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

int main()
{
 node *l=malloc(sizeof(node));
 int k=3;
 l=CreateList(l,k);
 l=DeleteNode(l,1);
 Prinf(l);

}
