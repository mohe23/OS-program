#include<stdio.h>
#include<stdlib.h>
typedef struct{
     int order; //节点在链表中的序号
     int num;   //页号
     int length;//页号与下一次出现该页号的距离，如果此页号不再出现，置999
     struct Page*next;
}Page;


void Prin(Page*h)
{
  Page *p=(Page*)malloc(sizeof(Page));
  p=h->next;
  while(p!=NULL)
  {
    printf("%d  ",p->num);//输出当前节点的页号
    p=p->next;
  }

}

Page* Optfunc(Page*h,Page*a,Page*b,int le,int len)//h是待处理页号链表的头结点，a是一个待处理页号节点，b是物理块链表头结点，len代表物理块的数目，le代表当前要插入物理块链表的序号。
{
   Page *p=(Page*)malloc(sizeof(Page));
  if(le<=len)
   b=AddNode(b,a,le);//如果物理块链表未满，将页号放入物理块中。

   else{
        p=b->next;
        while(p!=NULL)
        {
         p=lengths(h,p);//求出节点之后与其具有相同页号节点的距离，如果没有，置999
         p=p->next;
        }
        int ka=Getnums(b);//获得物理块链表中要被替换的节点序号
        b=DeleteNode(b,ka);//将被替换的节点删除
        b=AddNode(b,a,ka);//将替换的节点插入物理块链表
       }

  return b;

}
int main()
{
  Page*a=(Page*)malloc(sizeof(Page));
  Page*b=(Page*)malloc(sizeof(Page));
  //printf("创建一个页面链表");

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

//printf("创建一个页面 \n");
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
