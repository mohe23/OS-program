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

int main()
{
  Page*a=(Page*)malloc(sizeof(Page));
  Page*b=(Page*)malloc(sizeof(Page));
  Page*c=(Page*)malloc(sizeof(Page));
  Page*d=(Page*)malloc(sizeof(Page));
  Page*e=(Page*)malloc(sizeof(Page));
  Page*a1=(Page*)malloc(sizeof(Page));
  Page*a2=(Page*)malloc(sizeof(Page));
   a->order=NULL;
    a->num=NULL;
    a->length=NULL;
    a->next=c;

    b->order=NULL;
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

  a1=a->next;
  a2=a1;
  a2->next=NULL;
  int s=1;
  int fd=1;
  while(s<4)
  {
      //printf("%d\n",a1->num);

    b=AddNode(b,a2,s);
     Prin(b);
    s=s+1;
    //printf("%d\n",s);
    a1=a1->next;//显然错误是a1的next指向出了问题。
    a2=a1;
    a2->next=NULL;//printf("%c\n",a1->num);

    if(a1==NULL)
        printf("122334 \n");

  }

 return 0;
}
