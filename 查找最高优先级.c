#include<stdio.h>
#include<stdlib.h>
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

int main()
{
  node*l=(node*)malloc(sizeof(node));
  l=CreateList(l);
  int y,x;
  y=Maxpri(l,x);
  printf("%d\n",y);
  return 0;

}
