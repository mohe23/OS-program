#include<stdio.h>
#include<stdlib.h>
 typedef struct {
      char  name;   //���̱�ʶ��
      int comet;       //���̵���ʱ��
      char state;       //����״̬
      struct node*next;
 }node;


 node* CreateNode(node *nenode)
 {
   char a,c,i;
   int b;

   printf("�����ڵ�,����i:");
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

  node* CreateList(node *L)
 {

    int i,k;
    printf("��������ĳ���: ");
    scanf("%d",&k);
     fflush(stdin);
    node *r;

    r=(node*)malloc(sizeof(node));
    printf("���սڵ�: \n");
    r=CreateNode(r);
    printf("����ͷ�ڵ㣺\n");
    L=CreateNode(L);
    r=L;
    for(i=0;i<k;i++)
      {
       node *p;
       p=(node*)malloc(sizeof(node));
       printf("�������ݽڵ�:\n");
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
  printf("�����սڵ�: \n");
  p=CreateNode(p);
  p=h;
  if((i==1)&&(p->next))
  {
      q->next=p->next;
      p->next=q;
  }
  else if((i==1)&&(!(p->next)))
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

node* fcfs(node*ready,node*run,int k)
{
   int i=1;
   node *h=(node*)malloc(sizeof(node));
   printf("�����սڵ�: \n");
   h=CreateNode(h);
   h=ready->next;
   if(i<(k+1))
   {
    run=AddNode(run,h,i);
    h=h->next;
    i=i+1;
   }
 return run;
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

int main()
{
  node *x,*y;
  int k=2;
  x=(node*)malloc(sizeof(node));
  y=(node*)malloc(sizeof(node));
  printf("�������ж���ͷ���:\n");
  y=CreateNode(y);
  printf("������������: \n");
  x=CreateList(x);
  Prinf(x);
  y=fcfs(x,y,k);
  printf("���ж���: \n");
  Prinf(y);

}
