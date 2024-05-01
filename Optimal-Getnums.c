#include<stdio.h>
#include<stdlib.h>
typedef struct{
     int order; //节点在链表中的序号
     int num;   //页号
     int length;//页号与下一次出现该页号的距离，如果此页号不再出现，置999
     struct Page*next;
}Page;

int Getnums(Page*a)//返回物理块链表中要被换出的块所在的序号
{
    int l=0,maxs=-1,t=1;//l是函数返回值，maxs是当前length的最大值，t用来表示物理块链表节点的序号
    Page *p=malloc(sizeof(Page));
    p=a->next;//a是头结点，p是第一个数据节点
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
