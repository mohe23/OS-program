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
   o->comet=h->comet;
   o->state=h->state;
   o->next=NULL;

    return o;

}

int firstcome(node *l,int w)
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

      if((p->comet)>(q->comet))
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

void fcfs(node*ready,node*run,int k)
{


    for(int j=1;j<=k;j++)
    {
       node *s=(node*)malloc(sizeof(node));
        int z,leng;
        printf("��һ�δ����������������һ�������ȼ�1 \n");
     z=firstcome(ready,leng);//k�������ȣ�����������ɾ�ͻ�仯
     s=GetNode(ready,z);
     printf("���s \n");
     printf("%c\n",s->name);
     printf("%d\n",s->comet);
     printf("%c\n",s->state);

     ready=DeleteNode(ready,z);
     printf("�����������:\n");
     Prinf(ready);
     run=AddNode(run,s,j);
     printf("������ж���:\n");
     Prinf(run);
    }
}


int main()
{
  node *x,*y;
  int k;
  printf("����������: ");
  scanf("%d",&k);

  x=(node*)malloc(sizeof(node));
  y=(node*)malloc(sizeof(node));
  printf("�������ж���ͷ���:\n");
  y=CreateNode(y);
  printf("������������: \n");
  x=CreateList(x,k);
  fcfs(x,y,k);
  return 0;


}
