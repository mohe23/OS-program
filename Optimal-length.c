#include<stdio.h>
#include<stdlib.h>
typedef struct{
     int order; //�ڵ��������е����
     int num;   //ҳ��
     int length;//ҳ������һ�γ��ָ�ҳ�ŵľ��룬�����ҳ�Ų��ٳ��֣���999
     struct Page*next;
}Page;

Page* CreateNode( Page*pag)//�����ڵ�
 {
   int i,a,b,c;
   printf("�����ڵ�,����i:");//����������0����ʾ�����սڵ㣻����������1����ʾ�������ݽڵ�
   scanf("%d",&i);
    fflush(stdin);
   printf("\n");
   pag=(Page*)malloc(sizeof(Page));
   if(i==0)
   {
    pag->order=0;
    pag->num=NULL;
    pag->length=0;
   }
   else{
        printf("order: ");
        scanf("%d",&a);
        fflush(stdin);
        printf("\n");
        printf("num: ");
        scanf("%d",&b);
        fflush(stdin);
        printf("\n");
        printf("length: ");
        scanf("%d",&c);
        fflush(stdin);
          printf("\n");

       pag->order=a;
       pag->num=b;
       pag->length=c;
      }
  pag->next=NULL;
   return pag;
 }

 Page* CreateList(Page*L,int k)//����һ������Ϊk����������ͷ���
 {

    int i,j;

    Page *r;
    L=(Page*)malloc(sizeof(Page));
    r=(Page*)malloc(sizeof(Page));
    printf("����ͷ�ڵ㣺\n");
    L=CreateNode(L);
    L->next=NULL;
    r=L;
    for(i=0;i<k;i++)
      {
       Page *p;
       p=(Page*)malloc(sizeof(Page));
       printf("�������ݽڵ�:\n");
       p=CreateNode(p);
       p->next=NULL;
       r->next=p;
       r=p;
       }
    return L;
}


Page* AddNode(Page*h,Page*q,int i)//�������е�ָ��λ�ò���ڵ㡣
{

  int j=0;

  Page *p=(Page*)malloc(sizeof(Page));
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

Page* DeleteNode(Page *h,int d)//ɾ��������ָ��λ�õĽڵ�
{
    int j=0;
    Page *p=malloc(sizeof(Page));
    Page *q=malloc(sizeof(Page));
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

int Pans(Page*h,Page*p)
{
  int labe=0;//���λ�������hΪͷ���������У��������л�����p֮����pҳ����ͬ�Ľڵ㣬����1������Ϊ0
  Page *q=(Page*)malloc(sizeof(Page));
  q=h->next;
  while(q!=NULL)
  {
      if(p->num==q->num)
      {
        labe=1;
        break;

      }

       else
        q=q->next;
  }
return labe;
}

Page*lengths(Page*h,Page*p)//���㵱ǰҳ�����ҳ����һ�γ��ֵľ���
{
   Page *q=(Page*)malloc(sizeof(Page)); //ָ�����ҳ��������p֮���ҳ��ڵ�
   q=h;  //һ��ʼָ��ͷ���
    for(int i=0;i<=p->order;i++)
      q=q->next;   //q��ָ����ҳ�������н���p֮���ҳ��ڵ�

   int k=Pans(h,p);
   printf("%d\n",k);

   if(k==1)
   {
    while(q!=NULL)
    {
      if((q->num)==(p->num))
        {
            p->length=q->order-p->order;
            break;//ע��
        }

        else
        q=q->next;
    }
   }
   else
     p->length=999;//��ǰҳ��֮�������в���������ҳ����ͬ�Ľڵ�

 return p;
}

int main()
{
  Page*a=(Page*)malloc(sizeof(Page));
  Page*b=(Page*)malloc(sizeof(Page));
  //printf("����һ��ҳ������");

  Page*c=(Page*)malloc(sizeof(Page));
  Page*d=(Page*)malloc(sizeof(Page));
  Page*e=(Page*)malloc(sizeof(Page));
  Page*f=(Page*)malloc(sizeof(Page));

    a->order=NULL;
    a->num=NULL;
    a->length=NULL;
    a->next=c;

    c->order=1;
    c->num=0;
    c->length=0;
    c->next=d;

    d->order=2;
    d->num=1;
    d->length=0;
    d->next=e;

    e->order=3;
    e->num=2;
    e->length=0;
    e->next=f;

    f->order=4;
    f->num=0;
    f->length=0;
    f->next=NULL;

//printf("����һ��ҳ�� \n");
    b->order=1;
    b->num=0;
    b->length=0;

  b=lengths(a,b);
  printf("order:\n");
  printf("%d\n",b->order);
   printf("num:\n");
  printf("%d\n",b->num);
   printf("length:\n");
  printf("%d\n",b->length);

  return 0;
}
