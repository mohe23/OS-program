#include<stdio.h>
#include<stdlib.h>
typedef struct{
     int order; //�ڵ��������е����
     int num;   //ҳ��
     int length;//ҳ������һ�γ��ָ�ҳ�ŵľ��룬�����ҳ�Ų��ٳ��֣���999
     struct Page*next;
}Page;

int Getnums(Page*a)//���������������Ҫ�������Ŀ����ڵ����
{
    int l=0,maxs=-1,t=1;//l�Ǻ�������ֵ��maxs�ǵ�ǰlength�����ֵ��t������ʾ���������ڵ�����
    Page *p=malloc(sizeof(Page));
    p=a->next;//a��ͷ��㣬p�ǵ�һ�����ݽڵ�
    while(p!=NULL)
    {
      if(p->length>maxs)
       {
         maxs=p->length;
         l=t;
       }
     p=p->next;
     t=t+1;
    }
  return l;
}

int main()
{
  Page*a=(Page*)malloc(sizeof(Page));

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
    c->length=9;
    c->next=d;

    d->order=2;
    d->num=1;
    d->length=2;
    d->next=e;

    e->order=3;
    e->num=2;
    e->length=6;
    e->next=f;

    f->order=8;
    f->num=0;
    f->length=8;
    f->next=NULL;

    int nd=Getnums(a);
    printf("%d\n",nd);
    return 0;
}
