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
  printf("����Ҫ���ҵĽ������: ");
  scanf("%d",&j);
  printf("\n");
  d2=GetNode(d1,j);
  printf("%c\n",d2->name);
  printf("%d\n",d2->comet);
  printf("%c\n",d2->state);
  return 0;
}
