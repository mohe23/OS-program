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
   printf("\n");
}

Page* AddNode(Page*h,Page*q,int i)//在链表中的指定位置插入节点。
{

  int j=0;

  Page *p=(Page*)malloc(sizeof(Page));

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

Page*Getnodev(Page*h,int iv)
{

   Page*p=(Page*)malloc(sizeof(Page));
   Page*q=(Page*)malloc(sizeof(Page));
   p=h;
   for(int i=0;i<iv;i++)
    p=p->next;

    q=p;
    q->next=NULL;
   return q;
}

int main()
{
      int s;
  Page*a=(Page*)malloc(sizeof(Page));
  Page*b=(Page*)malloc(sizeof(Page));
  Page*c=(Page*)malloc(sizeof(Page));
  Page*d=(Page*)malloc(sizeof(Page));
  Page*e=(Page*)malloc(sizeof(Page));
  Page*a1=(Page*)malloc(sizeof(Page));
  Page*a2=(Page*)malloc(sizeof(Page));
   a->order=0;
    a->num=NULL;
    a->length=NULL;
    a->next=c;

    b->order=0;
    b->num=NULL;
    b->length=NULL;
    b->next=NULL;

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
    e->next=NULL;




       a1=Getnodev(a,1);
       printf("%d ",a1->order);
       printf("%d ",a1->num);
       printf("%d ",a1->length);
        fflush(stdin);
       //printf("%d",s);


       a1=Getnodev(a,2);
       printf("%d ",a1->order);
       printf("%d ",a1->num);
       printf("%d ",a1->length);
        fflush(stdin);
       //printf("%d",s);


        a1=Getnodev(a,3);
       printf("%d ",a1->order);
       printf("%d ",a1->num);
       printf("%d ",a1->length);
        fflush(stdin);
       //printf("%d",s);


   return 0;
}
