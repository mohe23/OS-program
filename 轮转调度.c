#include<stdio.h>
#include<stdlib.h>

typedef struct {
      char  name;   //������
      int ecomet;    //����ÿһ��ռ��CPU�ĵ���ʱ��
      int comet;       //����ԭʼ����ʱ��
      int runt;       //�����ܷ���ʱ��
      int lrunt;      //����ʣ�����ʱ��
      int finisht;     //�������ʱ��
      int zhout;       //��תʱ��
      int qzhout;     //��Ȩ��תʱ��
      struct node*next;
 }node;


node* CreateNode(node *nenode)
 {
   char a;
   int b,c,i;

   printf("�����ڵ�,����i:");//i=0�������սڵ㣻���򴴽������ݵĽڵ�
   scanf("%d",&i);
    fflush(stdin);
   printf("\n");

   if(i==0)
   {
    nenode->name=NULL;
    nenode->comet=NULL;
    nenode->ecomet=NULL;
    nenode->runt=NULL;
    nenode->lrunt=NULL;
    nenode->finisht=NULL;
    nenode->zhout=NULL;
    nenode->qzhout=NULL;
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
        printf("runt: ");
        scanf("%d",&c);
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
  int l,t,k,q,i;
  printf("�������г���k: ");
  scanf("%d",&k);
  printf("\n");
  q=1;
  t=0;

  node*ready=(node*)malloc(sizeof(node));
  node*r=(node*)malloc(sizeof(node));

  printf("������������: \n");
  ready=CreateList(ready,k);

  printf("�����սڵ� :\n");
  r=CreateNode(r);

  l=length(ready);

  while(l!=0)
   {
     node*p=(node*)malloc(sizeof(node));
     node*p1=(node*)malloc(sizeof(node));
     p=ready->next;
      p1=p;
     p->ecomet=t;

     if(p->lrunt>q)
      {

       p->lrunt=p->lrunt-q;
       p->finisht=p->ecomet+q;
       ready=DeleteNode(ready,1);
       ready=AddNode(ready,p1,l);

      }

      else{
            p->finisht=p->ecomet + p->lrunt;
            p->zhout=p->finisht - p->comet;
            p->qzhout=p->zhout/(p->runt/q+1);
            ready=DeleteNode(ready,1);
            int x=length(r);
            r=AddNode(r,p,x+1);
          }

      t= p1->finisht;
      l=length(ready);
   }

   int u=length(r);
    node*h=(node*)malloc(sizeof(node));
    h=r->next;


     printf("��תʱ��  ");
     for(i=0;i<u;i++)
   {

      printf("%5c",h->zhout);
      h=h->next;

    }

    return 0;



}




void Prinf(node *h)
{
   node *t=(node*)malloc(sizeof(node));
   t=h->next;
   while(t!=NULL)
    {

      printf("name  ");
      printf("%c\n",t->name);
      printf("comet  ");
      printf("%.2f\n",t->comet);
      printf("runt  ");
      printf("%d\n",t->runt);
      printf("lrunt  ");
      printf("%d\n",t->lrunt);
      printf("finisht  ");
      printf("%.2f\n",t->finisht);
       printf("zhout  ");
      printf("%.2f\n",t->zhout);
       printf("qzhout  ");
      printf("%.2f\n",t->qzhout);
      printf("\n");

      t=t->next;
    }
}

void Prn(node*neno)//���һ�����
{
     printf("name  ");
      printf("%c\n",neno->name);
      printf("comet  ");
      printf("%.2f\n",neno->comet);
      printf("runt  ");
      printf("%d\n",neno->runt);
       printf("lrunt  ");
      printf("%d\n",neno->lrunt);
      printf("finisht  ");
      printf("%.2f\n",neno->finisht);
       printf("zhout  ");
      printf("%.2f\n",neno->zhout);
       printf("qzhout  ");
      printf("%.2f\n",neno->qzhout);
      printf("\n");

}



