#include<stdio.h>
#include<stdlib.h>

typedef struct {
      char  name;   //������
      float ecomet;    //����ÿһ��ռ��CPU�ĵ���ʱ��
      float comet;       //����ԭʼ����ʱ��
      float runt;       //�����ܷ���ʱ��
      float lrunt;      //����ʣ�����ʱ��
      float finisht;     //�������ʱ��
      float zhout;       //��תʱ��
      float qzhout;     //��Ȩ��תʱ��
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

int main()
{
 node *l=malloc(sizeof(node));
 int k=3;
 l=CreateList(l,k);
 l=DeleteNode(l,1);
 Prinf(l);

}
