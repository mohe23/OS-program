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

   int i,b;
   char a,c;


   printf("�����ڵ�,����i:");
   scanf("%d",&i);
    fflush(stdin);
   printf("\n");

   if(i==0)
   {
    nenode->name=NULL;
    nenode->comet=0;
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

int firstcome(node *l)
{
  int k;
  int i=1;
  int j=2;
  int num=0;
 printf("���������������: ");
 scanf("%d\n",&k);

  node*p=(node*)malloc(sizeof(node));
  node*q=(node*)malloc(sizeof(node));

  printf("�����սڵ�: \n");
  p=CreateNode(p);
  printf("�����սڵ�: \n");
  q=CreateNode(q);
  p=l->next;
  Prinf(p);
  q=p->next;
  if(k>2)
  {
    int d=1;
    while(d<k)
    {
      if((p->comet)>(q->comet))
          {
           p=q;
           num=j;
          }
       else  {num=i;}

       q=q->next;
       j=j+1;
    }
  }

  else if(k==2)
  {
      if((p->comet)>(q->comet))
         num=j;
    else   num=i;
  }

  else {num=1;}

  return num;
}

int main()
{
   int i;
   node *l=(node*)malloc(sizeof(node));
   l=CreateList(l);
   i=firstcome(l);
   printf("������ȵ���Ľ������:");
   printf("%d",&i);
   return 0;
}
