#include<stdio.h>
#include<stdlib.h>
typedef struct{
     int order; //�ڵ��������е����
     int num;   //ҳ��
     int length;//ҳ������һ�γ��ָ�ҳ�ŵľ��룬�����ҳ�Ų��ٳ��֣���999
     struct Page*next;
}Page;


void Prin(Page*h)
{
  Page *p=(Page*)malloc(sizeof(Page));
  p=h->next;
  while(p!=NULL)
  {
    printf("%d  ",p->num);//�����ǰ�ڵ��ҳ��
    p=p->next;
  }

}

Page* Optfunc(Page*h,Page*a,Page*b,int le,int len)//h�Ǵ�����ҳ�������ͷ��㣬a��һ��������ҳ�Žڵ㣬b�����������ͷ��㣬len������������Ŀ��le����ǰҪ����������������š�
{
   Page *p=(Page*)malloc(sizeof(Page));
  if(le<=len)
   b=AddNode(b,a,le);//������������δ������ҳ�ŷ���������С�

   else{
        p=b->next;
        while(p!=NULL)
        {
         p=lengths(h,p);//����ڵ�֮�����������ͬҳ�Žڵ�ľ��룬���û�У���999
         p=p->next;
        }
        int ka=Getnums(b);//��������������Ҫ���滻�Ľڵ����
        b=DeleteNode(b,ka);//�����滻�Ľڵ�ɾ��
        b=AddNode(b,a,ka);//���滻�Ľڵ�������������
       }

  return b;

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
  Page*c1=(Page*)malloc(sizeof(Page));
  Page*d1=(Page*)malloc(sizeof(Page));
  Page*e1=(Page*)malloc(sizeof(Page));
  Page*f1=(Page*)malloc(sizeof(Page));
  Page*c2=(Page*)malloc(sizeof(Page));
  Page*d2=(Page*)malloc(sizeof(Page));
  Page*e2=(Page*)malloc(sizeof(Page));
  Page*f2=(Page*)malloc(sizeof(Page));
  Page*c3=(Page*)malloc(sizeof(Page));
  Page*d3=(Page*)malloc(sizeof(Page));
  Page*e3=(Page*)malloc(sizeof(Page));
  Page*f3=(Page*)malloc(sizeof(Page));
  Page*c4=(Page*)malloc(sizeof(Page));
  Page*d4=(Page*)malloc(sizeof(Page));
  Page*e4=(Page*)malloc(sizeof(Page));
  Page*f4=(Page*)malloc(sizeof(Page));

    a->order=NULL;
    a->num=NULL;
    a->length=NULL;
    a->next=c;

    c->order=1;
    c->num=7;
    c->length=0;
    c->next=d;

    d->order=2;
    d->num=0;
    d->length=0;
    d->next=e;

    e->order=3;
    e->num=1;
    e->length=0;
    e->next=f;

    f->order=4;
    f->num=2;
    f->length=0;
    f->next=c1;

    c1->order=5;
    c1->num=0;
    c1->length=0;
    c1->next=d1;

    d1->order=6;
    d1->num=3;
    d1->length=0;
    d1->next=e1;

    e1->order=7;
    e1->num=0;
    e1->length=0;
    e1->next=f1;

    f1->order=8;
    f1->num=4;
    f1->length=0;
    f1->next=c2;

     c2->order=9;
    c2->num=2;
    c2->length=0;
    c2->next=d2;

    d2->order=10;
    d2->num=3;
    d2->length=0;
    d2->next=e2;

    e2->order=11;
    e2->num=0;
    e2->length=0;
    e2->next=f2;

    f2->order=12;
    f2->num=3;
    f2->length=0;
    f2->next=c3;

    c3->order=13;
    c3->num=2;
    c3->length=0;
    c3->next=d3;

    d3->order=14;
    d3->num=1;
    d3->length=0;
    d3->next=e3;

    e3->order=15;
    e3->num=2;
    e3->length=0;
    e3->next=f3;

    f3->order=16;
    f3->num=0;
    f3->length=0;
    f3->next=c4;

    c4->order=17;
    c4->num=1;
    c4->length=0;
    c4->next=d4;

    d4->order=18;
    d4->num=7;
    d4->length=0;
    d4->next=e4;

    e4->order=19;
    e4->num=0;
    e4->length=0;
    e4->next=f4;

    f4->order=20;
    f4->num=1;
    f4->length=0;
    f4->next=NULL;

//printf("����һ��ҳ�� \n");
    b->order=NULL;
    b->num=NULL;
    b->length=NULL;
    b->next=NULL;
    int lp=1;
     Page*ef=(Page*)malloc(sizeof(Page));
       ef=c;

       while(ef!=NULL)
       {
         //printf("%d\n",ef->num);
         //ef=ef->next;
        b=Optfunc(a,ef,b,lp,3);
         lp=lp+1;
        ef=ef->next;
         Prin(b);
         printf("\n");
       }

    return 0;

}
