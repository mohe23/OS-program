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

   int e,b;
   char a,c;
   printf("�����ڵ�,����e:");
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
    printf("��������ĳ���: ");
    scanf("%d",&k);
     fflush(stdin);
     printf("\n");
    node *r;

    r=(node*)malloc(sizeof(node));
    printf("���սڵ�: \n");
    r=CreateNode(r);
    printf("����ͷ�ڵ㣺\n");
    L=CreateNode(L);
    r=L;
    for(z=0;z<k;z++)
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

int firstcome(node *l,int w)
{

  int i=1;
  int j=2;
  int xs=1;

  node*p=(node*)malloc(sizeof(node));
  node*q=(node*)malloc(sizeof(node));
  printf("�����սڵ�: \n");
  p=CreateNode(p);
  printf("�����սڵ�: \n");
  q=CreateNode(q);
  p=l->next;
  Prinf(p);
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

int main()
{
   int u;
   int g=0;
   node *v=(node*)malloc(sizeof(node));
   v=CreateList(v);
    printf("���������������: ");
   scanf("%d",&u);
   printf("\n");
   g=firstcome(v,u);
   printf("������ȵ���Ľ������:");
   printf("%d\n",g);
   return 0;
}
