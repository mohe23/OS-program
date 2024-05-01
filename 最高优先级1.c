#include<stdio.h>
#include<stdlib.h>
#define delta 2
typedef struct {
      char  name;      //���̱�ʶ��
      int time;       //���̻���Ҫ��ʱ�䣬��ֵ��������������Ҫ��ʱ�䡣
      char state;      //����״̬
      int  pri;       //���ȼ�
      struct node*next;
 }node;

 node* CreateNode(node *nenode)
 {
   char a,c,i;
   int b,d;

   printf("�����ڵ�,����i:");
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

int Maxpri(node *l,int w)
{

  int i=1;
  int j=2;
  int xs=1;
 printf("������ľ������г���: ");
 scanf("%d",&w);
 printf("\n");
  node*p=(node*)malloc(sizeof(node));
  node*q=(node*)malloc(sizeof(node));
  printf("�����սڵ�: \n");
  p=CreateNode(p);
  printf("�����սڵ�: \n");
  q=CreateNode(q);
  p=l->next;
  q=p->next;

    for(int d=1;d<w;d++)
    {

      if((p->pri)<(q->pri))
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

node* AddNode(node*h,node*q,int i)
{

  int j=0;

  node *p=(node*)malloc(sizeof(node));
  printf("�����սڵ�: \n");
  p=h;
if(!(p->next))
  {

     q->next=p->next;
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

node* DeleteNode(node *h,int d)//ɾ���ڵ�
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
    h=h->next;
   o->name=h->name;
   o->time=h->time;
   o->state=h->state;
   o->pri=h->pri;
   o->next=NULL;

    return o;
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

void Prinf(node *h)
{
   node *s=(node*)malloc(sizeof(node));
   node *t=(node*)malloc(sizeof(node));
   s=h;
   t=h->next;
   while(t!=NULL)
    {
      printf("%c\n",t->name);
      printf("%d\n",t->time);
      printf("%c\n",t->state);
      printf("%d\n",t->pri);
        t=t->next;
    }
}

void priority(node*x,node*y)
{
  int i,g,lenx,leny;
  lenx=length(x);
  while(lenx!=0)
  {

     leny=length(y);
     printf("%d\n",leny);
     node*p=(node*)malloc(sizeof(node));
     i=Maxpri(x,g);
     p=GetNode(x,i);
     x=DeleteNode(x,i);
     y=AddNode(y,p,leny+1);
   if(p->time>delta)
     {
      p->time=p->time-delta;
      p->pri=p->pri-1;
      lenx=length(x)+1;
      x=AddNode(x,p,lenx);
      leny=length(y);
      y=DeleteNode(y,leny);
     }
     printf("�����������: \n");
     Prinf(x);
     printf("������ж���: \n");
     Prinf(y);
     lenx=length(x);
  }

}

int main()
{
    node*m=(node*)malloc(sizeof(node));
    node*n=(node*)malloc(sizeof(node));
    printf("�������ж��У�ͷ���: \n");
    n=CreateNode(n);
    printf("������������: \n");
    m=CreateList(m);
    priority(m,n);
    return 0;

}

